//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

Adafruit_SSD1306 display(128, 64, &Wire);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000); // Pause for 2 seconds
  display.clearDisplay();
}

void loop()
{
  display.clearDisplay();
  display.fillCircle(45, 20, 10, WHITE);
  display.fillCircle(48, 17, 2, BLACK);
  display.fillRect(10, 10, 10, 10, WHITE);
  display.drawRoundRect(111, 12, 15, 15, 5, WHITE);
  display.drawLine(0, 0, display.width()-1, display.height() - 1, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(25, 0);
  display.println("Bye");
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1);
  display.println("world");
  display.setTextColor(WHITE);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(80, 30);
  display.println("OLED");
  display.display();
  delay(1000);
}
