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