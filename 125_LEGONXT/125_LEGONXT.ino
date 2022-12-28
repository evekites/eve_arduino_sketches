//A full description of this module (and many others) can be downloaded at: https://eve_arduino
#include <Wire.h>
#include <string.h>

#define ADDRESS 0x43
char readfromnxt;
int LED = 13;
boolean LEDStatus = false;

void setup()
{
  Serial.begin(9600);
  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, !digitalRead(LED));
  delay(3000);
}


//---------------------------------I2C Events-------------------------------//

void receiveEvent(int howMany)
{
  if (Wire.available() > 0 ) //&& index <15)
  {
    readfromnxt = Wire.read(); // receive byte as an integer
  }
}

void requestEvent()
{
  if (readfromnxt == 0x42)
  {
    if (digitalRead(LED))
    {
      Wire.write("LED is ON ", 15);
    }
    else
    {
      Wire.write("LED is OFF", 15);
    }
  }
}
