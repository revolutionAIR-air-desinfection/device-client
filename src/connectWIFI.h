#include <ESP8266WiFi.h>
#include <LEDeffects/pulseWarning.h>
// #include <future> don't know why this is there but afraid to remove...

void connectWIFI(const char *ssid, const char *password)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password); //Connect to wifi

        // Wait for connection with lil animation
        Serial.println("Connecting to Wifi");
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print(".");
            WifiNotConnected();
        }
        Serial.println("\nConnected");
    }
}
