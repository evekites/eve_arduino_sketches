//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int LED = 13;
int USB_Power_Out = 9;

void setup() 
{    
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(USB_Power_Out, OUTPUT);     
  digitalWrite(USB_Power_Out, LOW);
  Serial.begin(9600);
  Serial.println("Camera Controller Started");
}

void pulse(int duration) 
{
  digitalWrite(LED, HIGH);
  Serial.print("Send a ");
  Serial.print(duration);
  Serial.println(" ms pulse");
  digitalWrite(USB_Power_Out, HIGH);
  delay(duration);
  digitalWrite(USB_Power_Out, LOW);
  delay(55);
  digitalWrite(LED, LOW);
  delay(10000);
}

void loop() 
{
  pulse(20);
  pulse(50);
  pulse(80);
  pulse(110);
  pulse(140);
  pulse(170);
}

