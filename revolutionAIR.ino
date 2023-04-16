#include <Arduino.h>
// #include <Thread.h>
// #include <ThreadController.h>

// #include "./src/MQTT/mqttclient.h"

// ThreadController controller = ThreadController();

// Thread *mqttThread = new Thread();
// Thread *rainbowThread = new Thread();

void setup()
{
    Serial.begin(9600);
    // srand (static_cast <unsigned> (time(0))); // seeding random number generator

    // ledStripe_setup();
    // relais_setup();
    // fan_setup();
    // temperature_setup();
    // mqtt_setup();

    // // configuring threads
    // mqttThread->onRun(mqtt_loop);
    // rainbowThread->onRun(ledStripe_loop);

    // controller.add(mqttThread);
    // controller.add(rainbowThread);
}

void loop()
{
    // controller.run();
    Serial.println("dd");
}
