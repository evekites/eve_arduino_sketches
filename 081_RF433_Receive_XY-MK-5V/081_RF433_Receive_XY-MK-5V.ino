//A full description of this module (and many others) can be downloaded at: https://eve_arduino

//Receiver
#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Device is ready");
  vw_set_rx_pin(11);
  vw_setup(2000);
  vw_rx_start();
}

void loop()
{
  if (vw_get_message(message, &messageLength))
  {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();
  }
}

