//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Psx.h> 
#define dataPin 8
#define cmndPin 9
#define attPin 11
#define clockPin 10

#define LEDPin 13

Psx Psx;

unsigned int data = 0;

void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  data = Psx.read();
  Serial.println(data);
  if (data & psxR2)
  {
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }
  delay(20);
}

