#include <ESP8266WiFi.h>

#include "../led/effects/PulseWarning.h" // #include "led/LedStripe.h"
#include "../credentials/Credentials.h"
#include "../wifi/ClientHandler.h" // #include "uvc/Relais.h", #include "fan/Fan.h"

WiFiServer wifiServer(1080);

void connectWIFI()
{
	delay(10);
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
		wifiNotConnected(); // pulseWarning
	}

	randomSeed(micros());

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
}
