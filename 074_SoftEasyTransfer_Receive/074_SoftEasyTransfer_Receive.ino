//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
SoftEasyTransfer ET;

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
  pinMode(13, OUTPUT);
}

void loop() 
{
  
  if (ET.receiveData())
  {
    Serial.println(mydata.text);
  } 
  delay(250);
}
