//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int Button= 2;
const int Led =  13;

int Buttonstate = 0;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(Button, INPUT);  // when using external Pullup/Pulldown resistor
}

void loop(){
  Buttonstate = digitalRead(Button);

  if (Buttonstate == HIGH) 
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}

