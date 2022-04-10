#include <Adafruit_NeoPixel.h>

// ============== LED stripe ==============
// #include <LED/LEDstripe.h> // (already included by <connectWIFI.h>)

// ============== WIFI ==============
// #include <WiFi/connectWIFI.h>

// ============== MQTT ==============
#include "./src/MQTT/mqttclient.h"

// ============== connectWIFI ==============
// # include <credentials/credentials.h> // (already included by <connectWIFI.h>)

// ============== FAN ==============
// #include <fan/fan.h> // (already included by <ClientHandler.h>)

// ============== RELAIS ==============
// #include <UVC/relais.h>  // (already included by <ClientHandler.h>)

void setup()
{
  // ============== general ==============
  Serial.begin(9600);

  // ============== fan ==============
  fan_setup();

  // ============== LEDstripe ==============
  LEDstripe_setup();

  // ============== relais ==============
  relais_setup();

  // ============== mqtt ==============
  mqtt_setup();
}

void loop()
{

  // ============== WIFI ==============
  // connectWIFI(); // called in mqttclient.h, mqtt_setup()

  // ============== relais ==============
  // relaisON();
  // relaisOFF();

  // ============== fan ==============
  // fan_loop(50);

  // ============== mqtt ==============
  mqtt_loop();

  // ============== LEDstripe ==============
  // LEDstripe_loop(); // takes very long
  Blue();
}
