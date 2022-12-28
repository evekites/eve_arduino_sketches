//A full description of this module (and many others) can be downloaded at: https://eve_arduino

float tempC;
int reading;
int tempPin = 0;

void setup()
{
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop()
{
  reading = analogRead(tempPin);
  tempC=reading/(10.0/(1100/1024));
  Serial.println(tempC);
  delay(500);
}

