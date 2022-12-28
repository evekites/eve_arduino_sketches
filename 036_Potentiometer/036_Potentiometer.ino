//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int analogInPin = A0;
const int LED = 9;

int sensorValue = 0;
int outputValue = 0;

void setup()
{
}

void loop()
{
  sensorValue = analogRead(analogInPin);            
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  analogWrite(LED, outputValue);           
  delay(2);                     
}

