//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  Serial.begin(9600);  
}

void loop() 
{
  int ChannelA = map(analogRead(A0),0,1023,0,1);
  int ChannelB = map(analogRead(A1),0,1023,0,1);
  int ChannelC = map(analogRead(A2),0,1023,0,1);
  int ChannelD = map(analogRead(A3),0,1023,0,1);
  Serial.print(ChannelA, DEC);
  Serial.print(";");
  Serial.print(ChannelB, DEC);
  Serial.print(";");
  Serial.print(ChannelC, DEC);
  Serial.print(";");
  Serial.println(ChannelD, DEC);
}

