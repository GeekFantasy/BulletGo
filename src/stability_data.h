#ifndef STABILITY_H
#define STABILITY_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>

struct StabilityData
{
    uint32_t tick;
    float ypr[3];
};

struct FiringStability
{
    uint32_t trigger_time;
    StabilityData stability_data[50];
};

#endif