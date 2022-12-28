//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "token";

char ssid[] = "ssid";
char pass[] = "WPA2-key";
BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  Blynk.run();
}
