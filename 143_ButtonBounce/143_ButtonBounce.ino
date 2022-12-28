const int buttonPin = 12;
const int ledPin =  13;
int buttonState = 0;
int count=0;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);     
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {         
    digitalWrite(ledPin, HIGH);  
  } 
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println(count++); 
  }
}
