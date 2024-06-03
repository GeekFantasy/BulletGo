#ifndef FIRING_TABILITY_TRAINING_GUI_H
#define FIRING_TABILITY_TRAINING_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern const lv_img_dsc_t app_firing_stability ;

void firing_stability_gui_init(int16_t aver_x, int16_t aver_y, int number, int score);
void firing_stability_gui_del();
void firing_stability_gui_update(int x, int y);

#ifdef __cplusplus
}
#endif

#endif