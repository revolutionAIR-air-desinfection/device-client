// TODO: use switch case instead https://www.codeguru.com/cplusplus/switch-on-strings-in-c/

#include "../uvc/Relais.h"
#include "../fan/Fan.h"

// #include <iostream>
// #include <string>
// #include <sstream>
// #include <vector>
// #include <iterator>
// #include <cstdint>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::istringstream;
// using std::string;
// using std::vector;

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

void fanspeed(String cmd) // TODO: use int values for PWM
{
	/* //! OLD version without PWM
	if (cmd == "ON")
	{
		fanON();
		Serial.println("fan ON");
	}
	else if (cmd == "OFF")
	{
		fanOFF();
		Serial.println("fan OFF");
	}
	else
	{
		Serial.println("ERROR: unknown FAN value: " + cmd);
	}
	*/

	// //! new version with PWM
	// char *ending;
	// float speed_percentage = strtof(cmd.c_str(), &ending);
	// if (*ending != 0)
	// {
	// 	// error
	// 	Serial.println("ERROR: unknown FAN value: " + cmd);
	// }
	// else
	// {
	// 	setFanSpeed(speed_percentage);
	// }
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

void power(String cmd)
{
	if (cmd == "ON")
	{
		setDeviceState(true);
		Serial.println("device ON");
	}
	else if (cmd == "OFF")
	{
		setDeviceState(false);
		Serial.println("device OFF");
	}
	else
	{
		Serial.println("ERROR: unknown POWER value: " + cmd);
	}
}

void autopilot(String cmd)
{
	if (cmd == "ON")
	{
		relaisON();
		fanON();
		blue();

		Serial.println("auto ON");
		Serial.println("[AUTO] uvc ON");
		Serial.println("[AUTO] fan ON");
		Serial.println("[AUTO] rgb BLUE");
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

void rgb(String cmd) // cmd must be rgb value like "12,213,123"
{
	// // TODO: untested method
	// // converts "r,g,b to RGB value"
	// std::string str = cmd.c_str();
	// vector<string> values{};
	// char delimiter = ',';

	// istringstream sstream(str);
	// string value;

	// while (std::getline(sstream, value, delimiter))
	// {
	// 	value.erase(std::remove_if(value.begin(), value.end(), ispunct), value.end());
	// 	values.push_back(value);
	// }

	// for (const string s : values)
	// {
	// 	// 
	// 	char *ending;
	// 	float v = strtof(s.c_str(), &ending);
	// 	if (*ending != 0)
	// 	{
	// 		// error
	// 		Serial.print("ERROR: unknown RGB value: " + cmd);
	// 	}
	// 	else
	// 	{
	// 		// TODO send RGB value to LEDstripe.h
	// 	}
	// }
}

void handleCommand(String topic, String cmd)
{
	if (topic == "debug")
	{
		debug(cmd);
	}
	else if (topic == "fanspeed")
	{
		fanspeed(cmd);
	}
	else if (topic == "uvc")
	{
		uvc(cmd);
	}
	else if (topic == "power")
	{
		power(cmd);
	}
	else if (topic == "auto")
	{
		autopilot(cmd);
	}
	else if (topic == "rgb")
	{
		rgb(cmd);
	}
	else
	{
		// do nothing
	}
}
