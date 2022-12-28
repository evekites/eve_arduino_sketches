//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
SoftEasyTransfer ET;
String send_string = "Blue";
const long interval = 4000;
unsigned long previousMillis = 0;


struct RECEIVE_DATA_STRUCTURE
{
  char text[32];
};

RECEIVE_DATA_STRUCTURE mydata;

void setup()
{
  mySerial.begin(9600);
  ET.begin(details(mydata), &mySerial);
  Serial.begin(9600);
  send_string.toCharArray(mydata.text, send_string.length() + 1);
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    ET.sendData();
    Serial.print("Sent: ");
    Serial.println(send_string);
    previousMillis = currentMillis;
  }
  if (ET.receiveData()) {
    Serial.print("Received: ");
    Serial.println(mydata.text);
  }
   
}
