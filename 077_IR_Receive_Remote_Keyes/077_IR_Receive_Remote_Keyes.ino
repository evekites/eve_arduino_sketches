//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define BAUDRATE 9600
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int nobuttons = 21;

String Button_name[17] = 
{
           "Up",     
  "Left",  "OK",    "Right", 
           "Down", 
  "One",   "Two",   "Three", 
  "Four",  "Five",  "Six", 
  "Seven", "Eight", "Nine", 
  "*",     "Zero",  "Hash"
};

long    Button_DEC_code[17] =
{
            16736925, 
  16720605, 16712445, 16761405, 
            16754775, 
  16738455, 16750695, 16756815, 
  16724175, 16718055, 16743045, 
  16716015, 16726215, 16734885, 
  16728765, 16730805, 16732845
};



void setup()
{
  Serial.begin(BAUDRATE);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    int count = results.rawlen;
    int teller = 0;
    boolean notfound = true;
    if (results.decode_type == NEC)
    {
      while (teller < nobuttons && notfound)
      {
        long button = results.value;
        if (button == Button_DEC_code[teller])
        {
          Serial.println(Button_name[teller]);
          notfound = false;
        }
        teller++;
      }
    }
    if (notfound)
    {
      String button = String(results.value, HEX);
      if (button.substring(0, 6) != "ffffff")
      {
        button.toUpperCase();
        Serial.println("Unknown code:\n0x" + button + "\n" + String(results.value) + "\n");
      }
    }
    irrecv.resume(); // Receive the next value
  }
}

