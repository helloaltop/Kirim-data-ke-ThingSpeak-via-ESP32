#include <WiFi.h>
#include "ThingSpeak.h"

unsigned long myChannelNumber = 1;
const char myWriteAPIKey = "P3IPVWCSRD332ESU";
WiFiClient client;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to WiFi");
  WiFi.begin("Wokwi-GUEST", "", 6);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  ThingSpeak.begin(client);
}

void loop() {
  int x = ThingSpeak.writeField(myChannelNumber, 1, random(1,100), myWriteAPIKey);
  if(x == 200){
  Serial.println("Channel update successful.");
  }
  else{
  Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(30000); // TODO: Build something amazing!
}
