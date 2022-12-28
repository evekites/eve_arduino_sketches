//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int Sensor = 12;
int Led    =  13;

int SensorValue = 0;

void setup()
{
  pinMode(Led, OUTPUT);
  pinMode(Sensor, INPUT);
}

void loop()
{
  SensorValue = digitalRead(Sensor);
  if (SensorValue == HIGH)
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}

