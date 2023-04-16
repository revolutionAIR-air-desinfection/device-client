#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>

#include "../WiFi/connectWIFI.h" 
#include "DateTime.h"
#include "../temperature/TemperatureController.h"

const int update_interval = 3000;

BearSSL::CertStore certStore;
WiFiClientSecure espClient;
PubSubClient *client;

#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];
unsigned long lastMsg = 0;
int value = 0;

void callback(char *topic, byte *payload, unsigned int length)
{
	Serial.print("Message arrived [");
	Serial.print(topic);
	Serial.print("] ");
	String message = "";

	for (unsigned int i = 0; i < length; i++)
	{
		message = message + (char)payload[i];
	}
	Serial.println(message);

	handleCommand(topic, message);
}

void reconnect()
{
	while (!client->connected())
	{
		Serial.print("Attempting MQTT connection…");
		String clientId = "ESP8266Client";

		if (client->connect(clientId.c_str(), mqtt_user, mqtt_password))
		{
			Serial.println("connected");
			// client->publish(topic, "greeting"); //? for future implementation
			for (auto t : topics)
			{
				client->subscribe(t);
				Serial.print("subscribed to topic: ");
				Serial.println(t);
			}
		}
		else
		{
			Serial.print("failed, rc = ");
			Serial.print(client->state());
			Serial.println(" try again in 5 seconds");
			delay(5000);
		}
	}
}

void keepalive(int value)
{
	const char *local_topic = "keepalive";
	snprintf(msg, MSG_BUFFER_SIZE, "%d", value);

	// Serial.print("Publish ");
	// Serial.print(local_topic);
	// Serial.print(": ");
	// Serial.println(msg);

	client->publish(local_topic, msg);
}

void mqtt_setup()
{
	noInterrupts();
	LittleFS.begin();
	connectWIFI();
	setDateTime();

	// insecure mode to avoid certificates
	// espclient->setInsecure();

	int numCerts = certStore.initCertStore(LittleFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
	Serial.printf("Number of CA certs read: %d\n", numCerts);
	if (numCerts == 0)
	{
		Serial.printf("No certs found. Did you run certs-from-mozilla.py and upload the LittleFS directory before running?\n");
		return;
	}

	BearSSL::WiFiClientSecure *bear = new BearSSL::WiFiClientSecure();
	// integrate the cert store
	bear->setCertStore(&certStore);

	client = new PubSubClient(*bear);

	client->setServer(mqtt_server, 8883);
	client->setCallback(callback);
	Serial.println("[SETUP] MQTT: DONE");
	interrupts();
}

void mqtt_loop()
{
	noInterrupts();
	if (!client->connected())
	{
		mqttServerDisconnected();
		reconnect();
	}
	client->loop();

	unsigned long now = millis();
	if (now - lastMsg > update_interval)
	{
		lastMsg = now;
		++value;

		publish_temperature(client, msg, MSG_BUFFER_SIZE);
		keepalive(value);
	}
	interrupts();
}
