#include "bullet_counter.h"
#include "bullet_counter_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "common.h"

#define BULLET_COUNTER_APP_NAME "Bullet Counter"
#define BULLET_COUNTER_CONFIG_PATH "/bulletcounter.cfg"
#define TRIGGER_MOTION_RECORD_TIME 400 // 子弹发射后，多长时间开始采集 IMU的数据

static int bullet_cnt = 0;
static int bullet_cnt_prior = 0;
static bool is_loaded_prior = false;
static bool is_loaded = false;
static bool magazine_exist = false;
static bool magazine_exist_prior = false;
static bool inter_triggered = true;
static uint32_t inter_triggered_time = 0;
static bool need_record_motion = false;
static uint32_t motion_trigger_time = 0;
static uint32_t motion_record_time = 0;

void IRAM_ATTR handle_bulletsensor_inter()
{
    inter_triggered = true;
    inter_triggered_time = xTaskGetTickCount();
}

static int bullet_counter_init(AppController *sys)
{
    // tft->setSwapBytes(true);
    bullet_cnt = 0;
    is_loaded_prior = false;
    is_loaded = false;
    magazine_exist = false;
    inter_triggered = true;
    inter_triggered_time = xTaskGetTickCount();
    need_record_motion = false;

    bullet_counter_gui_init();
    bullet_sensor.initInterrupt(handle_bulletsensor_inter);
    return 0;
}

static void bullet_counter_process(AppController *sys,
                                   const ImuAction *act_info,
                                   int btn_event)
{
    if (ButtonEvent::BTN_DOWN == btn_event)
    {
        Serial.printf("Will exit the app. \n");
        sys->app_exit(); // 退出APP
        return;
    }

    bullet_cnt = bullet_sensor.getNum();
    is_loaded = bullet_sensor.isLoaded();
    magazine_exist = bullet_sensor.magazineExist();

    if (bullet_cnt != bullet_cnt_prior ||
        is_loaded != is_loaded_prior ||
        magazine_exist != magazine_exist_prior)
    {
        if (is_loaded_prior && !is_loaded)
        {
            need_record_motion = true;
            motion_trigger_time = xTaskGetTickCount();
            motion_record_time = motion_trigger_time + TRIGGER_MOTION_RECORD_TIME;
        }

        bullet_cnt_prior = bullet_cnt;
        is_loaded_prior = is_loaded;
        magazine_exist_prior = magazine_exist;
        display_bullet_status_v2(bullet_cnt, is_loaded, magazine_exist);
    }
    else
    {
        delay(25);
    }

    if (need_record_motion && (xTaskGetTickCount() >= motion_record_time))
    {
        //Serial.printf("*****Current time: %d, motion record time: %d, trigger time: %d \n", xTaskGetTickCount(), motion_record_time, motion_trigger_time );
        IMUSensorData data[50];
        FiringStability fs;

        int size = imu_data.getAllData(data, sizeof(data));
        fs.trig_time = motion_trigger_time;

        for (size_t i = 0; i < size; i++)
        {
            fs.motions[i].tick = data[i].tick;
            fs.motions[i].ypr[0] = data[i].ypr[0];
            fs.motions[i].ypr[1] = data[i].ypr[1];
            fs.motions[i].ypr[2] = data[i].ypr[2];
        }
        fire_stab_data.push(fs);

        need_record_motion = false;
        sys->send_to(BULLET_COUNTER_APP_NAME, CTRL_NAME, APP_MESSAGE_WRITE_DATA, NULL, NULL);
    }
}

static void bullet_counter_background_task(AppController *sys,
                                           const ImuAction *act_info)
{
}

static int bullet_counter_exit_callback(void *param)
{
    bullet_counter_gui_del();
    bullet_sensor.cancelInterrupt();
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
