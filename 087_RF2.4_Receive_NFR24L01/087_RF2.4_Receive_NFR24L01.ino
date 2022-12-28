//A full description of this module (and many others) can be downloaded at: https://eve_arduino

//Receiver
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
  Serial.println("ROLE: Receiver");
  radio.begin();
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  radio.openWritingPipe(address[1]);
  radio.openReadingPipe(1, address[0]);
  radio.startListening();
  radio.writeAckPayload( 1, &message_count, sizeof(message_count) );
  ++message_count;
  radio.printDetails();
  delay(50);
  attachInterrupt(0, check_radio, LOW);
}

void loop()
{
}

void check_radio(void)
{
  bool tx, fail, rx;
  radio.whatHappened(tx, fail, rx);
  if ( tx )
  {
    Serial.println("Ack Payload:Sent");
  }

  if ( fail )
  {
    Serial.println("Ack Payload:Failed");
  }

  if ( rx || radio.available())
  {
    static unsigned long got_time;
    radio.read( &got_time, sizeof(got_time) );
    Serial.print("Got payload ");
    Serial.println(got_time);
    radio.writeAckPayload( 1, &message_count, sizeof(message_count) );
    ++message_count;
  }
}

