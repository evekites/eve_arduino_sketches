//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <IRremote.h>

IRsend irsend; //Connect IR LED to D3!!

long    Button_DEC_code[4] =
{
  16736925, 16720605, 16761405, 16754775
};

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
    int sensorx=map(analogRead(A0), 0, 1023, -100, 100);
    if (sensorx>=-5 && sensorx<=5)
    {
      sensorx=0;
    }
    int sensory=map(analogRead(A1), 0, 1023, -100, 100);
    if (sensory>=-5 && sensory<=5)
    {
      sensory=0;
    }
    Serial.print(sensorx, DEC);
    Serial.print(", ");
    Serial.println(sensory, DEC);
    if (sensorx>0) irsend.sendNEC(Button_DEC_code[2], 32); //UP
    if (sensorx<0) irsend.sendNEC(Button_DEC_code[1], 32); //DOWN
    if (sensory>0) irsend.sendNEC(Button_DEC_code[0], 32); //RIGHT
    if (sensory<0) irsend.sendNEC(Button_DEC_code[3], 32); //LEFT
    delay(100);
}

