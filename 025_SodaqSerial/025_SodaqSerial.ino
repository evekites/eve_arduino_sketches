//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define Serial SerialUSB

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hello, world!");
  delay(1000);
}

