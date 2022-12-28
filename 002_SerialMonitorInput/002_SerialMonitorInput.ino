//A full description of this module (and many others) can be downloaded at: https://eve_arduino

String name;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("What is your name?");
}

void loop() 
{
    if(Serial.available() > 0)
    {
        name = Serial.readStringUntil('\n');
        Serial.print("Welcome ");
        Serial.println(name);
    }
}

