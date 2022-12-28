//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int CH1_pin=3;
const int CH2_pin=4;
const int CH3_pin=5;
const int CH4_pin=6;
const int CH5_pin=7;
const int CH6_pin=8;
const int CH7_pin=9;

void setup()
{
  Serial.begin(115200);
  pinMode(CH1_pin, INPUT);
  pinMode(CH2_pin, INPUT);
  pinMode(CH3_pin, INPUT);
  pinMode(CH4_pin, INPUT);
  pinMode(CH5_pin, INPUT);
  pinMode(CH6_pin, INPUT);
  pinMode(CH7_pin, INPUT);
}

void read_value(String channel_name, int channel_pin)
{
  int channel_value=pulseIn(channel_pin,HIGH);
  Serial.print(channel_name);
  Serial.print(":"); 
  Serial.print (channel_value);
  Serial.print (" | ");
}

void loop()
{
  read_value("CH1", CH1_pin);
  read_value("CH2", CH2_pin);
  read_value("CH3", CH3_pin);
  read_value("CH4", CH4_pin);
  read_value("CH5", CH5_pin);
  read_value("CH6", CH6_pin);
  read_value("CH7", CH7_pin);
  Serial.println();
}

