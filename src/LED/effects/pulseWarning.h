#include "../LedStripe.h"

void wifiNotConnected()
{
	pulseBrightness(255, 255, 0); // yellow
}

void deviceOpen()
{
	pulseBrightness(255, 0, 0); // red
}

void mqttServerDisconnected()
{
	pulseBrightness(255, 165, 0); // orange
}

void blue()
{
	pulseBrightness(0, 0, 255); // blue
}
