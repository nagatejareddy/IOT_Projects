#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// LCD and RFID
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD at I2C address 0x27
SoftwareSerial rfid(2, 3);          // RFID on pins RX=2, TX=3

String allowedTag = "5D00A3D51833";  // Authorized tag
const int relayPin = 9;              // Relay connected to pin 9

void setup() {
  Serial.begin(9600);
  rfid.begin(9600);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Start locked (Active LOW relay)

  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("CMRIT-IOT Lab");
  lcd.setCursor(0, 1);
  lcd.print("Scan your Tag");
}

void loop() {
  if (rfid.available()) {
    String tag = "";
    while (rfid.available()) {
      char c = rfid.read();
      tag += c;
      delay(5); // Small delay to complete reading
    }

    Serial.print("RFID Tag: ");
    Serial.println(tag);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tag:");
    lcd.setCursor(0, 1);
    lcd.print(tag);

    if (tag == allowedTag) {
      Serial.println("Access Granted");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access Granted");
      lcd.setCursor(0, 1);
      lcd.print("Door Unlocked");

      digitalWrite(relayPin, LOW);   // Unlock (relay ON)
      delay(3000);                   // Keep unlocked for 3 seconds
      digitalWrite(relayPin, HIGH);  // Lock again (relay OFF)

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door Locked");
      delay(2000);
    } else {
      Serial.println("Access Denied");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access Denied");
      delay(2000);
    }

    // Reset display
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CMRIT-IOT Lab");
    lcd.setCursor(0, 1);
    lcd.print("Scan your Tag");
  }
}
