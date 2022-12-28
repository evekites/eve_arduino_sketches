//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(6, 5);

void setup ()
{
    Serial.begin(9600); 
}

void loop ()
{
    
    Serial.println(int(distanceSensor.measureDistanceCm()));
    delay(500);
}

