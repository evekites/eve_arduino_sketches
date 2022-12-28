//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Servo.h> 
Servo myservo;

int pos = 0;

void setup() 
{ 
  myservo.attach(6);
} 
 
 
void loop() 
{ 
  myservo.writeMicroseconds(600);
  delay(2000);
  myservo.writeMicroseconds(1375);
  delay(2000);
  myservo.writeMicroseconds(2150);
  delay(2000);
  myservo.writeMicroseconds(1375);
  delay(2000);
}

