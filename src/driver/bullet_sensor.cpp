#include "bullet_sensor.h"
#include "common.h"


// BulletSensor::BulletSensor()
// {

// }

void BulletSensor::init()
{
    Wire1.begin( BULLET_SENSOR_SDA_PIN, BULLET_SENSOR_SCL_PIN, BULLET_SENSOR_IIC_FRQ);
}

int BulletSensor::getNum()
{
    int num = 0;
    uint8_t data[1];
    uint8_t status = I2Cdev::readByte(0x20, 0x00, data, 1000, &Wire1);
    if(status)
    {
        for (int i = 0; i < 7; i++)
        {
            if(0 == (data[0] & (1 << i)))
            {
                num = i;
            }
        }  
    }
    
    return num;
}

bool BulletSensor::isLoaded()
{
    bool loaded = false;
    uint8_t data[1];

    uint8_t status = I2Cdev::readByte(0x20, 0x00, data, 1000, &Wire1);
    if(status)
    {
        if(0 == (data[0] & (1 << BULLET_SENSOR_TRIGER_BIT)))
        {
            loaded = true;
        }
    }

    return loaded;
}