#include "../UVC/relais.h"
#include "../fan/fan.h"

bool isDeviceON = false;

void setDeviceState(bool state)
{
    isDeviceON = state;
}

void debug(String cmd)
{
    Serial.println(cmd);
    
}

void fanspeed(String cmd)
{
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
        Serial.println("ERROR: unknown RELAIS value: " + cmd);
    }
}

void autopilot(String cmd)
{
    if (cmd == "ON")
    {
        relaisON();
        fanON();
        // TODO: apply status color

        Serial.println("auto ON");
        Serial.println("[AUTO] uvc ON");
        Serial.println("[AUTO] fan ON");
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

void rgb(String cmd)
{
    // TODO: not implemented yet
    Serial.println("ERROR: UNIMPLEMENTED METHOD");
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
