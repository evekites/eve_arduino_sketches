#include <SoftwareSerial.h>
#include <DFMiniMp3.h>
//If you are using OSx to copy the mp3-files, use the following command to remove hidden files before playing:
// dot_clean /Volumes/<SDVolumeName>

class Mp3Notify
{
  public:
    static void OnError(uint16_t errorCode)
    {
      // see DfMp3_Error for code meaning
      Serial.println();
      Serial.print("Com Error ");
      Serial.println(errorCode);
    }

    static void OnPlayFinished(uint16_t globalTrack)
    {
      Serial.print("Klaar met spelen: ");
      Serial.println(globalTrack);
    }

    static void OnCardOnline(uint16_t code)
    {
      Serial.println();
      Serial.print("Card online ");
      Serial.println(code);
    }

    static void OnUsbOnline(uint16_t code)
    {
      Serial.println();
      Serial.print("USB Disk online ");
      Serial.println(code);
    }

    static void OnCardInserted(uint16_t code)
    {
      Serial.println();
      Serial.print("Card inserted ");
      Serial.println(code);
    }

    static void OnUsbInserted(uint16_t code)
    {
      Serial.println();
      Serial.print("USB Disk inserted ");
      Serial.println(code);
    }

    static void OnCardRemoved(uint16_t code)
    {
      Serial.println();
      Serial.print("Card removed ");
      Serial.println(code);
    }

    static void OnUsbRemoved(uint16_t code)
    {
      Serial.println();
      Serial.print("USB Disk removed ");
      Serial.println(code);
    }
};

SoftwareSerial MP3Serial(10, 11);
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(MP3Serial);

void setup()
{
  Serial.begin(115200);
  Serial.println("initializing...");
  mp3.begin();
  uint16_t volume = mp3.getVolume();
  Serial.print("volume ");
  Serial.println(volume);
  mp3.setVolume(30);
  uint16_t songCount = mp3.getTotalTrackCount();
  Serial.print("files ");
  Serial.println(songCount);
  Serial.println("starting...");
}

void waitMilliseconds(uint16_t msWait)
{
  uint32_t start = millis();
  while ((millis() - start) < msWait)
  {
    mp3.loop();
    delay(1);
  }
}

void loop()
{
  Serial.println("track 1");
  mp3.playMp3FolderTrack(1);
  waitMilliseconds(5000);
  Serial.println("track 2");
  mp3.playMp3FolderTrack(2);
  waitMilliseconds(5000);
}
