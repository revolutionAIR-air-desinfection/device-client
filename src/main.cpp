#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// LED stripe stuff
// #include <LEDstripe.h> (already included by <connectWIFI.h>)

// connectWIFI stuff
#include <connectWIFI.h>

// FAN stuff
#include <fan.h>

// Relais stuff
#include <relais.h>

const char *ssid = "Pixelspot";     // wifi SSID
const char *password = "123456789"; // wifi Password

void setup()
{
    // ============== general ==============
    Serial.begin(9600);

    // ============== fan ==============
    fan_setup();

    // ============== LEDstripe ==============
    LEDstripe_setup();

    // ============== relais ==============
    relais_setup();
}
 
void loop()
{
    // ============== connectWIFI ==============
    // connectWIFI(ssid, password);

    // ============== relais ==============
    // relaisON();
    // relaisOFF();

    // ============== fan ============== 
    fan_loop();

    // ============== LEDstripe ============== 
    // LEDstripe_loop(); // takes very long

    // applyAllLeds(0, 255, 255);
}
