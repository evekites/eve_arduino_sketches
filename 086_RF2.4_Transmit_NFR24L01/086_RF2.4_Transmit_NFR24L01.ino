//A full description of this module (and many others) can be downloaded at: https://eve_arduino

//Transmitter
#include <SPI.h>
#include "RF24.h"
#include "printf.h"

RF24 radio(9, 10);

byte address[][5] = { 0xCC, 0xCE, 0xCC, 0xCE, 0xCC , 0xCE, 0xCC, 0xCE, 0xCC, 0xCE};
static uint32_t message_count = 0;

void setup()
{
  Serial.begin(115200);
  printf_begin();
  Serial.print("RF24/examples/pingpair_irq");
  Serial.println("ROLE: Transmitter");
  radio.begin();
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1, address[1]);
  radio.printDetails();
  delay(50);
  attachInterrupt(0, check_radio, LOW);
}


void loop()
{
  unsigned long time = millis();
  Serial.print("Now sending ");
  Serial.println(time);
  radio.startWrite( &time, sizeof(unsigned long) , 0);
  delay(2000);
}

void check_radio(void)
{
  bool tx, fail, rx;
  radio.whatHappened(tx, fail, rx);
  if ( tx )
  {
    Serial.println("Send:OK");
  }
  if ( fail )
  {
    Serial.println("Send:Failed");
  }
  if ( rx || radio.available())
  {
    radio.read(&message_count, sizeof(message_count));
    Serial.print("Ack: ");
    Serial.println(message_count);
  }
}

