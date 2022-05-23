#include <PubSubClient.h>

#include "TemperatureSensor.h"
#include "../credentials/TemperatureSensor.h"

// size of msg[] is MSG_BUFFER_SIZE
void publish_temperature(PubSubClient *client, char msg[], int MSG_BUFFER_SIZE)
{
    const char* local_topic = "temperature";

    char temperature[4];
    dtostrf(getTempCByIndex(), 2, 2, temperature); // convert float to char array
    snprintf(msg, MSG_BUFFER_SIZE, temperature);

    // Serial.print("Publish ");
    // Serial.print(local_topic);
    // Serial.print(": ");
    // Serial.println(msg);

    client->publish(local_topic, msg);
}
