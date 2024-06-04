#ifndef FIRING_TABILITY_TRAINING_GUI_H
#define FIRING_TABILITY_TRAINING_GUI_H

// #ifdef __cplusplus
// extern "C" {
// #endif

#include "lvgl.h"
#include "stability_data.h"

extern const lv_img_dsc_t app_firing_stability ;

void firing_stability_gui_clean();
void firing_stability_gui_init(int16_t aver_x, int16_t aver_y, int number, int score);
void firing_stability_gui_init_v2(lv_obj_t** screen, lv_scr_load_anim_t anim_type, FiringStability &stab_data, int16_t aver_x, int16_t aver_y, int number, int score);
void firing_stability_gui_del();
bool firing_stability_gui_load_screen(lv_obj_t * screen, lv_scr_load_anim_t anim_type, uint32_t time);
void firing_stability_gui_update(int x, int y);
void firing_stability_gui_set_values(lv_obj_t *chart, lv_chart_series_t *ser_acc_x, lv_chart_series_t * ser_acc_y, int x, int y);
void firing_stability_gui_del_v2(lv_obj_t * screen);

// #ifdef __cplusplus
// }
// #endif

#endif