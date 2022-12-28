//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  SerialUSB.begin(9600);
}

void loop()
{
  SerialUSB.println("Hello, world!");
  delay(1000);
}

