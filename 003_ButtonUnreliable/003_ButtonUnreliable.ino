//A full description of this module (and many others) can be downloaded at: https://eve_arduino

/* No Pullup, unreliable!!!!!! */
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT); 
}

void loop(){
  int Buttonstate = digitalRead(2);
  if (Buttonstate == HIGH) //When button is pressed, buttonstate == HIGH! 
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}

