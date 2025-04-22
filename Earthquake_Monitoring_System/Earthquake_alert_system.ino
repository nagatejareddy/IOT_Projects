#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Wi-Fi credentials
const char* ssid = "Cyberpunk_005";
const char* password = "ABCD1234";

// ThingSpeak
const char* host = "api.thingspeak.com";
String apiKey = "MXUGYX49NXSF1BT2";

const int vibrationPin = D5; // GPIO14
const int sampleCount = 100;
const int vibrationThreshold = 40; // % above which we call it an earthquake

void setup() {
  pinMode(vibrationPin, INPUT);
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("WiFi Connected");
  display.display();
  delay(1000);
}

void loop() {
  int vibrationCount = 0;

  for (int i = 0; i < sampleCount; i++) {
    if (digitalRead(vibrationPin) == HIGH) {
      vibrationCount++;
    }
    delay(10); // total sample time: ~1 second
  }

  int vibrationPercent = (vibrationCount * 100) / sampleCount;

  Serial.print("Vibration: ");
  Serial.print(vibrationPercent);
  Serial.println("%");

  // OLED Display
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Vibration Monitor");

  display.setCursor(0, 16);
  display.setTextSize(2);
  display.print(vibrationPercent);
  display.println("%");

  display.setTextSize(1);
  display.setCursor(0, 48);

  if (vibrationPercent > vibrationThreshold) {
    display.println("⚠ EARTHQUAKE ALERT ⚠");
    Serial.println("⚠ EARTHQUAKE ALERT ⚠");
  } else if (vibrationPercent > 0) {
    display.println("Vibration Detected");
  } else {
    display.println("No Vibration");
  }

  display.display();

  // Send to ThingSpeak
  sendToThingSpeak(vibrationPercent);

  delay(15000); // 15s delay for ThingSpeak
}

void sendToThingSpeak(int value) {
  WiFiClient client;

  if (!client.connect(host, 80)) {
    Serial.println("ThingSpeak connection failed");
    return;
  }

  String url = "/update?api_key=" + apiKey + "&field1=" + String(value);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  delay(500);
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  client.stop();
}
