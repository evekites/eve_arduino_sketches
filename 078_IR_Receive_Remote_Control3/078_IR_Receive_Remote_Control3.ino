//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define BAUDRATE 9600
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int nobuttons = 21;

String Button_name[21] = 
{
  "Power", "Vol+", "Func/Stop", 
  "Rwd", "Play", "FF", 
  "Down", "Vol-", "Up", 
  "Zero", "EQ", "St/Rept", 
  "One", "Two", "Three", 
  "Four", "Five", "Six", 
  "Seven", "Eight", "Nine"
};

long    Button_DEC_code[21] =
{
  16580863, 16613503, 16597183,
  16589023, 16621663, 16605343,
  16584943, 16617583, 16601263,
  16593103, 16625743, 16609423,
  16582903, 16615543, 16599223,
  16591063, 16623703, 16607383,
  16586983, 16619623, 16603303
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

