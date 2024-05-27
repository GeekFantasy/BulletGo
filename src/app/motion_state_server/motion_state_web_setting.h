#ifndef MOTION_STATE_WEB_SETTING_H
#define MOTION_STATE_WEB_SETTING_H

#include <WString.h>
#include "sys/app_controller.h"

extern AppController *app_controller; // APP控制器
void init_motion_page_header(void);
void init_motion_page_footer(void);
void motion_data_api(void);
void motion_sys_setting(void);

#endif