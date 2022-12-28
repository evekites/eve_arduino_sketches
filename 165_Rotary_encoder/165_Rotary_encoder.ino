#define ENCODERPIN_A 2
#define ENCODERPIN_B 3
#define CLEARBUTTON 8

volatile int encoderPos = 0;
int lastReportedPos = 1;
static boolean rotating = false;

boolean A_set = false;
boolean B_set = false;

void setup() {
  pinMode(ENCODERPIN_A, INPUT_PULLUP);
  pinMode(ENCODERPIN_B, INPUT_PULLUP);
  pinMode(CLEARBUTTON, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE);
  attachInterrupt(1, doEncoderB, CHANGE);
  Serial.begin(9600);
}


void loop() {
  rotating = true;
  if (lastReportedPos != encoderPos)
  {
    Serial.print("Index:");
    Serial.println(encoderPos, DEC);
    lastReportedPos = encoderPos;
  }
  if (digitalRead(CLEARBUTTON) == LOW )
  {
    encoderPos = 0;
  }
}

void doEncoderA()
{
  if ( rotating ) delay (1);
  if ( digitalRead(ENCODERPIN_A) != A_set )
  {
    A_set = !A_set;
    if ( A_set && !B_set )
    {
      encoderPos += 1;
    }
    rotating = false;
  }
}

void doEncoderB()
{
  if ( rotating ) delay (1);
  if ( digitalRead(ENCODERPIN_B) != B_set )
  {
    B_set = !B_set;
    if ( B_set && !A_set )
    {
      encoderPos -= 1;
    }
    rotating = false;
  }
}
