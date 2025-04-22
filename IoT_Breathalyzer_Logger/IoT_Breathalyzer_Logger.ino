#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "QQ";         // Replace with your Wi-Fi SSID
const char* password = "aaaa1111"; // Replace with your Wi-Fi password

WiFiClient client;

// ThingSpeak channel info
unsigned long myChannelNumber = 2930117; // Replace with your ThingSpeak Channel number
const char* myWriteAPIKey = "0BY7CE3V9F00AISF";  // Replace with your ThingSpeak Write API Key

// Pin definitions for LEDs
int mq3Pin = A0;            // MQ-3 sensor connected to A0
int ledPin1 = D2;           // Level 1 LED (No Alcohol)
int ledPin2 = D5;           // Level 2 LED (Low Alcohol)
int ledPin3 = D6;           // Level 3 LED (Moderate Alcohol)
int ledPin4 = D7;           // Level 4 LED (High Alcohol)

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  
  // Wait for Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Set LED pins as OUTPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  // Read the value from the MQ-3 alcohol sensor
  int sensorValue = analogRead(mq3Pin);
  float voltage = sensorValue * (3.3 / 1023.0);  // Convert sensor value to voltage
  float bacEstimate = voltage * 0.4; // Approximate BAC estimation (adjust if needed)

  // Print the sensor value, voltage, and BAC estimate
  Serial.print("Sensor Value: "); Serial.print(sensorValue);
  Serial.print(" | Voltage: "); Serial.print(voltage);
  Serial.print(" | BAC Estimate: "); Serial.println(bacEstimate);

  // Control LEDs based on BAC levels
  if (bacEstimate == 0.00) {
    // Level 1: No Alcohol (BAC <= 0.00)
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  } else if (bacEstimate > 0.00 && bacEstimate <= 0.02) {
    // Level 2: Low Alcohol (0.00 < BAC <= 0.02)
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  } else if (bacEstimate > 0.02 && bacEstimate <= 0.05) {
    // Level 3: Moderate Alcohol (0.02 < BAC <= 0.05)
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  } else if (bacEstimate > 0.05) {
    // Level 4: High Alcohol (BAC > 0.05)
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
  }

  // Send the BAC estimate to ThingSpeak
  ThingSpeak.setField(1, bacEstimate);  // Field 1 stores BAC estimate
  int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  // Check if data was sent successfully
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.println("Failed to send data");
  }

  // Wait 15 seconds before taking the next reading (ThingSpeak rate limit)
  delay(15000);
}
