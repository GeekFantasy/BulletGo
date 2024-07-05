#include "motion_state_server.h"
#include "motion_state_server_gui.h"
#include "motion_state_api.h"
#include "sys/app_controller.h"
#include "app/app_conf.h"
#include "network.h"
#include "common.h"

#define SERVER_REFLUSH_INTERVAL 5000UL // 配置界面重新刷新时间(5s)
#define DNS_PORT 53                    // DNS端口

// DNSServer dnsServer;

struct ServerAppRunData
{
    boolean web_start;                    // 标志是否开启web server服务，0为关闭 1为开启
    boolean req_sent;                     // 标志是否发送wifi请求服务，0为关闭 1为开启
    unsigned long serverReflushPreMillis; // 上一回更新的时间
};

static ServerAppRunData *run_data = NULL;


static int motion_server_init(AppController *sys)
{
    motion_server_gui_init();
    // 初始化运行时参数
    run_data = (ServerAppRunData *)malloc(sizeof(ServerAppRunData));
    run_data->web_start = 0;
    run_data->req_sent = 0;
    run_data->serverReflushPreMillis = 0;
    return 0;
}

static void motion_server_process(AppController *sys,
                           const ImuAction *action,
                           int btn_event)
{
    if (ButtonEvent::BTN_DOWN == btn_event)
    {
        run_data->web_start = 0;
        run_data->req_sent = 0;
        stop_motion_api();
        sys->app_exit();
        return;
    }

    if (0 == run_data->web_start && 0 == run_data->req_sent)
    {
        // 预显示
        display_motion_server_setting(
            "Motion Server",
            "Domain: holocubic",
            "Wait...", "Wait...",
            LV_SCR_LOAD_ANIM_NONE);
        // 如果web服务没有开启 且 ap开启的请求没有发送 message这边没有作用（填0）
        // sys->send_to(MOTION_STATE_SERVER_APP_NAME, CTRL_NAME,
        //              APP_MESSAGE_WIFI_CONN, NULL, NULL);
         sys->send_to(MOTION_STATE_SERVER_APP_NAME, CTRL_NAME,
                     APP_MESSAGE_WIFI_AP, NULL, NULL);

        run_data->req_sent = 1; // 标志为 ap开启请求已发送
    }
    else if (1 == run_data->web_start)
    {
        uint32_t prior_tick = GET_SYS_MILLIS();
        motion_api_handle(); // 一定需要放在循环里扫描
        Serial.printf("Handle Client time: %d.\n", GET_SYS_MILLIS() - prior_tick);
        delay(20);
        
        if (doDelayMillisTime(SERVER_REFLUSH_INTERVAL, &run_data->serverReflushPreMillis, false) == true)
        {
            // 发送wifi维持的心跳
            sys->send_to(MOTION_STATE_SERVER_APP_NAME, CTRL_NAME, APP_MESSAGE_WIFI_ALIVE, NULL, NULL);

            display_motion_server_setting("Motion Server Start","Domain: holocubic",
                WiFi.localIP().toString().c_str(), WiFi.softAPIP().toString().c_str(), LV_SCR_LOAD_ANIM_NONE);
        }
    }
}

static void motion_server_background_task(AppController *sys,
                                   const ImuAction *act_info)
{
    // 本函数为后台任务，主控制器会间隔一分钟调用此函数
    // 本函数尽量只调用"常驻数据",其他变量可能会因为生命周期的缘故已经释放
}

static int motion_server_exit_callback(void *param)
{
    motion_server_gui_del();

    // 释放运行数据
    if (NULL != run_data)
    {
        free(run_data);
        run_data = NULL;
    }
    return 0;
}

static void motion_server_message_handle(const char *from, const char *to,
                                  APP_MESSAGE_TYPE type, void *message,
                                  void *ext_info)
{
    switch (type)
    {
    case APP_MESSAGE_WIFI_CONN:
    case APP_MESSAGE_WIFI_AP:
    {
        Serial.print(F("APP_MESSAGE_WIFI_CONN enable\n"));
        display_motion_server_setting(
            "Motion Server Start",
            "Domain: holocubic",
            WiFi.localIP().toString().c_str(),
            WiFi.softAPIP().toString().c_str(),
            LV_SCR_LOAD_ANIM_NONE);
        start_motion_api();
        run_data->web_start = 1;
    }
    break;
    case APP_MESSAGE_WIFI_ALIVE:
    {
        // wifi心跳维持的响应 可以不做任何处理
    }
    break;
    default:
        break;
    }
}

APP_OBJ motion_state_server_app = {MOTION_STATE_SERVER_APP_NAME, &app_motion_state_server, "",
                      motion_server_init, motion_server_process, motion_server_background_task,
                      motion_server_exit_callback, motion_server_message_handle};
