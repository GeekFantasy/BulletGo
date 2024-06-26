#ifndef SYS_LOADING_H
#define SYS_LOADING_H

#include "lvgl.h"

/** Callback to call when the loading is ready*/
typedef void (*sys_loading_ready_cb_t)();
void start_loading_animation(sys_loading_ready_cb_t ready_cb);

#endif