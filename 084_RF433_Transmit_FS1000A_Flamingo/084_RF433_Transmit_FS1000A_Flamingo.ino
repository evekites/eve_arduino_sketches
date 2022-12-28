//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <NewRemoteTransmitter.h>
NewRemoteTransmitter transmitter(12345678, 10, 268);

void setup() 
{
}

void loop()
{
  transmitter.sendUnit(1, true);
  delay(1000);
  transmitter.sendUnit(1, false);
  delay(1000);
}

