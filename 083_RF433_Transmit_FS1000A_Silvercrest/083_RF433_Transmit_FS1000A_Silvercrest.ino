//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define MAX_CODE_CYCLES   4
#define SHORT_DELAY         380
#define NORMAL_DELAY        500
#define SIGNAL_DELAY      1500
#define SYNC_DELAY        2650
#define EXTRASHORT_DELAY  3000
#define EXTRA_DELAY       10000
#define RF_DATA_PIN       10

const boolean on = true;
const boolean off = false;
unsigned char swap;

enum {
  PLUG_A = 0,
  PLUG_B = 1,
  PLUG_C = 2,
  PLUG_D = 3,
  PLUG_MASTER = 4,
};

unsigned long signals[5][2][MAX_CODE_CYCLES] = {
  { /*A*/
    { /*ON */
      0b111101010010010011010101, 0b111100111011110010010101,
      0b111110101110011111000101, 0b111110111000100001000101
    },
    { /*OFF*/
      0b111111100011111111110101, 0b111100001111001100110101,
      0b111100100000101100000101, 0b111101110100000111100101
    }
  },
  { /*B*/
    { /*ON */
      0b111101000101011000101100, 0b111111110111000001111100,
      0b111100010110111010111100, 0b111111000001001010001100
    },
    { /*OFF*/
      0b111110001100010110101100, 0b111101101010101001101100,
      0b111110011101110100011100, 0b111111011001100101011100
    }
  },
  { /*C*/
    { /*ON */
      0b111110011101110100011110, 0b111101101010101001101110,
      0b111110001100010110101110, 0b111111011001100101011110
    },
    { /*OFF*/
      0b111111110111000001111110, 0b111100010110111010111110,
      0b111111000001001010001110, 0b111101000101011000101110
    }
  },
  { /*D*/
    { /*ON */
      0b111100100000101100000111, 0b111101110100000111100111,
      0b111111100011111111110111, 0b111100001111001100110111
    },
    { /*OFF*/
      0b111101010010010011010111, 0b111100111011110010010111,
      0b111110101110011111000111, 0b111110111000100001000111
    }
  },
  { /*MASTER*/
    { /*ON */
      0b111101101010101001100010, 0b111110011101110100010010,
      0b111111011001100101010010, 0b111110001100010110100010
    },
    { /*OFF*/
      0b111111110111000001110010, 0b111101000101011000100010,
      0b111111000001001010000010, 0b111100010110111010110010
    }
  },
};

void setup() {
  pinMode(RF_DATA_PIN, OUTPUT);
  Serial.begin(9600);
  swap  = 0;
}

void sendSync()
{
  digitalWrite(RF_DATA_PIN, HIGH);
  delayMicroseconds(SHORT_DELAY);
  digitalWrite(RF_DATA_PIN, LOW);
  delayMicroseconds(SYNC_DELAY - SHORT_DELAY);
}

void sendValue(boolean value, unsigned int base_delay)
{
  unsigned long d = value ? SIGNAL_DELAY - base_delay : base_delay;
  digitalWrite(RF_DATA_PIN, HIGH);
  delayMicroseconds(d);
  digitalWrite(RF_DATA_PIN, LOW);
  delayMicroseconds(SIGNAL_DELAY - d);
}

void longSync()
{
  digitalWrite(RF_DATA_PIN, HIGH);
  delayMicroseconds(EXTRASHORT_DELAY);
  digitalWrite(RF_DATA_PIN, LOW);
  delayMicroseconds(EXTRA_DELAY - EXTRASHORT_DELAY);
}

void ActivatePlug(unsigned char PlugNo, boolean PlugStatus)
{
  digitalWrite(RF_DATA_PIN, LOW);
  delayMicroseconds(1000);
  unsigned long signal = signals[PlugNo][PlugStatus][swap];
  swap++;
  swap %= MAX_CODE_CYCLES;
  Serial.print(PlugNo == PLUG_MASTER ? 'M' : (char)('A' + PlugNo));
  Serial.print(" ");
  Serial.println(PlugStatus ? "On" : "Off");
  for (unsigned char i = 0; i < 4; i++)
  {
    sendSync();
    for (unsigned char k = 0; k < 24; k++)
    {
      sendValue(bitRead(signal, 23 - k), SHORT_DELAY);
    }
  }
  for (unsigned char i = 0; i < 4; i++)
  {
    longSync();
    for (unsigned char k = 0; k < 24; k++)
    {
      sendValue(bitRead(signal, 23 - k), NORMAL_DELAY);
    }
  }
}

void loop()
{
  ActivatePlug(PLUG_A, on);
  delay(500);
  ActivatePlug(PLUG_A, off);
  delay(5000);
}

