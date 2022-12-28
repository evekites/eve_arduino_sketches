//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int JoyX = A0;
const int JoyY = A1;
const int JoyS = 5;

int sensorY;
int sensorX;
int Switch=9;

void setup()
{
  Serial.begin(9600);
  pinMode(5, INPUT_PULLUP);
}

void loop()
{
  sensorX = analogRead(JoyX);
  sensorY = analogRead(JoyY);
  Switch = digitalRead(JoyS);
  Serial.print("X: ");
  Serial.print(sensorX);
  Serial.print(" Y: ");
  Serial.print(sensorY);
  Serial.print(" S: ");
  Serial.println(Switch);
}

