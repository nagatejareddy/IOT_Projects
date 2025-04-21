#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak
unsigned long channelNumber = YOUR_CHANNEL_NUMBER;   // Replace with your channel number
const char* writeAPIKey = "YOUR_WRITE_API_KEY";      // Replace with your ThingSpeak Write API Key

WiFiClient client;

// Pin Definitions
#define PIR_PIN D2
#define RED_LED_PIN D5
#define GREEN_LED_PIN D6
#define BUZZER_PIN D7

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Motion Detected!");

    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);

    // Send motion detected to ThingSpeak
    ThingSpeak.setField(1, "Motion Detected");
  } else {
    Serial.println("No Motion");

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);

    // Send no motion to ThingSpeak
    ThingSpeak.setField(1, "No Motion");
  }

  // Write to ThingSpeak
  int x = ThingSpeak.writeFields(channelNumber, writeAPIKey);
  if (x == 200) {
    Serial.println("ThingSpeak update successful.");
  } else {
    Serial.println("ThingSpeak update failed. Error: " + String(x));
  }

  delay(15000); // ThingSpeak accepts updates every 15 seconds
}
