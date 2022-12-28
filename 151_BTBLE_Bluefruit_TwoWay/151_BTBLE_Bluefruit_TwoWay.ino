//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Arduino.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

#define BUFSIZE                        128
#define VERBOSE_MODE                   true

SoftwareSerial bluefruitSS = SoftwareSerial(10,11);
Adafruit_BluefruitLE_UART ble(bluefruitSS, -1, 9, -1);

void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

void setup(void)
{
  delay(500);
  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit Command <-> Data Mode Example"));
  Serial.print(F("Initialising the Bluefruit LE module: "));
  ble.begin(VERBOSE_MODE); 
  Serial.println( F("OK!") );
  ble.echo(false);
  Serial.println("Requesting Bluefruit info:");
  ble.info();
  ble.verbose(false);  // debug info is a little annoying after this point!
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);
}

void loop(void)
{
  char n, inputs[BUFSIZE+1];
  if (Serial.available())
  {
    n = Serial.readBytes(inputs, BUFSIZE);
    inputs[n] = 0;
    Serial.print("Sending: ");
    Serial.println(inputs);
    ble.print(inputs);
  }
  while ( ble.available() )
  {
    int c = ble.read();
    Serial.print((char)c);
  }
}
