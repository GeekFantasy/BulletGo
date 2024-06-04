#include "FreeRTOS.h"

#ifndef BULLET_SENSOR_H
#define BULLET_SENSOR_H

#define BULLET_SENSOR_IIC_FRQ       100000
#define BULLET_SENSOR_SDA_PIN       13
#define BULLET_SENSOR_SCL_PIN       15
#define BULLET_SENSOR_INT_PIN       2
#define BULLET_FETCH_INTERVAL      20  //ms

#define BULLET_SENSOR_MAGAZINE_BIT          0
#define BULLET_SENSOR_FIRST_BULLET_BIT      1
#define BULLET_SENSOR_LAST_BULLET_BIT       6
#define BULLET_SENSOR_TRIGER_BIT            7

class BulletSensor
{
    private:
    TickType_t fetch_data_time;
    uint8_t sensor_data[1];
    bool getSensorData();

    public:
    void init();
    void initInterrupt(void (*isr)());
    void cancelInterrupt();
    int getNum();
    bool magazineExist();
    bool isLoaded();
};

#endif