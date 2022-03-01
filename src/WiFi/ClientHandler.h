#include <UVC/relais.h>
#include <fan/fan.h>

void handleCommand(String cmd) {

    if(cmd.equalsIgnoreCase("FAN ON")) {
        Serial.print(cmd); // TODO: log
        fanON();
    } else if(cmd.equalsIgnoreCase("FAN OFF")) {
        Serial.print(cmd); // TODO: log
        fanOFF();
    } else if(cmd.equalsIgnoreCase("UVC ON")) {
        Serial.print(cmd); // TODO: log
        relaisON();
    } else if(cmd.equalsIgnoreCase("UVC OFF")) {
        Serial.print(cmd); // TODO: log
        relaisOFF();
    } else {
        // TODO: not implemented yet
        Serial.print(cmd); // TODO: log
    }

}
