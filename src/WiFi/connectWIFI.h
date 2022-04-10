#include <ESP8266WiFi.h>

#include "../LED/effects/pulseWarning.h"
#include "../credentials/credentials.h"
#include "../WiFi/ClientHandler.h"

WiFiServer wifiServer(1080);

void connectWIFI()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    WifiNotConnected(); // pulseWarning
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// void clientLoop()
// {
//     WiFiClient client = wifiServer.available();

//     if (client)
//     {

//         while (client.connected())
//         {

//             String command = "";
//             while (client.available() > 0)
//             {
//                 char c = client.read();
//                 command += c;
//                 // client.write(c); // echo bounce back to client
//             }
//             if (!command.isEmpty())
//             {
//                 // Serial.print(command);
//                 handleCommand(command);
//             }
            
//             Blue();

//             delay(10);
//         }

//         client.stop();
//         Serial.println("Client disconnected");
//     }
// }
