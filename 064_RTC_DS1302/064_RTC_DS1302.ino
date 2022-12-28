//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <DS1302.h>

const int RSTPin = 9;
const int DATPin = 8;
const int CLKPin = 7;

DS1302 rtc(RSTPin, DATPin, CLKPin);

String dayName[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void printTime()
{
  Time t = rtc.time();
  String tString = String(dayName[t.day - 1]) + " " + String(t.yr)
                   + "-" + String(t.mon) + "-" + String(t.date) + " "
                   + String(t.hr) + ":" + String(t.min) + ":" + String(t.sec);
  Serial.println(tString);
}

void setClockOnce() //Call this routine to change the clock
{
  Time t(2019, 12, 8, 17, 54,  30, Time::kSunday);
  rtc.time(t);
}

void setup()
{
  Serial.begin(9600);
  rtc.writeProtect(false);
  rtc.halt(false);
  //setClockOnce();
}

void loop()
{
  printTime();
  delay(1000);
}
