// /*
//     FILE ONLY EXISTS TO BE ABLE TO COMPILE IN VS CODE WITH PLATFORMIO
//     CODE INSIDE THIS FILE IS NOT USED
// */

// #include <Arduino.h>
// #include <Thread.h>
// #include <ThreadController.h>

// #include "mqtt/MqttClient.h"

// ThreadController controller = ThreadController();

// Thread *mqttThread = new Thread();
// Thread *rainbowThread = new Thread();

// void setup()
// {
//     Serial.begin(9600);

//     ledStripe_setup();
//     relais_setup();
//     fan_setup();
//     temperature_setup();
//     mqtt_setup();

//     // configuring threads
//     mqttThread->onRun(mqtt_loop);
//     rainbowThread->onRun(ledStripe_loop);

//     controller.add(mqttThread);
//     controller.add(rainbowThread);
// }

// void loop()
// {
//     controller.run();
//     // mqtt_loop();
//     // ledStripe_loop();
// }
