#include "bullet_sensor.h"
#include "common.h"


// BulletSensor::BulletSensor()
// {

// }

void BulletSensor::init()
{
    Wire1.begin( BULLET_SENSOR_SDA_PIN, BULLET_SENSOR_SCL_PIN, BULLET_SENSOR_IIC_FRQ);
    fetch_data_time = 0;
    sensor_data[0] = 0x0F;
}

void BulletSensor::initInterrupt(void (*isr)())
{
    pinMode(BULLET_SENSOR_INT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BULLET_SENSOR_INT_PIN), isr, FALLING);
}

void BulletSensor::cancelInterrupt()
{
     detachInterrupt(digitalPinToInterrupt(BULLET_SENSOR_INT_PIN));
}

bool BulletSensor::getSensorData()
{
    uint8_t data[1];

    if(xTaskGetTickCount() - fetch_data_time <= BULLET_FETCH_INTERVAL)
    {
        return true;
    }
    
    uint8_t status = I2Cdev::readByte(0x20, 0x00, data, 1000, &Wire1);
    if(status)
    {
        sensor_data[0] = data[0];
        fetch_data_time = xTaskGetTickCount();
    }

    return status;
}

int BulletSensor::getNum()
{
    int num = 0;
    
    if(getSensorData())
    {
        for (int i = BULLET_SENSOR_FIRST_BULLET_BIT; i <= BULLET_SENSOR_LAST_BULLET_BIT; i++)
        {
            if(0 == (sensor_data[0] & (1 << i)))
            {
                num = i;
            }
        }  
    }
    
    return num;
}

bool BulletSensor::magazineExist()
{
    bool exist = false;
    
    if(getSensorData())
    {
        if(0 == (sensor_data[0] & (1 << BULLET_SENSOR_MAGAZINE_BIT)))
        {
            exist = true;
        }
    }

    return exist;
}

bool BulletSensor::isLoaded()
{
    bool loaded = false;
    
    if(getSensorData())
    {
        if(0 == (sensor_data[0] & (1 << BULLET_SENSOR_TRIGER_BIT)))
        {
            loaded = true;
        }
    }

    return loaded;
}