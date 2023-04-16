#include <Adafruit_NeoPixel.h>

#include "RGB.h"

/*
    DEFINITIONS FOR PINS
*/

#define TEMPERATURE D6 // Temperature sensor
#define RELAIS D3      // Relais for UVC LEDs
#define LED D1         // LED Stripe outside
#define LED_IN D2      // LED Stripe inside
#define PWM D4         // FAN PWM
#define PWM_RELAIS D5  // transistor to turn off the fan

/*
    Settings for LED Stripe
*/
#define NUMPIXELS 34            // number of leds on LED stripe
#define pulseDelay 15          // delay for pulsing warnging/error LED indicator
#define LEDfade_duration 10000  // time in ms the LED stripe needs to fade for 1 cycle
#define LEDstep_delay 500       // time for "rainbowMoving" to wait until stepping 1 LED further
#define maxBrightness 0.8        // 0.1 - 1.0 Value for Brightness
#define minBrightness 0.15

Adafruit_NeoPixel pixels(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_in(NUMPIXELS, LED_IN, NEO_GRB + NEO_KHZ800);

/*
    global colors
*/
#define AUTOPILOT RGB(0, 0, 255)
#define WIFI_NOT_CONNECTED RGB(255, 255, 0)
#define DEVICE_OPEN RGB(255, 0, 0)
#define MQTT_SERVER_DISCONNECTED RGB(255, 165, 0)
