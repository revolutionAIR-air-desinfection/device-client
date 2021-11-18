#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// LED stripe stuff
#include <LEDstripe.h>

// connectWIFI stuff
#include <connectWIFI.h>
const char *ssid = "projektebg";     // wifi SSID
const char *password = "9749970526914394"; // wifi Password

void setup()
{
    // general stuff
    Serial.begin(9600);

    // LEDstripe stuff
    LEDstripe_setup();

    // connectWIFI stuff
    connectWIFI_setup(ssid, password);
}

void loop()
{
    // LEDstripe stuff
    LEDstripe_loop();
}
