#ifndef APP_BULLET_COUNTER_GUI_H
#define APP_BULLET_COUNTER_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern lv_font_t digifacewide;
extern const lv_img_dsc_t app_bullet_counter;
extern const lv_img_dsc_t bullet_counter_loaded;
extern const lv_img_dsc_t bullet_counter_not_loaded;

void bullet_counter_gui_init();
void display_bullet_status();

#ifdef __cplusplus
}
#endif

#endif