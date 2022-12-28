//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
SoftEasyTransfer ET; 

struct SEND_DATA_STRUCTURE{
  char text[32];
};
int counter=0;

SEND_DATA_STRUCTURE mydata;

void setup()
{
  mySerial.begin(9600);
  ET.begin(details(mydata), &mySerial);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  String sendString=String(counter++);
  sendString.toCharArray(mydata.text,sendString.length()+1);
  ET.sendData();
  delay(2000);
}
 
