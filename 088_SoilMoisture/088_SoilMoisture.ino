//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int Dry = 622; //Measured in the air
const int Water = 371; //Measured in a glass of water
int Measurement = 0;
int Result = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Measurement = analogRead(A0);
  Result = map(Measurement, Dry, Water, 0, 100);  
  Serial.println(String(Result) + " % moisture");
  delay(100);
}
