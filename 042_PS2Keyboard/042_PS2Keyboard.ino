//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <PS2Keyboard.h>
const int DataPin = 7;
const int IRQpin =  2;

PS2Keyboard keyboard;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
}

void loop() {
  if (keyboard.available())
  {
    char c = keyboard.read();
    if (c == PS2_ENTER)
    {
      Serial.println();
    }
    else if (c == PS2_TAB)
    {
      Serial.print("[Tab]");
    }
    else if (c == PS2_ESC)
    {
      Serial.print("[ESC]");
    }
    else if (c == PS2_PAGEDOWN)
    {
      Serial.print("[PgDn]");
    }
    else if (c == PS2_PAGEUP)
    {
      Serial.print("[PgUp]");
    }
    else if (c == PS2_LEFTARROW)
    {
      Serial.print("[Left]");
    }
    else if (c == PS2_RIGHTARROW)
    {
      Serial.print("[Right]");
    }
    else if (c == PS2_UPARROW)
    {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW)
    {
      Serial.print("[Down]");
    }
    else if (c == PS2_DELETE)
    {
      Serial.print("[Del]");
    }
    else
    {
      Serial.print(c);
    }
  }
}

