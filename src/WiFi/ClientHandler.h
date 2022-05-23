#include "../uvc/Relais.h"
#include "../fan/Fan.h"
// #include "../config.h"

typedef uint8_t BYTE;

bool isDeviceON = false;

void setDeviceState(bool state)
{
	isDeviceON = state;
	//? TODO: implement device turning off?
}

void debug(String cmd)
{
	Serial.println("[DEBUG] " + cmd);
}

void fan(String cmd)
{
	setFanSpeed(cmd.toInt());
}

void uvc(String cmd)
{
	if (cmd == "ON")
	{
		relaisON();
		Serial.println("uvc ON");
	}
	else if (cmd == "OFF")
	{
		relaisOFF();
		Serial.println("uvc OFF");
	}
	else
	{
		Serial.println("ERROR: unknown RELAIS value: " + cmd);
	}
}

void rgb(RGB rgb)
{
	setCustomColor(rgb);

	Serial.print("rgb (");
	Serial.print(rgb.r);
	Serial.print(",");
	Serial.print(rgb.g);
	Serial.print(",");
	Serial.print(rgb.b);
	Serial.println(")");
}

void autopilot(String cmd)
{
	if (cmd == "ON")
	{
		relaisON();
		setFanSpeed(100);
		setCustomColor(AUTOPILOT);

		Serial.println("auto ON");
		Serial.println("[AUTO] uvc ON");
		Serial.println("[AUTO] fan ON");
		Serial.println("[AUTO] rgb AUTOPILOT");
	}
	else if (cmd == "OFF")
	{
		// do nothing
		Serial.println("auto OFF");
	}
	else
	{
		Serial.println("ERROR: unknown AUTO value: " + cmd);
	}
}

void power(String cmd)
{
	debug("power");
	if (cmd == "ON")
	{
		setDeviceState(true);
		autopilot("ON");
		Serial.println("device ON");
	}
	else if (cmd == "OFF")
	{
		setDeviceState(false);
		setCustomColor(RGB(0, 0, 0)); //! UNTESTED: should turn off the LED stripe
		fanOFF();
		relaisOFF();

		Serial.println("device OFF");
	}
	else
	{
		Serial.println("ERROR: unknown POWER value: " + cmd);
	}
}

void handleCommand(String topic, String cmd)
{
	if (topic == "debug")
	{
		debug(cmd);
	}
	else if (topic == "fan")
	{
		fan(cmd);
	}
	else if (topic == "uvc")
	{
		uvc(cmd);
	}
	else if (topic == "device")
	{
		power(cmd);
	}
	else if (topic == "auto")
	{
		autopilot(cmd);
	}
	else if (topic == "rgb")
	{
		// cmd must be rgb value like "12,213,123"
		rgb(stringToRGB(cmd));
	}
	else
	{
		Serial.println("ERROR: unknown topic");
	}
}
