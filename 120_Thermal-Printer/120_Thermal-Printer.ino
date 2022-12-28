//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&mySerial);

void setup()
{
  mySerial.begin(19200);
  printer.begin();
  printer.justify('L');
  printer.println(F("Hello"));
  printer.justify('C');
  printer.println(F("World"));

  printer.sleep();
  delay(3000);
  printer.wake();
  printer.setDefault();
}

void loop()
{
}

