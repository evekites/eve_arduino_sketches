//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int sensorA=A0;
int sensorvalueA;

void setup()

{
  Serial.begin(9600);
}

void loop()
{
  sensorvalueA=analogRead(sensorA);
  if (sensorvalueA > 550)
  {
    Serial.println(sensorvalueA);
    delay(1000);
  }
}

