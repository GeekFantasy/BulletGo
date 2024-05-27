
// 参考代码 https://github.com/G6EJD/ESP32-8266-File-Upload

#include "network.h"
#include "common.h"
#include "motion_state_server.h"
#include "motion_state_web_setting.h"
#include "app/app_conf.h"
#include "FS.h"
#include "HardwareSerial.h"
#include <esp32-hal.h>

static boolean sd_present = true;
static String webpage = "";
static String motion_data = "";
static String webpage_header = "";
static String webpage_footer = "";

static void Send_HTML(const String &content)
{
    motion_server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
    motion_server.sendHeader("Pragma", "no-cache");
    motion_server.sendHeader("Expires", "-1");
    motion_server.setContentLength(CONTENT_LENGTH_UNKNOWN);
    // Empty content inhibits Content-length header so we have to close the socket ourselves.
    motion_server.send(200, "text/html", "");
    motion_server.sendContent(webpage_header);

    motion_server.sendContent(content);
    motion_server.sendContent(webpage_footer);

    motion_server.sendContent("");
    motion_server.client().stop(); // Stop is needed because no content length was sent
}

static String file_size(int bytes)
{
    String fsize = "";
    if (bytes < 1024)
        fsize = String(bytes) + " B";
    else if (bytes < (1024 * 1024))
        fsize = String(bytes / 1024.0, 3) + " KB";
    else if (bytes < (1024 * 1024 * 1024))
        fsize = String(bytes / 1024.0 / 1024.0, 3) + " MB";
    else
        fsize = String(bytes / 1024.0 / 1024.0 / 1024.0, 3) + " GB";
    return fsize;
}

#define SETING_CSS ".input {display: block;margin-top: 10px;}"                                          \
                   ".input span {width: 300px;float: left;float: left;height: 36px;line-height: 36px;}" \
                   ".input input {height: 30px;width: 200px;}"                                          \
                   ".input .radio {height: 30px;width: 50px;}"                                          \
                   ".btn {width: 120px;height: 35px;background-color: #000000;border: 0px;color: #ffffff;margin-top: 15px;margin-left: auto;}" // margin-left: 100px;

#define SYS_SETTING "<form method=\"GET\" action=\"saveSysConf\">"                                                                                                                                                                                                      \
                    "<label class=\"input\"><span>WiFi SSID_0(2.4G)</span><input type=\"text\"name=\"ssid_0\"value=\"%s\"></label>"                                                                                                                                     \
                    "<label class=\"input\"><span>WiFi Passwd_0</span><input type=\"text\"name=\"password_0\"value=\"%s\"></label>"                                                                                                                                     \
                    "<label class=\"input\"><span>功耗控制（0低发热 1性能优先）</span><input type=\"text\"name=\"power_mode\"value=\"%s\"></label>"                                                                                                        \
                    "<label class=\"input\"><span>屏幕亮度 (值为1~100)</span><input type=\"text\"name=\"backLight\"value=\"%s\"></label>"                                                                                                                         \
                    "<label class=\"input\"><span>屏幕方向 (0~5可选)</span><input type=\"text\"name=\"rotation\"value=\"%s\"></label>"                                                                                                                            \
                    "<label class=\"input\"><span>操作方向（0~15可选）</span><input type=\"text\"name=\"mpu_order\"value=\"%s\"></label>"                                                                                                                       \
                    "<label class=\"input\"><span>MPU6050自动校准</span><input class=\"radio\" type=\"radio\" value=\"0\" name=\"auto_calibration_mpu\" %s>关闭<input class=\"radio\" type=\"radio\" value=\"1\" name=\"auto_calibration_mpu\" %s>开启</label>" \
                    "<label class=\"input\"><span>开机自启的APP名字</span><input type=\"text\"name=\"auto_start_app\"value=\"%s\"></label>"                                                                                                                      \
                    "</label><input class=\"btn\" type=\"submit\" name=\"submit\" value=\"保存\"></form>"


void init_motion_page_header()
{
    webpage_header = F("<!DOCTYPE html><html>");
    webpage_header += F("<head>");
    webpage_header += F("<title>HoloCubic WebServer</title>"); // NOTE: 1em = 16px
    webpage_header += F("<meta http-equiv='Content-Type' name='viewport' content='user-scalable=yes,initial-scale=1.0,width=device-width; text/html; charset=utf-8' />");
    webpage_header += F("<style>");
    webpage_header += F(SETING_CSS);
    webpage_header += F("body{max-width:65%;margin:0 auto;font-family:arial;font-size:105%;text-align:center;color:blue;background-color:#dbdadb;}");
    webpage_header += F("ul{list-style-type:none;margin:0.1em;padding:0;border-radius:0.375em;overflow:hidden;background-color:#878588;font-size:1em;}");
    webpage_header += F("li{float:left;border-radius:0.375em;border-right:0.06em solid #bbb;}last-child {border-right:none;font-size:85%}");
    webpage_header += F("li a{display: block;border-radius:0.375em;padding:0.44em 0.44em;text-decoration:none;font-size:85%}");
    webpage_header += F("li a:hover{background-color:#EAE3EA;border-radius:0.375em;font-size:85%}");
    webpage_header += F("section {font-size:0.88em;}");
    webpage_header += F("h1{color:white;border-radius:0.5em;font-size:1em;padding:0.2em 0.2em;background:#4c4c4d;}");
    webpage_header += F("h2{color:orange;font-size:1.0em;}");
    webpage_header += F("h3{font-size:0.8em;}");
    webpage_header += F("table{font-family:arial,sans-serif;font-size:0.9em;border-collapse:collapse;width:85%;}");
    webpage_header += F("th,td {border:0.06em solid #dddddd;text-align:left;padding:0.3em;border-bottom:0.06em solid #dddddd;}");
    webpage_header += F("tr:nth-child(odd) {background-color:#eeeeee;}");
    webpage_header += F(".rcorners_n {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:20%;color:white;font-size:75%;}");
    webpage_header += F(".rcorners_m {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:50%;color:white;font-size:75%;}");
    webpage_header += F(".rcorners_w {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:70%;color:white;font-size:75%;}");
    webpage_header += F(".column{float:left;width:50%;height:45%;}");
    webpage_header += F(".row:after{content:'';display:table;clear:both;}");
    webpage_header += F("*{box-sizing:border-box;}");
    webpage_header += F("footer{background-color:#b1b1b1; text-align:center;padding:0.3em 0.3em;border-radius:0.375em;font-size:60%;}");
    webpage_header += F("button{border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:20%;color:white;font-size:130%;}");
    webpage_header += F(".buttons {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:15%;color:white;font-size:80%;}");
    webpage_header += F(".buttonsm{border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:9%; color:white;font-size:70%;}");
    webpage_header += F(".buttonm {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:15%;color:white;font-size:70%;}");
    webpage_header += F(".buttonw {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:40%;color:white;font-size:70%;}");
    webpage_header += F("a{font-size:75%;}");
    webpage_header += F("p{font-size:75%;}");

    webpage_header += F("</style></head><body>");

    webpage_header += F("<h1>HoloCubic_AIO ");
    webpage_header += F(BULLETGO_VERSION "</h1>");
    webpage_header += F("<ul>");
    webpage_header += F("<li><a href='/'>Home</a></li>"); // Lower Menu bar command entries
    webpage_header += F("<li><a href='/download'>Download</a></li>");
    webpage_header += F("<li><a href='/upload'>Upload</a></li>");
    webpage_header += F("<li><a href='/delete'>Delete</a></li>");

    webpage_header += F("<li><a href='/sys_setting'>系统设置</a></li>");

    webpage_header += F("<li><a href='/rgb_setting'>RGB设置</a></li>");
#if APP_WEATHER_USE
    webpage_header += F("<li><a href='/weather_setting'>新版天气</a></li>");
#endif
#if APP_WEATHER_OLD_USE
    webpage_header += F("<li><a href='/weather_old_setting'>旧版天气</a></li>");
#endif
#if APP_BILIBILI_FANS_USE
    webpage_header += F("<li><a href='/bili_setting'>B站</a></li>");
#endif
#if APP_PICTURE_USE
    webpage_header += F("<li><a href='/picture_setting'>相册</a></li>");
#endif
#if APP_MEDIA_PLAYER_USE
    webpage_header += F("<li><a href='/media_setting'>媒体播放器</a></li>");
#endif
#if APP_SCREEN_SHARE_USE
    webpage_header += F("<li><a href='/screen_setting'>屏幕分享</a></li>");
#endif
#if APP_HEARTBEAT_USE
    webpage_header += F("<li><a href='/heartbeat_setting'>心跳</a></li>");
#endif
#if APP_ANNIVERSARY_USE
    webpage_header += F("<li><a href='/anniversary_setting'>纪念日</a></li>");
#endif
#if APP_STOCK_MARKET_USE
    webpage_header += F("<li><a href='/stock_setting'>股票行情</a></li>");
#endif
#if APP_PC_RESOURCE_USE
    webpage_header += F("<li><a href='/pc_resource_setting'>PC资源监控</a></li>");
#endif
    webpage_header += F("</ul>");
}

void init_motion_page_footer()
{
    webpage_footer = F("<footer>&copy;ClimbSnail 2021</footer>");
    webpage_footer += F("</body></html>");
}

// All supporting functions from here...
void motion_data_api()
{
    motion_data = "motion-data: 12,34,56";
    motion_server.send(200, "text/plain", motion_data);
}

void motion_sys_setting()
{
    char buf[2048];
    char ssid_0[32];
    char password_0[32];
    char power_mode[32];
    char backLight[32];
    char rotation[32];
    char mpu_order[32];
    char min_brightness[32];
    char max_brightness[32];
    char time[32];
    char auto_calibration_mpu[32];
    char auto_start_app[32];
    // 读取数据
    app_controller->send_to(MOTION_STATE_SERVER_APP_NAME, "AppCtrl", APP_MESSAGE_READ_CFG,
                            NULL, NULL);
    
    SysUtilConfig cfg = app_controller->sys_cfg;
    // 主要为了处理启停MPU自动校准的单选框
    if (0 == cfg.auto_calibration_mpu)
    {
        sprintf(buf, SYS_SETTING,
                ssid_0, password_0,
                power_mode, backLight, rotation,
                mpu_order, "checked=\"checked\"", "",
                auto_start_app);
    }
    else
    {
        sprintf(buf, SYS_SETTING,
                ssid_0, password_0,
                power_mode, backLight, rotation,
                mpu_order, "", "checked=\"checked\"",
                auto_start_app);
    }
    webpage = buf;
    Send_HTML(webpage);
}