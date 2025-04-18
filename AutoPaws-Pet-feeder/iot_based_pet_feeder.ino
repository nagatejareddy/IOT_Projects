#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
Servo servo;

const int servoPin = 10;     // Servo signal pin
const int buzzerPin = 11;    // Buzzer signal pin

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Feeding time variables
int feedHour = 12;
int feedMinute = 0;
bool hasFed = false;

void setup() {
  Wire.begin();
  rtc.begin();
  lcd.begin(16, 2);
  lcd.backlight();

  servo.attach(servoPin);
  servo.write(0);  // Closed position

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);  // Buzzer OFF

  lcd.setCursor(0, 0);
  lcd.print("Auto Pet Feeder");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  // Display current time
  lcd.setCursor(0, 0);
  lcd.print("Time   ");
  printTwoDigits(now.hour());
  lcd.print(":");
  printTwoDigits(now.minute());

  // Display feed time
  lcd.setCursor(0, 1);
  lcd.print("Feed@  ");
  printTwoDigits(feedHour);
  lcd.print(":");
  printTwoDigits(feedMinute);

  // Trigger feeding
  if (now.hour() == feedHour && now.minute() == feedMinute && !hasFed) {
    feedPet();
    hasFed = true;
  }

  // Reset flag after minute changes
  if (now.minute() != feedMinute) {
    hasFed = false;
  }

  // Set feed time
  char key = keypad.getKey();
  if (key == 'A') {
    lcd.clear();
    lcd.print("Set HHMM:");
    String timeStr = "";
    while (timeStr.length() < 4) {
      char k = keypad.getKey();
      if (k >= '0' && k <= '9') {
        timeStr += k;
        lcd.setCursor(timeStr.length() - 1, 1);
        lcd.print(k);
      }
    }
    feedHour = timeStr.substring(0, 2).toInt();
    feedMinute = timeStr.substring(2, 4).toInt();
    lcd.clear();
  }

  delay(500);
}

void printTwoDigits(int number) {
  if (number < 10) lcd.print("0");
  lcd.print(number);
}

void feedPet() {
  lcd.clear();
  lcd.print("Feeding...");

  // Start buzzer
  tone(buzzerPin, 1000);  // 1kHz tone

  // Open servo to 90°
  servo.write(90);
  delay(5000);  // Keep open for 5 seconds

  // Stop buzzer and close servo
  noTone(buzzerPin);
  servo.write(0);

  lcd.setCursor(0, 1);
  lcd.print("Done!");
  delay(1000);
  lcd.clear();
}
