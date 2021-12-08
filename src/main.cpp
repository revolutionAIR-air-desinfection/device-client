#include <Adafruit_NeoPixel.h>

// ============== LED stripe ==============
// #include <LEDstripe.h> (already included by <connectWIFI.h>)


// ============== MQTT ==============
#include <MQTT/client.h>


// ============== connectWIFI ==============
#include <connectWIFI.h>
# include <credentials.h>


// ============== FAN ==============
#include <fan.h>


// ============== RELAIS ==============
#include <relais.h>


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
