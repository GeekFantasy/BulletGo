#ifndef MOTION_STATE_API_H
#define MOTION_STATE_API_H

#include "sys/app_controller.h"

//extern AppController *app_controller; // APP控制器

void start_motion_api();
void motion_api_handle();
void stop_motion_api();

#endif