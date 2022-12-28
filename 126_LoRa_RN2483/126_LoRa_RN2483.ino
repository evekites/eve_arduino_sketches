//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <rn2xx3.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

rn2xx3 myLora(mySerial);

const int LED_PIN = 13;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(LED_PIN, 1);
  Serial.begin(57600); //serial port to computer
  mySerial.begin(9600); //serial port to radio
  Serial.println("Startup");
  initialize_radio();
  digitalWrite(LED_PIN, 0);
  delay(2000);
}

void initialize_radio()
{
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(100); //wait for the RN2xx3's startup message
  mySerial.flush();
  myLora.autobaud();
  String hweui = myLora.hweui();
  Serial.println(myLora.hweui());
  Serial.println("RN2xx3 firmware version:");
  Serial.println(myLora.sysver());
  Serial.println("Trying to join TTN");
  bool join_result = false;
  const char *devAddr = "260117F3";
  const char *appSKey = "4409B2A0F9955BB676EBF1C9E77372D9";
  const char *nwkSKey = "B661F4353E2C5D13916E933CB91BEF0C";
  join_result = myLora.initABP(devAddr, appSKey, nwkSKey);
  Serial.print("devAddr=");
  Serial.println(devAddr);
}

void loop()
{
  digitalWrite(LED_PIN, 1);
  Serial.println("TXing");
  myLora.tx("AB");
  //byte payload[] = "Hello";
  //myLora.txBytes(payload, sizeof(payload));
  digitalWrite(LED_PIN, 0);
  delay(200);
}
