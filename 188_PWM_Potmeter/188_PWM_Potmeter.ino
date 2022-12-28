#define PWM_LED 3
#define POTMETER A0
#define SIGNAL_LED 13

/*
   Bitscope micro

   DSO  (Scope) settings):

   SCOPE
   CURSOR
   GRID

   Trigger: CHA, RISE

   REPEAT TRACE
   20 us/Div

   CHA
   5.2V   MAX
   2V/Div

   OSCILOSCOPE
   400 us   20MHz
   NORMAL   SMOOTH
   RECORDER off WIDE BAND
*/

void setup() {
  pinMode(PWM_LED, 155);
  pinMode(SIGNAL_LED, OUTPUT);
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  Serial.begin(9600);
}

int previousBrightness = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int potmeterValue = analogRead(POTMETER);
  int brightness = map (potmeterValue, 0, 1024, 0, 255);
  int brightnessPercentage = map (potmeterValue, 0, 1024, 0, 100);
  if (abs(brightness - previousBrightness) >= 2)
  {
    analogWrite(PWM_LED, brightness);
    Serial.print("PWM value: ");
    Serial.print(brightness);
    Serial.print(", percentage: ");
    Serial.println(brightnessPercentage);
    previousBrightness = brightness;
  }
}
