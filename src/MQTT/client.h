#include <ArduinoMqttClient.h>
#include <Wifi/connectWIFI.h>
#include <credentials.h>

// #include <ArduinoMqttClient.h>
#if defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_AVR_UNO_WIFI_REV2)
#include <WiFiNINA.h>
#elif defined(ARDUINO_SAMD_MKR1000)
#include <WiFi101.h>
#elif defined(ARDUINO_ESP8266_ESP12)
#include <ESP8266WiFi.h>
#endif

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

/* DONT FORGET TO DECLARE THESE IN CREDENTIALS FILE !!!
 * broker[]
 * port
 * topic[]
 * username
 * password
 */

const long interval = 1000;
unsigned long previousMillis = 0;

int count = 0;

void mqtt_setup()
{
    // You can provide a unique client ID, if not set the library uses Arduino-millis()
    // Each client must have a unique client ID
    // mqttClient.setId(mqtt_clientId);

    // You can provide a username and password for authentication
    // mqttClient.setUsernamePassword(mqtt_username, mqtt_password);

    Serial.print("Attempting to connect to the MQTT broker: ");
    Serial.println(broker);

    if (!mqttClient.connect(broker, mqtt_port))
    {
        Serial.print("MQTT connection failed! Error code = ");
        Serial.println(mqttClient.connectError());

        while (1)
            ;
    }

    Serial.println("You're connected to the MQTT broker!");
    Serial.println();

    Serial.print("Subscribing to topic: ");
    Serial.println(topic);
    Serial.println();

    // subscribe to a topic
    mqttClient.subscribe(topic);

    // topics can be unsubscribed using:
    // mqttClient.unsubscribe(topic);

    Serial.print("Waiting for messages on topic: ");
    Serial.println(topic);
    Serial.println();
}

void mqtt_loop()
{
    // check for incoming messages
    int messageSize = mqttClient.parseMessage();
    if (messageSize)
    {
        // we received a message, print out the topic and contents
        Serial.print("Received a message with topic '");
        Serial.print(mqttClient.messageTopic());
        Serial.print("', length ");
        Serial.print(messageSize);
        Serial.println(" bytes:");

        // use the Stream interface to print the contents
        while (mqttClient.available())
        {
            Serial.print((char)mqttClient.read());
        }
        Serial.println();

        Serial.println();
    }

    // avoid having delays in loop, we'll use the strategy from BlinkWithoutDelay
    // see: File -> Examples -> 02.Digital -> BlinkWithoutDelay for more info
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        // save the last time a message was sent
        previousMillis = currentMillis;

        Serial.print("Sending message to topic: ");
        Serial.println(topic);
        Serial.print("echo ");
        Serial.println(count);

        // send message, the Print interface can be used to set the message contents
        mqttClient.beginMessage(topic);
        mqttClient.print("echo ");
        mqttClient.print(count);
        mqttClient.endMessage();

        Serial.println();

        count++;
    }
}