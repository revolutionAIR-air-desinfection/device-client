#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>

// #include "../credentials/credentials.h"
#include "../WiFi/connectWIFI.h"

// #include "../WiFi/ClientHandler.h"

const int update_interval = 2000;

BearSSL::CertStore certStore;
WiFiClientSecure espClient;
PubSubClient *client;
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// TODO: move to /WIFI/connectWifi.h
// connect to wifi
// void setup_wifi()
// {
//   delay(10);
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }

//   randomSeed(micros());

//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// required for CA certificates
void setDateTime()
{
  // Only the date is needed for validating the certificates.
  configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");

  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2)
  {
    delay(100);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println();

  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.printf("%s %s", tzname[0], asctime(&timeinfo));
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message = "";
  for (int i = 0; i < length; i++)
  {
    message = message + (char)payload[i];
  }
  Serial.println(message);

  handleCommand(topic, message);
}

void reconnect()
{
  // Loop until reconnected
  while (!client->connected())
  {
    Serial.print("Attempting MQTT connection…");
    String clientId = "ESP8266Client - MyClient";

    if (client->connect(clientId.c_str(), mqtt_user, mqtt_password))
    {
      Serial.println("connected");
      // client->publish(topic, "greeting");
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

int getTemperature(int value) // TODO: remove value
{
  //! TODO: get temperature value
  return value; // TODO: replace value with actual value
}

void publish_temperature(int value) // TODO: remove value
{
  const char *local_topic = "temperature";
  snprintf(msg, MSG_BUFFER_SIZE, "%ld", getTemperature(value)); // TODO: remove value

  Serial.print("Publish ");
  Serial.print(local_topic);
  Serial.print(": ");

  Serial.println(msg);
  client->publish(local_topic, msg);
}

void keepalive(int value)
{
  const char *local_topic = "keepalive";
  snprintf(msg, MSG_BUFFER_SIZE, "%ld", getTemperature(value)); // TODO: remove value

  Serial.print("Publish ");
  Serial.print(local_topic);
  Serial.print(": ");

  Serial.println(msg);
  client->publish(local_topic, msg);
}

void mqtt_setup()
{
  delay(500);
  Serial.begin(9600);
  delay(500);

  LittleFS.begin();
  connectWIFI();
  setDateTime();

  // insecure mode to avoid certificates (should not be allowed with hiveMQ)
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
}

void mqtt_loop()
{
  if (!client->connected())
  {
    reconnect();
  }
  client->loop();

  unsigned long now = millis();
  if (now - lastMsg > update_interval)
  {
    lastMsg = now;
    ++value;

    publish_temperature(22); // TODO: remove value
    keepalive(value);
  }
}
