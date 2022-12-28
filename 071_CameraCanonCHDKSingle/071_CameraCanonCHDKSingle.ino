//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int LED=13;
int CHDKport=9;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(CHDKport, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready to take pictures");
}

void loop()
{
  delay(10000);
  Serial.println("shoot");
  digitalWrite(LED, HIGH);
  digitalWrite(CHDKport, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  digitalWrite(CHDKport, LOW);
}

