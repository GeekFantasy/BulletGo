#ifndef APP_STABILITY_TRAINING_GUI_H
#define APP_STABILITY_TRAINING_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#define STABILITY_TRAINING_DOT_GREEEN lv_color_hex(0x00FF00)
#define STABILITY_TRAINING_DOT_RED    lv_color_hex(0xFF0000)

extern const lv_img_dsc_t app_stability_training ;

void stability_training_gui_init();
void count_down_gui_init(int count_down);
void count_down_gui_update(int count_down);
void count_down_gui_release();
void stability_training_gui_del(void);
void stability_training_gui_update(lv_color_t color, int dot_x, int dot_y, uint32_t second, int score);

#ifdef __cplusplus
}
#endif

#endif