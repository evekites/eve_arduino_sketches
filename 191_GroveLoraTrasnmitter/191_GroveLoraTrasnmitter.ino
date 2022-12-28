#include <ArduinoJson.h>
#include<SoftwareSerial.h>

SoftwareSerial e5(5, 6);

static char recv_buf[512];
static int led = 13;
int counter = 0;
static int at_send_check_response(char *p_ack, int timeout_ms, char *p_cmd, ...)
{
    int ch;
    int num = 0;
    int index = 0;
    int startMillis = 0;
    va_list args;
    memset(recv_buf, 0, sizeof(recv_buf));
    va_start(args, p_cmd);
    e5.print(p_cmd);
    Serial.print(p_cmd);
    va_end(args);
    delay(200);
    startMillis = millis();
 
    if (p_ack == NULL)
        return 0;
 
    do
    {
        while (e5.available() > 0)
        {
            ch = e5.read();
            recv_buf[index++] = ch;
            Serial.print((char)ch);
            delay(2);
        }
 
        if (strstr(recv_buf, p_ack) != NULL)
            return 1;
 
    } while (millis() - startMillis < timeout_ms);
    Serial.println();
    return 0;
}
 
void setup(void)
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    e5.begin(9600);
    Serial.print("E5 LOCAL TEST\r\n");
    at_send_check_response("+AT: OK", 100, "AT\r\n");
    at_send_check_response("+MODE: TEST", 1000, "AT+MODE=TEST\r\n");
    delay(200);
    digitalWrite(led, HIGH);
}
 
void loop(void)
{
      char cmd[128];
      counter=counter+1;

      // Transmit HEX Value
      sprintf(cmd, "AT+TEST=TXLRPKT,\"%d\"\r\n", counter);
      int ret = at_send_check_response("+TEST: TXLRPKT", 5000, cmd);
      
      if (ret)
        Serial.println("Sent");
      else
        Serial.println("Send failed!\r\n\r\n");
      delay(5000);
      
}
