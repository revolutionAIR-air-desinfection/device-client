#include <Adafruit_NeoPixel.h>

// ============== LED stripe ==============
// #include <LED/LEDstripe.h> // (already included by <connectWIFI.h>)


// ============== MQTT ==============
#include <MQTT/client.h>


// ============== connectWIFI ==============
// # include <credentials.h>


// ============== FAN ==============
#include <fan/fan.h>


// ============== RELAIS ==============
#include <UVC/relais.h>


void setup()
{
    // ============== general ==============
    Serial.begin(9600);


    // ============== fan ==============
    // fan_setup();


    // ============== LEDstripe ==============
    LEDstripe_setup();


    // ============== relais ==============
    // relais_setup();

    // ============== mqtt ==============
    // mqtt_setup();
}
 
void loop()
{
    // ============== connectWIFI ==============
    // connectWIFI();


    // ============== relais ==============
    // relaisON();
    // relaisOFF();


    // ============== fan ============== 
    // fan_loop(100);


    // ============== mqtt ==============
    // mqtt_loop();


    // ============== LEDstripe ============== 
    LEDstripe_loop(); // takes very long
}
