#include <SoftwareSerial.h>
#include <RHReliableDatagram.h>
#include <RH_RF95.h>
#define CLIENT_ADDRESS 12
#define SERVER_ADDRESS 34

uint8_t replyMessage[] = "And hello back to you";
uint8_t incommingMessage[RH_RF95_MAX_MESSAGE_LEN];

SoftwareSerial ss(5, 6);  //D5
RH_RF95 driver(ss);

RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup() 
{
  Serial.begin(9600);
  if (!manager.init())
  {
    Serial.println("init failed");
  }
}

void loop()
{
  if(manager.available())
  {
    uint8_t len = sizeof(incommingMessage);
    uint8_t sourceAddress;
    if(manager.recvfromAck(incommingMessage, &len, &sourceAddress))
    {
      Serial.print("Got message from address: 0x");
      Serial.print(sourceAddress, HEX);
      Serial.print(": ");
      Serial.println((char*)incommingMessage);
      if(!manager.sendtoWait(replyMessage, sizeof(replyMessage), sourceAddress))
      {
        Serial.println("sendtoWait failed");
      }
    }
  }
}
