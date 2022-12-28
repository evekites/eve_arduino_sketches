//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SD.h>
#include <SPI.h>
Sd2Card card;
SdVolume volume;

const int chipSelect = 4;

void setup()
{
  Serial.begin(9600);
  Serial.print("\nInitializing SD card...");
  if (!card.init(SPI_HALF_SPEED, chipSelect))
  {
    Serial.println("initialization failed");
    return;
  }
  else
  {
   Serial.println("Wiring is correct and a card is present."); 
  }

  Serial.print("\nCard type: ");
  switch(card.type())
  {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  if (!volume.init(card))
  {
    Serial.println("Could not find FAT16/FAT32 partition.");
    return;
  }

  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();
  
  volumesize = volume.blocksPerCluster();
  volumesize *= volume.clusterCount();
  volumesize *= 512;
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
}


void loop(void)
{
}
