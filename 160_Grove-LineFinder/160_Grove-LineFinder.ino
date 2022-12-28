//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int signalPin =  3;

void setup()
{
  pinMode(signalPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (HIGH == digitalRead(signalPin))
  {
    Serial.println("black");
  }
  else
  {
    Serial.println("white");
  }
  delay(1000);                  // wait for a second
}
