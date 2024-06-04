#include "motion_state_api.h"
#include "network.h"
#include "app/app_conf.h"
#include "HardwareSerial.h"
#include "common.h"

#define RESP_DATA_COUNT             50  // The count of the sensor data responsed once.

WebServer motion_server(80);
static IMUSensorData tmp_sen_data[RESP_DATA_COUNT];

static void motion_data_api_func()
{
    int num = imu_data.getAllData(tmp_sen_data, RESP_DATA_COUNT);
    String motion_data;
    motion_data.reserve(22 + num * (12 + 3 * 7));
    motion_data += "tick,acc_x,acc_y,acc_z\n";

    for (size_t i = 0; i < num; i++)
    {
        char line[35];
        snprintf(line, sizeof(line), "%d,%2.2f,%2.2f,%2.2f\n",tmp_sen_data[i].tick, tmp_sen_data[i].acc[0], tmp_sen_data[i].acc[1], tmp_sen_data[i].acc[2]);
        motion_data += line;
    }
    
    motion_server.send(200, "text/plain", motion_data);
    Serial.println("Motion Data API Called.");
}

void start_motion_api()
{
    motion_server.on("/motion-state", HTTP_GET, motion_data_api_func);

    motion_server.begin();
    Serial.println("HTTP server started");
}

void motion_api_handle()
{
    motion_server.handleClient();
}

void stop_motion_api()
{
    motion_server.stop();
    motion_server.close();
}

