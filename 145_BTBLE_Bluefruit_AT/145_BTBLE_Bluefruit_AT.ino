//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Arduino.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

#define BUFSIZE                        160
#define VERBOSE_MODE                   true //otherwise you won't see the result of the AT commands

SoftwareSerial bluefruitSS = SoftwareSerial(10,11);
Adafruit_BluefruitLE_UART ble(bluefruitSS, -1, 9, -1);

void setup(void)
{
  delay(500);
  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit AT Command Example"));
  Serial.print(F("Initialising the Bluefruit LE module: "));
  ble.begin(VERBOSE_MODE); 
  Serial.println( F("OK!") );
  ble.echo(false);
  Serial.println("Requesting Bluefruit info:");
  ble.info();
}

void loop(void)
{
  char command[BUFSIZE+1];
  getUserInput(command, BUFSIZE);
  ble.println(command);
  ble.waitForOK();
}

void getUserInput(char buffer[], uint8_t maxSize)
{
  memset(buffer, 0, maxSize);
  while( Serial.available() == 0 ) {
    delay(1);
  }
  uint8_t count=0;
  do
  {
    count += Serial.readBytes(buffer+count, maxSize);
    delay(2);
  } while( (count < maxSize) && !(Serial.available() == 0) );
}
