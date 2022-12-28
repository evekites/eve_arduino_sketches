//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  Serial.begin(115200);
  pinMode(3, INPUT);
}

void loop()
{
  Serial.println(pulseIn(3, LOW));
}
