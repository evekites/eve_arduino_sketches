//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello world, this is:");
}

void loop()
{
  Serial.println("Arduino");
  delay(500);
}
