#include "bullet_counter.h"
#include "bullet_counter_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "common.h"

#define BULLET_COUNTER_APP_NAME "Bullet Counter"

#define BULLET_COUNTER_CONFIG_PATH "/bulletcounter.cfg"

static int bullet_counter_init(AppController *sys)
{
    tft->setSwapBytes(true);
    bullet_counter_gui_init();
    return 0;
}

static void bullet_counter_process(AppController *sys,
                            const ImuAction *act_info,
                            int btn_event)
{
    if(0 == btn_event)
    {
        Serial.printf("Will exit the app. \n");
        sys->app_exit(); // 退出APP
        return;
    }

    Serial.printf("Display bullet status. \n");
    display_bullet_status(bullet_sensor.getNum(), bullet_sensor.isLoaded());
}

static void bullet_counter_background_task(AppController *sys,
                                    const ImuAction *act_info)
{

}

static int bullet_counter_exit_callback(void *param)
{
    bullet_counter_gui_del();
    return 0;
}

static void bullet_counter_message_handle(const char *from, const char *to,
                                   APP_MESSAGE_TYPE type, void *message,
                                   void *ext_info)
{
   
}

APP_OBJ bullet_counter_app = {BULLET_COUNTER_APP_NAME, &app_bullet_counter, "",
                              bullet_counter_init, bullet_counter_process, bullet_counter_background_task,
                              bullet_counter_exit_callback, bullet_counter_message_handle};
