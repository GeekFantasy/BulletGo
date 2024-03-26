#ifndef APP_BULLET_COUNTER_GUI_H
#define APP_BULLET_COUNTER_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern const lv_img_dsc_t app_bullet_counter;

void bullet_counter_gui_init();
void bullet_counter_gui_del(void);
void display_bullet_status(int bullet_cnt, bool is_loaded);

#ifdef __cplusplus
}
#endif

#endif