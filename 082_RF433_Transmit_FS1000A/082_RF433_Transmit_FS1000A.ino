//A full description of this module (and many others) can be downloaded at: https://eve_arduino

//Transmitter
#include <VirtualWire.h>

void setup()
{
  vw_set_tx_pin(10);
  vw_setup(2000);
  pinMode(13, OUTPUT);
}

void loop()
{
  send("Is there anybody out there?");
  delay(1000);
}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  digitalWrite(13, HIGH);
  vw_wait_tx();
  digitalWrite(13, LOW);
}

