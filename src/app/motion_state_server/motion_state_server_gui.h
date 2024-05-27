#ifndef MOTION_STATE_SERVER_GUI_H
#define MOTION_STATE_SERVER_GUI_H

// #include "lv_port_indev.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#define ANIEND                      \
    while (lv_anim_count_running()) \
        lv_task_handler(); //等待动画完成

    void motion_server_gui_init(void);
    void motion_server_setting_init(void);
    void display_motion_server_setting(const char *title, const char *domain,
                        const char *info, const char *ap_ip,
                         lv_scr_load_anim_t anim_type);
    void motion_server_gui_del(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
    extern const lv_img_dsc_t app_motion_state_server;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif