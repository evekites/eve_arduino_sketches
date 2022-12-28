//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftwareSerial.h>
#include <stdlib.h>
#define SSID "wifi-zolder"
#define PASS "ikh0uvanv33lk03kj3s!"
#define IP "184.106.153.149" // ThingSpeak IP Address: 184.106.153.149

int lm35Pin = A0;
int aantal = 1;
String apiKey = "TPKHOTNNANSUII54";

SoftwareSerial ser(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  ser.begin(115200);
  ser.println("AT+RST");
  Serial.println("AT+RST");
  while (!connectWiFi())
  {
    Serial.println("No WiFi connection, retrying");
    delay(2000);
  }
}

boolean connectWiFi()
{
  ser.println("AT+CWMODE=1");
  Serial.println("AT+CWMODE=1");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  ser.println(cmd);
  Serial.println(cmd);
  delay(7000);
  if (ser.find("OK"))
  {
    Serial.println("verbinding");
    return true;
  }
  else
  {
    Serial.println("Geen verbinding");
    return false;
  }
}

void loop()
{
  int val = 0;
  for (int i = 0; i < 10; i++)
  {
    val += analogRead(lm35Pin);
    delay(500);
  }
  float temp = val * 50.0f / 1023.0f;
  char buf[16];
  String strTemp = dtostrf(temp, 4, 1, buf);
  Serial.println(strTemp);
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149";
  cmd += "\",80";
  ser.println(cmd);
  if (ser.find("Error"))
  {
    Serial.println("AT+CIPSTART error");
    return;
  }
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr += "&temperature=";
  getStr += String(strTemp);
  getStr += "\r\n\r\n";
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length() - 2);
  ser.println(cmd);
  if (ser.find(">"))
  {
    ser.print(getStr);
    Serial.println(aantal++);
  }
  else
  {
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  delay(16000);
}
