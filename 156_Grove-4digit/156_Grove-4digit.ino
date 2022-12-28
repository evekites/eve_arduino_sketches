#include "TM1637.h"
#define CLK 2
#define DIO 3
TM1637 tm1637(CLK, DIO);

void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
}

void loop()
{
  for (int count = 9999; count >= 0; count--)
  {
    tm1637.display(3, count / 1 % 10);
    tm1637.display(2, count / 10 % 10);
    tm1637.display(1, count / 100 % 10);
    tm1637.display(0, count / 1000 % 10);
    delay(10);
  }
  while (true);
  {
  }
}
