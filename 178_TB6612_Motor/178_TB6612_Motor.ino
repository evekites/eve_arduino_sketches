//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int MotorA=5;
int MotorA_CCW=2;
int MotorA_CW=3;

int Motorspeed=255;

void setup()
{
 pinMode(MotorA,OUTPUT);
 pinMode(MotorA_CW,OUTPUT);
 pinMode(MotorA_CCW,OUTPUT);
}

void loop()
{
  digitalWrite(MotorA_CW,LOW); 
  digitalWrite(MotorA_CCW,HIGH);
  analogWrite(MotorA, Motorspeed);
  delay(2000);
  digitalWrite(MotorA_CW,HIGH); 
  digitalWrite(MotorA_CCW,LOW);
  analogWrite(MotorA, Motorspeed);
  delay(2000);
}
