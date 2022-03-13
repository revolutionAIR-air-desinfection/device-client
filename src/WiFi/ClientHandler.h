#include <UVC/relais.h>
#include <fan/fan.h>

bool isDeviceON = false;

void setDeviceState(bool state) {
    isDeviceON = state;
}

void handleCommand(String cmd) {

    Serial.println(cmd);

    if(cmd.equalsIgnoreCase("FAN ON")) {
        fanON();

    } else if(cmd.equalsIgnoreCase("FAN OFF")) {
        fanOFF();

    } else if(cmd.equalsIgnoreCase("UVC ON")) {
        relaisON();

    } else if(cmd.equalsIgnoreCase("UVC OFF")) {
        relaisOFF();

    } else if(cmd.equalsIgnoreCase("DEVICE ON")) {
        setDeviceState(true);
        
    } else if(cmd.equalsIgnoreCase("DEVICE OFF")) {
        setDeviceState(false);
        
    } else {
        // TODO: not implemented yet
    }

}
