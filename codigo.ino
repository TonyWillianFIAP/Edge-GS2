#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <uri/UriBraces.h>
#include "ArduinoJson.h"
#include "EspMQTTClient.h"
#include <SD.h>
 
// MQTT Configuracoes
EspMQTTClient client{
  "Wokwi-GUEST", //SSID do WiFi
  "",     // Senha do wifi
  "mqtt.tago.io",  // Endereço do servidor
  "",       // Usuario
  "34e42be8-83e3-496f-a2a8-eb7a0f21fb93",         // Token do device
  "Receptor sd-card",           // Nome do device
  1883             // Porta de comunicação
};
 
WebServer server(80);
 
#define CS_PIN 2
File root;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Conectando WiFi");
  while (!client.isWifiConnected()) {
    Serial.print('.'); client.loop(); delay(1000);
  }
  Serial.println("WiFi Conectado");
  Serial.println("Conectando com Servidor MQTT");
  while (!client.isMqttConnected()) {
    Serial.print('.'); client.loop(); delay(1000);
  }
  Serial.println("MQTT Conectado");
 
  Serial.print("Initializing SD card... ");
 
  if (!SD.begin(CS_PIN)) {
    Serial.println("Card initialization failed!");
    while (true);
  }
 
  Serial.println("initialization done.");
 
  Serial.println("Files in the card:");
  root = SD.open("/");
  printDirectory(root, 0);
  Serial.println("");
}
 
void onConnectionEstablished() {
  server.handleClient();
  client.loop();
}
 
void loop() {
    // Example of reading file from the card:
  File textFile = SD.open("/wokwi.txt");
  if (textFile) {
    Serial.print("wokwi.txt: ");
    while (textFile.available()) {
      Serial.write(textFile.read());
    }
    textFile.close();
  } else {
    Serial.println("error opening wokwi.txt!");
  }
}
 
void printDirectory(File dir, int numTabs) {
  while (true) {
 
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}