//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int sensorPin = A0;
unsigned int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);     
  Serial.println(sensorValue);
  delay(500);  
}
