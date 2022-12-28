#include <SoftwareSerial.h>
#include <RHReliableDatagram.h>
#include <RH_RF95.h>
#define CLIENT_ADDRESS 12
#define SERVER_ADDRESS 34

uint8_t outgoingMessage[] = "Hello World!";
uint8_t incommingMessage[RH_RF95_MAX_MESSAGE_LEN];

SoftwareSerial ss(5, 6); //D5
RH_RF95 driver(ss);

RHReliableDatagram manager(driver, CLIENT_ADDRESS);

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
  Serial.println("Sending message.");
  if(manager.sendtoWait(outgoingMessage, sizeof(outgoingMessage), SERVER_ADDRESS))
  {
    uint8_t len = sizeof(incommingMessage);
    uint8_t sourceAddress;
    if(manager.recvfromAckTimeout(incommingMessage, &len, 2000, &sourceAddress))
    {
      Serial.print("  Got reply from address: 0x");
      Serial.print(sourceAddress, HEX);
      Serial.print(": ");
      Serial.println((char*)incommingMessage);
    }
    else
    {
      Serial.println("No reply, is the erver running?");
    }
  }
  else
  {
    Serial.println("sendtoWait failed");  
  }
  delay(2000);
}
