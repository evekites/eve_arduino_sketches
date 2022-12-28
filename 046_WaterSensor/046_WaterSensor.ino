//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int analogPin = A0;
int led = 13;
int val = 0;
int data = 0;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(analogPin);
  if (val > 600)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  Serial.println(val);
  delay(100);
}

