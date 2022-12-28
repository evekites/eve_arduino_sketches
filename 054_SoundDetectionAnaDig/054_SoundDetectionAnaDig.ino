//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int sensorA=A0;
int sensorD=9;
int sensorvalueD;
int sensorvalueA;

void setup()

{
  pinMode(sensorD, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorvalueD=digitalRead(sensorD);
  sensorvalueA=analogRead(sensorA);
  if (sensorvalueD == HIGH)
  {
    Serial.print("Yes I heard you at level: ");
    Serial.println(sensorvalueA);
    delay(1000);
  }
}

