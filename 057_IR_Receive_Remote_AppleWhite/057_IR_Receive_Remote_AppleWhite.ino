//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define BAUDRATE 9600
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int nobuttons = 6;

String Button_name[21] = 
{
                "Vol+", 
  "Previous",   "Play/pause", "Next", 
                "Vol-", 
                
                "Menu"
};

long    Button_DEC_code[21] =
{
              2011287768, 
  2011238616, 2011242712, 2011291864,
              2011279576, 
              
              2011250904
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
