#include "firing_stability.h"
#include "firing_stability_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "common.h"

#define FIRING_STABILITY_APP_NAME "Firing Stability"
#define FIRING_STABILITY_CONFIG_PATH "/firingstability.cfg"

#define ANIMATION_TIME 500

FiringStability stab_data;

static int update_cnt = 0;
static bool ui_initialed = false;

static int num_of_data = 0;
static int cur_data_idx = 0; 
static lv_obj_t* screens[FIRING_STAB_DATA_SIZE] = {NULL, NULL, NULL, NULL, NULL};
lv_scr_load_anim_t anim_type = LV_SCR_LOAD_ANIM_NONE;
static uint32_t not_respond_time = 0;  // Use it to make the screen load animation finish.

static void get_average_data(FiringStability &sd, int16_t *aver_x, int16_t *aver_y)
{
    int i = 0;
    int32_t sum_x = 0;
    int32_t sum_y = 0;

    for (i = 0; i < 50; i++)
    {
        sum_x += sd.motions[i].ypr[0] * 100;
        sum_y += sd.motions[i].ypr[1] * 100;
    }

    *aver_x = sum_x / 50;
    *aver_y = sum_y / 50;
}

static int firing_stability_init(AppController *sys)
{
    num_of_data = fire_stab_data.size();
    cur_data_idx = 0;
    not_respond_time = 0;

    firing_stability_gui_clean();
    anim_type = LV_SCR_LOAD_ANIM_FADE_IN;

    Serial.printf("******The number of stability data is %d. ******\n", num_of_data);

    // if (fire_stab_data.size() > 0)
    // {
    //     int16_t aver_x = 0, aver_y = 0;

    //     Serial.printf("fire_stab_data.size() = %d \n", fire_stab_data.size());
    //     stab_data = fire_stab_data.getLast();
    //     get_average_data(stab_data, &aver_x, &aver_y);

    //     tft->setSwapBytes(true);
    //     Serial.printf("Start to gui init. aver_x: %d, aver_y : %d\n", aver_x, aver_y);
    //     firing_stability_gui_init(aver_x, aver_y, 1, 100);
    //     Serial.printf("Finished to gui init.\n");
    //     update_cnt = 0;
    //     ui_initialed = true;
    // }

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

    if(xTaskGetTickCount() < not_respond_time) // For the case where the animation need to finish
    {
        delay(40);
        return;   
    }

    // 具体操作
    if (TURN_LEFT == act_info->active)
    {
        cur_data_idx++;
        cur_data_idx %= num_of_data;
        anim_type = LV_SCR_LOAD_ANIM_MOVE_LEFT;
    }
    else if (TURN_RIGHT == act_info->active)
    {
        cur_data_idx--;
        cur_data_idx = (cur_data_idx + num_of_data) % num_of_data;
        anim_type = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
    }
    Serial.printf("******Current data index is %d. ******\n", cur_data_idx);

    if(NULL == screens[cur_data_idx])
    {
        // Init the screen and fill in data 
        int16_t aver_x = 0, aver_y = 0;
        FiringStability stab_data = fire_stab_data.getIndex(num_of_data - cur_data_idx - 1); // The last one shows first
        get_average_data(stab_data, &aver_x, &aver_y);
        Serial.printf("******Average x: %d, average y: %d. ******\n", aver_x, aver_y);

        firing_stability_gui_init_v2(&screens[cur_data_idx], anim_type, stab_data, aver_x, aver_y, (cur_data_idx + 1), (100 - cur_data_idx));
        not_respond_time = xTaskGetTickCount() + ANIMATION_TIME;
        Serial.printf("******The trigger time of the current data: %d. ******\n", stab_data.trig_time);
    }
    else
    {
        //  Display the screen directly
        if(firing_stability_gui_load_screen(screens[cur_data_idx], anim_type, ANIMATION_TIME))
        {
            not_respond_time = xTaskGetTickCount() + ANIMATION_TIME; 
        }
        else
        {
            delay(40);
        }
        
        Serial.printf("******Need to delay for screen load animation. ******\n");
    }
    
    // if (ui_initialed)
    // {
    //     Serial.printf("Begin to add data.\n");
    //     if (update_cnt < 50)
    //     {
    //         firing_stability_gui_update(stab_data.motions[update_cnt].ypr[0] * 100, stab_data.motions[update_cnt].ypr[1] * 100);
    //         Serial.printf("*********Succeed to add one data, x: %f, y: %f *********.\n",
    //                       stab_data.motions[update_cnt].ypr[0],
    //                       stab_data.motions[update_cnt].ypr[1]);
    //         update_cnt++;
    //     }
    // }
}

static void firing_stability_background_task(AppController *sys,
                                             const ImuAction *act_info)
{
}

static int firing_stability_exit_callback(void *param)
{
    num_of_data = 0;
    cur_data_idx = 0;

    for (size_t i = 0; i < FIRING_STAB_DATA_SIZE; i++)
    {
        if(NULL != screens[i])
        {
            firing_stability_gui_del_v2(screens[i]);
        }
        screens[i] = NULL;
    }
    

    // firing_stability_gui_del();
    // update_cnt = 0;
    // ui_initialed = false;
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
