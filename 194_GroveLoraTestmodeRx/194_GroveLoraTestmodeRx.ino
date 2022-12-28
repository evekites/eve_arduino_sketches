#include <SoftwareSerial.h>
SoftwareSerial lora_wio_e5(5, 6);

static char recv_buf[512];
static int led = 13;
int counter = 0;

static int at_send_check_response(char *p_ack, int timeout_ms, char *p_cmd, ...) {
  digitalWrite(led, HIGH);
  int ch;
  int num = 0;
  int index = 0;
  int startMillis = 0;
  va_list args;
  memset(recv_buf, 0, sizeof(recv_buf));
  va_start(args, p_cmd);
  lora_wio_e5.print(p_cmd);
  Serial.print(p_cmd);
  va_end(args);
  delay(200);
  startMillis = millis();
  if (p_ack == NULL) {
    Serial.println("Receive failed: No return value?");
    Serial.println();
    blink(1);
    return 0;
  } else {
    do {
      while (lora_wio_e5.available() > 0) {
        ch = lora_wio_e5.read();
        recv_buf[index++] = ch;
        Serial.print((char)ch);
        delay(2);
      }
      if (strstr(recv_buf, p_ack) != NULL) {
        Serial.println("Receive succesful");
        Serial.println();
        blink(2);
        return 1;
      }
    } while (millis() - startMillis < timeout_ms);
  }
  Serial.println("Receive failed: Time out?");
  Serial.println();
  blink(1);
  return 0;
}

void blink(int blinkcounter) {
  digitalWrite(led, LOW);
  delay(300);
  for (int i = 0; i < blinkcounter; i++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}

void setup() {
  Serial.begin(9600);
  lora_wio_e5.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  at_send_check_response("+AT: OK", 1000, "AT\r\n");
  Serial.println("Configuration:");
  at_send_check_response("+MODE: TEST", 1000, "AT+MODE=TEST\r\n");
  if (!at_send_check_response("+TEST: RXLRPKT", 5000, "AT+TEST=RXLRPKT\r\n"))
  {
    while (true) {
      blink(1);
    }
  }
  blink(4);
  delay(200);
}

void loop(void) {
  int ret = at_send_check_response("+TEST: RX", 1000, "");
  delay(5000);
}
