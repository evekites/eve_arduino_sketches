//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int Led=13;
int ProxIR=10;
int val;
void setup()

{
  pinMode(Led,OUTPUT);
  pinMode(ProxIR,INPUT);//
}

void loop()
{
  val=digitalRead(ProxIR);
  if(val==HIGH)
  {
    digitalWrite(Led,LOW);
  }
  else
  {
    digitalWrite(Led,HIGH);
  }
}

