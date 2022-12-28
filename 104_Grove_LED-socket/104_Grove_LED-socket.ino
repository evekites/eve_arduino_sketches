//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int led = 2 ;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop()
{
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

