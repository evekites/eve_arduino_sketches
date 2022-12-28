//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int analogInPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(analogInPin);            
  Serial.println(sensorValue);
  delay(200);                     
}

