# revolutionAIR

The smartest air disinfector in the world! IoT integration with MQTT and mobile app.

## Status Colors

COLOR           |   MEANING
-------------   |   -------------
:rainbow:       |   everything is fine :white_check_mark:
:green_heart:   |   -
:yellow_heart:  |   no WIFI connection
:heart:         |   device open
:purple_heart:  |   -
:blue_heart:    |   -

## Credentials

make sure to add a `src/credentials/credentials.h` file to your project with the following imformation: 

```
// [==========] CREDENTIALS [==========]

// ------------ WIFI ------------
const char *ssid = "";     // wifi SSID
const char *password = ""; // wifi Password

// ------------ MQTT ------------
const char broker[] = ""; // MQTT broker URL (e.g. "test.mosquitto.org")
const int mqtt_port = 1883;
const char topic[] = ""; // MQTT topic to subscribe (e.g. "arduino/echo")
const char *mqtt_username = ""; // MQTT auth username if used
const char *mqtt_password = ""; // MQTT auth password if used
// const char *mqtt_clientId = "";
```