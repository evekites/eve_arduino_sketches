//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  BTSerial.begin(38400);
}

void loop()
{
  BTSerial.println("Hello World");
  delay(1000);
}
