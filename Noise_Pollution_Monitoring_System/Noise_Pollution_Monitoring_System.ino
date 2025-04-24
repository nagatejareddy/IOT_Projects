#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
#define SOUND_SENSOR_PIN A0
#define ALERT_PIN D5  // GPIO14

#define THRESHOLD_DB 75

void setup() {
  Serial.begin(115200);

  pinMode(ALERT_PIN, OUTPUT);
  digitalWrite(ALERT_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);
  display.println("Initializing...");
  display.display();
  delay(1000);
}

void loop() {
  int sensorValue = analogRead(SOUND_SENSOR_PIN);
  int fakeDB = map(sensorValue, 0, 1023, 30, 120);

  Serial.print("Analog: ");
  Serial.print(sensorValue);
  Serial.print(" -> dB (approx): ");
  Serial.println(fakeDB);

  // Display UI
  display.clearDisplay();

  // Header
  display.setTextSize(1);
  display.setCursor(30, 0);
  display.println("NOISE MONITOR");

  // Draw box
  display.drawRect(10, 15, 108, 40, SSD1306_WHITE);

  // Display dB reading in big font
  display.setTextSize(2);
  display.setCursor(35, 25);
  display.print(fakeDB);
  display.print(" dB");

  // Status bar
  display.setTextSize(1);
  display.setCursor(0, 56);
  if (fakeDB > THRESHOLD_DB) {
    display.print("Status: LOUD! 🔊");
    digitalWrite(ALERT_PIN, HIGH);
  } else {
    display.print("Status: Normal");
    digitalWrite(ALERT_PIN, LOW);
  }

  display.display();
  delay(500);
}
