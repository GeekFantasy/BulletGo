#include "bullet_counter.h"
#include "bullet_counter_gui.h"
//#include "weather_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "network.h"
#include "common.h"
#include "ArduinoJson.h"
#include <esp32-hal-timer.h>
#include <map>

#define BULLET_COUNTER_APP_NAME "Bullet Counter"
#define WEATHER_NOW_API "https://www.yiketianqi.com/free/day?appid=%s&appsecret=%s&unescape=1&city=%s"
#define WEATHER_NOW_API_UPDATE "https://yiketianqi.com/api?unescape=1&version=v6&appid=%s&appsecret=%s&city=%s"
#define WEATHER_DALIY_API "https://www.yiketianqi.com/free/week?unescape=1&appid=%s&appsecret=%s&city=%s"
#define TIME_API "http://api.m.taobao.com/rest/api3.do?api=mtop.common.gettimestamp"
#define WEATHER_PAGE_SIZE 2
#define UPDATE_WEATHER 0x01       // 更新天气
#define UPDATE_DALIY_WEATHER 0x02 // 更新每天天气
#define UPDATE_TIME 0x04          // 更新时间

// 天气的持久化配置
#define BULLET_COUNTER_CONFIG_PATH "/bulletcounter.cfg"
//LV_IMAGE_DECLARE(app_bullet_counter);

struct WT_Config
{
    String tianqi_appid;                 // tianqiapid 的 appid
    String tianqi_appsecret;             // tianqiapid 的 appsecret
    String tianqi_addr;                  // tianqiapid 的地址（填中文）
    unsigned long weatherUpdataInterval; // 天气更新的时间间隔(s)
    unsigned long timeUpdataInterval;    // 日期时钟更新的时间间隔(s)
};

static void write_config(WT_Config *cfg)
{
    char tmp[16];
    // 将配置数据保存在文件中（持久化）
    String w_data;
    w_data = w_data + cfg->tianqi_appid + "\n";
    w_data = w_data + cfg->tianqi_appsecret + "\n";
    w_data = w_data + cfg->tianqi_addr + "\n";
    memset(tmp, 0, 16);
    snprintf(tmp, 16, "%lu\n", cfg->weatherUpdataInterval);
    w_data += tmp;
    memset(tmp, 0, 16);
    snprintf(tmp, 16, "%lu\n", cfg->timeUpdataInterval);
    w_data += tmp;
    g_flashCfg.writeFile(BULLET_COUNTER_CONFIG_PATH, w_data.c_str());
}

static void read_config(WT_Config *cfg)
{
    // 如果有需要持久化配置文件 可以调用此函数将数据存在flash中
    // 配置文件名最好以APP名为开头 以".cfg"结尾，以免多个APP读取混乱
    char info[128] = {0};
    uint16_t size = g_flashCfg.readFile(BULLET_COUNTER_CONFIG_PATH, (uint8_t *)info);
    info[size] = 0;
    if (size == 0)
    {
        // 默认值
        cfg->tianqi_addr = "北京";
        cfg->weatherUpdataInterval = 900000; // 天气更新的时间间隔900000(900s)
        cfg->timeUpdataInterval = 900000;    // 日期时钟更新的时间间隔900000(900s)
        write_config(cfg);
    }
    else
    {
        // 解析数据
        char *param[5] = {0};
        analyseParam(info, 5, param);
        cfg->tianqi_appid = param[0];
        cfg->tianqi_appsecret = param[1];
        cfg->tianqi_addr = param[2];
        cfg->weatherUpdataInterval = atol(param[3]);
        cfg->timeUpdataInterval = atol(param[4]);
    }
}

struct WeatherAppRunData
{
    unsigned long preWeatherMillis; // 上一回更新天气时的毫秒数
    unsigned long preTimeMillis;    // 更新时间计数器
    long long preNetTimestamp;      // 上一次的网络时间戳
    long long errorNetTimestamp;    // 网络到显示过程中的时间误差
    long long preLocalTimestamp;    // 上一次的本地机器时间戳
    unsigned int coactusUpdateFlag; // 强制更新标志
    int clock_page;
    unsigned int update_type; // 更新类型的标志位

    BaseType_t xReturned_task_task_update; // 更新数据的异步任务
    TaskHandle_t xHandle_task_task_update; // 更新数据的异步任务

    ESP32Time g_rtc; // 用于时间解码
    //Weather wea;     // 保存天气状况
};

static WT_Config cfg_data;
static WeatherAppRunData *run_data = NULL;

enum wea_event_Id
{
    UPDATE_NOW,
    UPDATE_NTP,
    UPDATE_DAILY
};

//std::map<String, int> weatherMap = {{"qing", 0}, {"yin", 1}, {"yu", 2}, {"yun", 3}, {"bingbao", 4}, {"wu", 5}, {"shachen", 6}, {"lei", 7}, {"xue", 8}};

static void task_update(void *parameter); // 异步更新任务


static int bullet_counter_init(AppController *sys)
{
    tft->setSwapBytes(true);
    bullet_counter_gui_init();
    // // 获取配置信息
    // read_config(&cfg_data);

    // // 初始化运行时参数
    // run_data = (WeatherAppRunData *)calloc(1, sizeof(WeatherAppRunData));
    // //memset((char *)&run_data->wea, 0, sizeof(Weather));
    // run_data->preNetTimestamp = 1577808000000; // 上一次的网络时间戳 初始化为2020-01-01 00:00:00
    // run_data->errorNetTimestamp = 2;
    // run_data->preLocalTimestamp = GET_SYS_MILLIS(); // 上一次的本地机器时间戳
    // run_data->clock_page = 0;
    // run_data->preWeatherMillis = 0;
    // run_data->preTimeMillis = 0;
    // // 强制更新
    // run_data->coactusUpdateFlag = 0x01;
    // run_data->update_type = 0x00; // 表示什么也不需要更新

    // 目前更新数据的任务栈大小5000够用，4000不够用
    // 为了后期迭代新功能 当前设置为8000
    // run_data->xReturned_task_task_update = xTaskCreate(
    //     task_update,                          /*任务函数*/
    //     "Task_update",                        /*带任务名称的字符串*/
    //     8000,                                /*堆栈大小，单位为字节*/
    //     NULL,                                 /*作为任务输入传递的参数*/
    //     1,                                    /*任务的优先级*/
    //     &run_data->xHandle_task_task_update); /*任务句柄*/

    return 0;
}

static void bullet_counter_process(AppController *sys,
                            const ImuAction *act_info)
{
    display_bullet_status();
    // lv_scr_load_anim_t anim_type = LV_SCR_LOAD_ANIM_NONE;

    // if (RETURN == act_info->active)
    // {
    //     sys->app_exit();
    //     return;
    // }
    // else if (GO_FORWORD == act_info->active)
    // {
    //     // 间接强制更新
    //     run_data->coactusUpdateFlag = 0x01;
    //     delay(500); // 以防间接强制更新后，生产很多请求 使显示卡顿
    // }
    // else if (TURN_RIGHT == act_info->active)
    // {
    //     anim_type = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
    //     run_data->clock_page = (run_data->clock_page + 1) % WEATHER_PAGE_SIZE;
    // }
    // else if (TURN_LEFT == act_info->active)
    // {
    //     anim_type = LV_SCR_LOAD_ANIM_MOVE_LEFT;
    //     // 以下等效与 clock_page = (clock_page + WEATHER_PAGE_SIZE - 1) % WEATHER_PAGE_SIZE;
    //     // +3为了不让数据溢出成负数，而导致取模逻辑错误
    //     run_data->clock_page = (run_data->clock_page + WEATHER_PAGE_SIZE - 1) % WEATHER_PAGE_SIZE;
    // }

    // // 界面刷新
    // if (run_data->clock_page == 0)
    // {
    //     //display_weather(run_data->wea, anim_type);
    //     if (0x01 == run_data->coactusUpdateFlag || doDelayMillisTime(cfg_data.weatherUpdataInterval, &run_data->preWeatherMillis, false))
    //     {
    //         sys->send_to(BULLET_COUNTER_APP_NAME, CTRL_NAME,
    //                      APP_MESSAGE_WIFI_CONN, (void *)UPDATE_NOW, NULL);
    //         sys->send_to(BULLET_COUNTER_APP_NAME, CTRL_NAME,
    //                      APP_MESSAGE_WIFI_CONN, (void *)UPDATE_DAILY, NULL);
    //     }

    //     if (0x01 == run_data->coactusUpdateFlag || doDelayMillisTime(cfg_data.timeUpdataInterval, &run_data->preTimeMillis, false))
    //     {
    //         // 尝试同步网络上的时钟
    //         sys->send_to(BULLET_COUNTER_APP_NAME, CTRL_NAME,
    //                      APP_MESSAGE_WIFI_CONN, (void *)UPDATE_NTP, NULL);
    //     }
    //     else if (GET_SYS_MILLIS() - run_data->preLocalTimestamp > 400)
    //     {
    //         //UpdateTime_RTC(get_timestamp());
    //     }
    //     run_data->coactusUpdateFlag = 0x00; // 取消强制更新标志
    //     //display_space();
    //     delay(30);
    // }
    // else if (run_data->clock_page == 1)
    // {
    //     // 仅在切换界面时获取一次未来天气
    //     //display_curve(run_data->wea.daily_max, run_data->wea.daily_min, anim_type);
    //     delay(300);
    // }
}

static void bullet_counter_background_task(AppController *sys,
                                    const ImuAction *act_info)
{
    // 本函数为后台任务，主控制器会间隔一分钟调用此函数
    // 本函数尽量只调用"常驻数据",其他变量可能会因为生命周期的缘故已经释放
}

static int bullet_counter_exit_callback(void *param)
{
    //weather_gui_del();

    // // 查杀异步任务
    // if (run_data->xReturned_task_task_update == pdPASS)
    // {
    //     vTaskDelete(run_data->xHandle_task_task_update);
    // }

    // // 释放运行数据
    // if (NULL != run_data)
    // {
    //     free(run_data);
    //     run_data = NULL;
    // }
    return 0;
}

// static void task_update(void *parameter)
// {
//     // 数据更新任务
//     while (1)
//     {
//         if (run_data->update_type & UPDATE_WEATHER)
//         {
//             get_weather();
//             if (run_data->clock_page == 0)
//             {
//                 display_weather(run_data->wea, LV_SCR_LOAD_ANIM_NONE);
//             }
//             run_data->update_type &= (~UPDATE_WEATHER);
//         }
//         if (run_data->update_type & UPDATE_TIME)
//         {
//             long long timestamp = get_timestamp(TIME_API); // nowapi时间API
//             if (run_data->clock_page == 0)
//             {
//                 UpdateTime_RTC(timestamp);
//             }
//             run_data->update_type &= (~UPDATE_TIME);
//         }
//         if (run_data->update_type & UPDATE_DALIY_WEATHER)
//         {
//             get_daliyWeather(run_data->wea.daily_max, run_data->wea.daily_min);
//             if (run_data->clock_page == 1)
//             {
//                 display_curve(run_data->wea.daily_max, run_data->wea.daily_min, LV_SCR_LOAD_ANIM_NONE);
//             }
//             run_data->update_type &= (~UPDATE_DALIY_WEATHER);
//         }
//         vTaskDelay(2000 / portTICK_PERIOD_MS);
//     }
// }

static void bullet_counter_message_handle(const char *from, const char *to,
                                   APP_MESSAGE_TYPE type, void *message,
                                   void *ext_info)
{
    switch (type)
    {
    case APP_MESSAGE_WIFI_CONN:
    {
        Serial.println(F("----->weather_event_notification"));
        int event_id = (int)message;
        switch (event_id)
        {
        case UPDATE_NOW:
        {
            Serial.print(F("weather update.\n"));
            run_data->update_type |= UPDATE_WEATHER;

            //get_weather();
            if (run_data->clock_page == 0)
            {
                //display_weather(run_data->wea, LV_SCR_LOAD_ANIM_NONE);
            }
        };
        break;
        case UPDATE_NTP:
        {
            Serial.print(F("ntp update.\n"));
            run_data->update_type |= UPDATE_TIME;

            //long long timestamp = get_timestamp(TIME_API); // nowapi时间API
            if (run_data->clock_page == 0)
            {
                //UpdateTime_RTC(timestamp);
            }
        };
        break;
        case UPDATE_DAILY:
        {
            Serial.print(F("daliy update.\n"));
            run_data->update_type |= UPDATE_DALIY_WEATHER;

            //get_daliyWeather(run_data->wea.daily_max, run_data->wea.daily_min);
            if (run_data->clock_page == 1)
            {
                //display_curve(run_data->wea.daily_max, run_data->wea.daily_min, LV_SCR_LOAD_ANIM_NONE);
            }
        };
        break;
        default:
            break;
        }
    }
    break;
    case APP_MESSAGE_GET_PARAM:
    {
        char *param_key = (char *)message;
        if (!strcmp(param_key, "tianqi_appid"))
        {
            snprintf((char *)ext_info, 32, "%s", cfg_data.tianqi_appid.c_str());
        }
        else if (!strcmp(param_key, "tianqi_appsecret"))
        {
            snprintf((char *)ext_info, 32, "%s", cfg_data.tianqi_appsecret.c_str());
        }
        else if (!strcmp(param_key, "tianqi_addr"))
        {
            snprintf((char *)ext_info, 32, "%s", cfg_data.tianqi_addr.c_str());
        }
        else if (!strcmp(param_key, "weatherUpdataInterval"))
        {
            snprintf((char *)ext_info, 32, "%lu", cfg_data.weatherUpdataInterval);
        }
        else if (!strcmp(param_key, "timeUpdataInterval"))
        {
            snprintf((char *)ext_info, 32, "%lu", cfg_data.timeUpdataInterval);
        }
        else
        {
            snprintf((char *)ext_info, 32, "%s", "NULL");
        }
    }
    break;
    case APP_MESSAGE_SET_PARAM:
    {
        char *param_key = (char *)message;
        char *param_val = (char *)ext_info;
        if (!strcmp(param_key, "tianqi_appid"))
        {
            cfg_data.tianqi_appid = param_val;
        }
        else if (!strcmp(param_key, "tianqi_appsecret"))
        {
            cfg_data.tianqi_appsecret = param_val;
        }
        else if (!strcmp(param_key, "tianqi_addr"))
        {
            cfg_data.tianqi_addr = param_val;
        }
        else if (!strcmp(param_key, "weatherUpdataInterval"))
        {
            cfg_data.weatherUpdataInterval = atol(param_val);
        }
        else if (!strcmp(param_key, "timeUpdataInterval"))
        {
            cfg_data.timeUpdataInterval = atol(param_val);
        }
    }
    break;
    case APP_MESSAGE_READ_CFG:
    {
        read_config(&cfg_data);
    }
    break;
    case APP_MESSAGE_WRITE_CFG:
    {
        write_config(&cfg_data);
    }
    break;
    default:
        break;
    }
}

APP_OBJ bullet_counter_app = {BULLET_COUNTER_APP_NAME, &app_bullet_counter, "GeekFantasy",
                              bullet_counter_init, bullet_counter_process, bullet_counter_background_task,
                              bullet_counter_exit_callback, bullet_counter_message_handle};
