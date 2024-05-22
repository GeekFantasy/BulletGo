#include "stability_training.h"
#include "stability_training_gui.h"
#include "ESP32Time.h"
#include "sys/app_controller.h"
#include "common.h"

#define STABILITY_TRAINING_APP_NAME "Stability Training"
#define BULLET_COUNTER_CONFIG_PATH "/bulletcounter.cfg"

static float pitch_init = 00.0f;
static float roll_init = 00.0f;
static float pitch_curr = 00.0f;
static  float roll_curr = 00.0f;

static uint32_t tick_init = 0;
static uint32_t seconds = 0;
static float score = 100.0; // 示例三位数
static int score_cnt = 1;

static int stability_training_init(AppController *sys)
{
    tft->setSwapBytes(true);
    stability_training_gui_init();

    mpu.updateYPR();
    pitch_init = mpu.getPitch();
    roll_init = mpu.getRoll();

    tick_init = lv_tick_get();
    seconds = tick_init/1000;
    score = 100;
    score_cnt = 1;
    return 0;
}

static void stability_training_process(AppController *sys,
                            const ImuAction *act_info,
                            int btn_event)
{
    if(0 == btn_event)
    {
        Serial.printf("Will exit stability training app. \n");
        sys->app_exit(); // 退出APP
        return;
    }

    mpu.updateYPR();
    pitch_curr = mpu.getPitch();
    roll_curr = mpu.getRoll();

    // Calc the positioni of the dot
    int px_y = (int)((pitch_curr - pitch_init) * 60);
    int px_x = (int)((roll_curr - roll_init) * 60);
    px_y = abs(px_y) < 120 ? px_y : (px_y < 0 ? -120 : 120);
    px_x = abs(px_x) < 120 ? px_x : (px_x < 0 ? -120 : 120);  
    lv_color_t dot_color = (abs(px_y) > 20 || abs(px_x) > 20) ? STABILITY_TRAINING_DOT_RED : STABILITY_TRAINING_DOT_GREEEN;

    // Calc the score
    int max_px = max(abs(px_y), abs(px_x));
    int score_tmp = 105 - max_px;
    score_tmp = score_tmp > 0 ? score_tmp : 0;
    score_tmp = score_tmp < 100 ? score_tmp : 100;
    score = (score * score_cnt + score_tmp)/(score_cnt + 1);
    score_cnt ++;

    // Calc the time
    seconds = (lv_tick_get() - tick_init) / 1000;
    stability_training_gui_update(dot_color, px_x, px_y, seconds, (int)score);
}

static void stability_training_background_task(AppController *sys,
                                    const ImuAction *act_info)
{

}

static int stability_training_exit_callback(void *param)
{
    stability_training_gui_del();
    return 0;
}

static void stability_training_message_handle(const char *from, const char *to,
                                   APP_MESSAGE_TYPE type, void *message,
                                   void *ext_info)
{
   
}

APP_OBJ stability_training_app = {STABILITY_TRAINING_APP_NAME, &app_stability_training, "",
                              stability_training_init, stability_training_process, stability_training_background_task,
                              stability_training_exit_callback, stability_training_message_handle};
