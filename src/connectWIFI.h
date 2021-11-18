#include <ESP8266WiFi.h>

void connectWIFI_setup(const char *ssid, const char *password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); //Connect to wifi

    // Wait for connection with lil animation
    Serial.println("Connecting to Wifi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected");
}
