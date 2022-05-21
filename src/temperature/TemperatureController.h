#include <PubSubClient.h>

#include "TemperatureSensor.h"

// size of msg[] is MSG_BUFFER_SIZE
void publish_temperature(PubSubClient *client, char msg[], int MSG_BUFFER_SIZE)
{
    const char* local_topic = "temperature";
    snprintf(msg, MSG_BUFFER_SIZE, "%d", getTemperature());

    Serial.print("Publish ");
    Serial.print(local_topic);
    Serial.print(": ");

    Serial.println(msg);
    client->publish(local_topic, msg);
}
