#ifndef STABILITY_H
#define STABILITY_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>

struct Motion
{
    uint32_t tick;
    float ypr[3];
};

struct FiringStability
{
    uint32_t trig_time;
    Motion motions[50];
};

#endif