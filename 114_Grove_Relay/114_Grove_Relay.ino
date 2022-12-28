//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int Relaypin = 2 ;

void setup() 
{                
  pinMode(Relaypin, OUTPUT);     
}

void loop()
{
  digitalWrite(Relaypin, HIGH);
  delay(1000);
  digitalWrite(Relaypin, LOW);
  delay(1000);
}

