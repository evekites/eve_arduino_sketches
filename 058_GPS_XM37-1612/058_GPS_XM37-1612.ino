//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;

SoftwareSerial GPSSerial(3, 2);
unsigned long fixtime;
void setup()
{
  Serial.begin(115200);
  GPSSerial.begin(9600);
  delay(1000);
  Serial.println("GPS");
}

void loop()
{
  while (GPSSerial.available() > 0)
  {
    if (gps.encode(GPSSerial.read()))
    {
      displayInfo();
    }
  }
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 4);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 4);
    Serial.print(F(","));
    Serial.print(gps.altitude.meters(),0);
    Serial.print(F(","));
    Serial.print(fixtime);
  }
  else
  {
    Serial.print(F("No Fix yet, pleas wait, "));
    fixtime=millis()/1000.000;
    Serial.print(fixtime);
  }
  Serial.println();
}
