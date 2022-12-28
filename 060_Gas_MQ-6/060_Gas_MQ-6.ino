//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int sensorValue;
int GasSensorPin = 4;
void setup()
{
 Serial.begin(9600);
}
void loop()
{
 sensorValue = analogRead(GasSensorPin);
 Serial.println(sensorValue, DEC);
 delay(100);
}

