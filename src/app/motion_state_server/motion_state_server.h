#ifndef MOTION_STATE_SERVER_H
#define MOTION_STATE_SERVER_H

#include "sys/interface.h"
#define SERVER_APP_NAME "WebServer"

#ifdef ESP8266
#include <ESP8266WiFi.h>      // Built-in
#include <ESP8266WiFiMulti.h> // Built-in
#include <ESP8266WebServer.h> // Built-in
#include <ESP8266mDNS.h>
extern ESP8266WebServer server;
#else
#include <WiFi.h>      // Built-in
#include <WiFiMulti.h> // 当我们需要使用ESP8266开发板存储多个WiFi网络连接信息时，可以使用ESP8266WiFiMulti库来实现。
#include <WebServer.h> // https://github.com/Pedroalbuquerque/ESP32WebServer
#include <ESPmDNS.h>
#include <DNSServer.h>
#include <HTTPClient.h>

#endif

extern APP_OBJ motion_state_server_app;

#endif