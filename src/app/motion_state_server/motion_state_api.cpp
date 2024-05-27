#include "motion_state_api.h"
#include "network.h"
#include "app/app_conf.h"
#include "HardwareSerial.h"

WebServer motion_server(80);
static String motion_data = "";

static void motion_data_api_func()
{
    motion_data = "motion-data: 12,34,56";
    motion_server.send(200, "text/plain", motion_data);
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

