#include "../LedStripe.h"

void wifiNotConnected()
{
	pulseBrightness(WIFI_NOT_CONNECTED); // yellow
}

void deviceOpen()
{
	pulseBrightness(DEVICE_OPEN); // red
}

void mqttServerDisconnected()
{
	pulseBrightness(MQTT_SERVER_DISCONNECTED); // orange
}
