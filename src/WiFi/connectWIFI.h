#include <ESP8266WiFi.h>
#include <LED/effects/pulseWarning.h>
#include <credentials.h>
#include <WiFi/ClientHandler.h>

WiFiServer wifiServer(1080);

void connectWIFI()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password); // Connect to wifi

        // Wait for connection with lil animation
        Serial.println("Connecting to Wifi");
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print(".");
            WifiNotConnected();
        }
        Serial.println("\nConnected");

        // ========== CLIENT =================

        Serial.println(WiFi.localIP());

        wifiServer.begin();
    }
}

void clientLoop()
{
    WiFiClient client = wifiServer.available();

    if (client)
    {

        while (client.connected())
        {

            String command = "";
            while (client.available() > 0)
            {
                char c = client.read();
                command += c;
                // client.write(c); // echo bounce back to client
            }
            if (!command.isEmpty())
            {
                // Serial.print(command);
                handleCommand(command);
            }
            
            Blue();

            delay(10);
        }

        client.stop();
        Serial.println("Client disconnected");
    }
}
