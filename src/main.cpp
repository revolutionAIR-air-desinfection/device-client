#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// LED stripe stuff
#include <LEDstripe.h>

// connectWIFI stuff
#include <connectWIFI.h>
const char *ssid = "Pixelspot";     // wifi SSID
const char *password = "asdfjklo"; // wifi Password

void setup()
{
    // general stuff
    Serial.begin(9600);

    // LEDstripe stuff
    LEDstripe_setup();

}

void loop()
{
    // LED stripe stuff
    WifiNotConnected();

    // connectWIFI stuff
    connectWIFI_setup(ssid, password);

    // LEDstripe stuff
    LEDstripe_loop();
}
