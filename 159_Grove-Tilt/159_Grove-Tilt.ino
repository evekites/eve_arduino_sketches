int tiltPin = 7;
int LEDPin = 13;

void setup()
{
    pinMode(LEDPin, OUTPUT);
    pinMode(tiltPin, INPUT);
}

void loop()
{

    if (digitalRead(tiltPin)==HIGH)
    {
        digitalWrite(LEDPin, HIGH);
        delay(200);
        digitalWrite(LEDPin, LOW);
    }

}
