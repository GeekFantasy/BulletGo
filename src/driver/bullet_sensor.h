#ifndef BULLET_SENSOR_H
#define BULLET_SENSOR_H

#define BULLET_SENSOR_IIC_FRQ       100000
#define BULLET_SENSOR_SDA_PIN       13
#define BULLET_SENSOR_SCL_PIN       15
#define BULLET_SENSOR_INT_PIN       2

#define BULLET_SENSOR_TRIGER_BIT    7


class BulletSensor
{
    public:
    void init();
    int getNum();
    bool isLoaded();
};

#endif