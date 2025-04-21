#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PULSE_SENSOR A0

int pulseValue = 0;
int bpm = 0;
int glowSize = 8;
bool growing = true;

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(30, 30);
  display.println("Heart Glow Init");
  display.display();
  delay(1500);
}

void loop() {
  pulseValue = analogRead(PULSE_SENSOR);
  bpm = map(pulseValue, 500, 1023, 60, 120);  // Simulated BPM

  // Glow animation logic
  if (growing) {
    glowSize++;
    if (glowSize > 12) growing = false;
  } else {
    glowSize--;
    if (glowSize < 8) growing = true;
  }

  display.clearDisplay();

  // Glow effect: draw faint large heart behind
  drawHeart(64, 10, glowSize);  // Dynamic size for glowing effect

  // Foreground heart (core)
  drawHeart(64, 10, 6);         // Fixed-size inner heart

  // Show BPM
  display.setTextSize(2);
  display.setCursor(18, 32);
  display.print("BPM: ");
  display.print(bpm);

  display.setTextSize(1);
  display.setCursor(20, 56);
  display.print(bpm < 90 ? "All Good ❤" : "Relax & Breathe");

  display.display();
  delay(100);
}

// Function to draw heart shape
void drawHeart(int x, int y, int size) {
  display.fillCircle(x - size/2, y, size/2, SSD1306_WHITE);
  display.fillCircle(x + size/2, y, size/2, SSD1306_WHITE);
  display.fillTriangle(x - size, y, x + size, y, x, y + size * 1.4, SSD1306_WHITE);
}
