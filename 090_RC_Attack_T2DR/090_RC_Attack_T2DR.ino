//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int ch1_pin=3;
const int ch2_pin=4;

int ch1_value;
int ch2_value;

void setup() {
  Serial.begin(115200);
  pinMode(ch1_pin, INPUT);
  pinMode(ch2_pin,INPUT);
}

void loop() {
  ch1_value = pulseIn (ch1_pin,HIGH);
  Serial.print ("Ch1:");
  Serial.print (ch1_value);
  Serial.print (" | ");
 
  ch2_value = pulseIn (ch2_pin,HIGH);
  Serial.print ("Ch2:");
  Serial.print (ch2_value);
  Serial.println ();
}
