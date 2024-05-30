#include "firing_stability.h"
#include "firing_stability_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "common.h"

#define FIRING_STABILITY_APP_NAME "Firing Stability"
#define FIRING_STABILITY_CONFIG_PATH "/firingstability.cfg"
FiringStability stab_data;

int update_cnt = 0;

static void get_average_data(FiringStability &sd, int16_t *aver_x, int16_t *aver_y)
{
    int i = 0;
    int32_t sum_x = 0;
    int32_t sum_y = 0;

    for (i = 0; i < 50; i++)
    {
        sum_x += sd.stability_data[i].ypr[0] * 100;
        sum_y += sd.stability_data[i].ypr[1] * 100;
    }

    *aver_x = sum_x / 50;
    *aver_y = sum_y / 50;
}

static int firing_stability_init(AppController *sys)
{
    int16_t aver_x = 0, aver_y = 0;

    if (fire_stab_data.size() > 0)
    {
        Serial.printf("fire_stab_data.size() = %d \n", fire_stab_data.size());
        stab_data = fire_stab_data.getLast();
        get_average_data(stab_data, &aver_x, &aver_y);
    }

    tft->setSwapBytes(true);
    
    Serial.printf("Start to gui init. aver_x: %d, aver_y : %d\n", aver_x, aver_y);
    firing_stability_gui_init(aver_x, aver_y);
    Serial.printf("Finished to gui init.\n");
    update_cnt = 0;
    return 0;
}

static void firing_stability_process(AppController *sys,
                                     const ImuAction *act_info,
                                     int btn_event)
{
    if (0 == btn_event)
    {
        Serial.printf("Exit stability training app. \n");
        sys->app_exit(); // 退出APP
        return;
    }
    Serial.printf("Begin to add data.\n");
    if (update_cnt < 50)
    {
        firing_stability_gui_update(stab_data.stability_data[update_cnt].ypr[0] * 100,  stab_data.stability_data[update_cnt].ypr[1] * 100);
        Serial.printf("*********Succeed to add one data, x: %f, y: %f *********.\n", 
                        stab_data.stability_data[update_cnt].ypr[0] ,
                        stab_data.stability_data[update_cnt].ypr[1]);
        update_cnt++;
    }
}

static void firing_stability_background_task(AppController *sys,
                                             const ImuAction *act_info)
{
}

static int firing_stability_exit_callback(void *param)
{
    firing_stability_gui_del();
    update_cnt = 0;
    return 0;
}

static void firing_stability_message_handle(const char *from, const char *to,
                                            APP_MESSAGE_TYPE type, void *message,
                                            void *ext_info)
{
}

APP_OBJ firing_stability_app = {FIRING_STABILITY_APP_NAME, &app_firing_stability, "",
                                firing_stability_init, firing_stability_process, firing_stability_background_task,
                                firing_stability_exit_callback, firing_stability_message_handle};