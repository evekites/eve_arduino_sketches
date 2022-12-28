 //A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int AUX1_pin=3;
const int GEAR_pin=4;
const int RUDD_pin=5;
const int ELEV_pin=6;
const int AILE_pin=7;
const int THRO_pin=8;

void setup()
{
  Serial.begin(115200);
  pinMode(AUX1_pin, INPUT);
  pinMode(GEAR_pin,INPUT);
  pinMode(RUDD_pin, INPUT);
  pinMode(ELEV_pin,INPUT);
  pinMode(AILE_pin, INPUT);
  pinMode(THRO_pin,INPUT);
}

void read_value(String channel_name, int channel_pin)
{
  int channel_value=pulseIn(channel_pin,HIGH);
  Serial.print(channel_name);
  Serial.print(":"); 
  Serial.print (channel_value);
  Serial.print ("\t");
}

void loop()
{
  read_value("AUX1", AUX1_pin);
  read_value("GEAR", GEAR_pin);
  read_value("RUDD", RUDD_pin);
  read_value("ELEV", ELEV_pin);
  read_value("AILE", AILE_pin);
  read_value("THRO", THRO_pin);
  Serial.println();
}
