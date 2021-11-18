#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// LED stripe stuff
// #include <LEDstripe.h> (already included by <connectWIFI.h>)

// connectWIFI stuff
#include <connectWIFI.h>

const char *ssid = "";     // wifi SSID
const char *password = ""; // wifi Password

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
    WifiNotConnected(); // TODO: enable

    // connectWIFI stuff
    connectWIFI_setup(ssid, password); // TODO: enable

    // LEDstripe stuff
    LEDstripe_loop();
}
