# Automatic Pet Feeder

## Description
This project is an **Automatic Pet Feeder** system built using an **Arduino** platform. The feeder is equipped with a **real-time clock (RTC)**, **LCD display**, **keypad**, **servo motor**, and a **buzzer** to automate the feeding process. The system feeds the pet at a specified time and can be manually triggered or reprogrammed by the user via the keypad.

### Features:
- Displays the current time and set feeding time on an **LCD screen**.
- **Servo motor** opens the pet feeder at the set time to serve food.
- **Buzzer** sounds when the pet is being fed.
- **Keypad** allows setting and changing the feeding time in **HHMM** format.
- **RTC module (DS3231)** ensures accurate timekeeping even if the system is powered off.

## Components Used:
- **Arduino (Uno or Mega)**
- **RTC_DS3231 module**
- **LiquidCrystal_I2C Display (16x2)**
- **4x4 Keypad**
- **Servo motor**
- **Buzzer**
- **Wires and Breadboard**
  
## Wiring:
- **Servo motor** connected to pin 10 (PWM).
- **Buzzer** connected to pin 11.
- **RTC** module connected to the I2C pins (SDA, SCL).
- **Keypad** connected to Arduino pins 2, 3, 4, 5 (rows) and 6, 7, 8, 9 (columns).

## How It Works:
1. The **RTC module** keeps track of the current time.
2. The **LCD display** shows both the current time and the set feeding time.
3. The system compares the current time to the set feeding time. When they match, the **servo motor** opens the pet feeder to dispense food for 5 seconds.
4. The **buzzer** sounds to notify that feeding is in progress.
5. After each feeding, the servo closes and the buzzer stops, indicating that the feeding is complete.
6. The **keypad** is used to set the feeding time by entering the time in **HHMM** format.
7. The system automatically resets after each minute to check for the next feeding cycle.

## Instructions:

1. **Setting the Feeding Time:**
   - Press the **'A'** key on the keypad.
   - Enter the feeding time in **HHMM** format (e.g., 1200 for 12:00 PM).
   - The system will update the feeding time and display it on the LCD.

2. **Feeding:**
   - At the specified feeding time, the servo motor will open, and the buzzer will sound for 5 seconds, signaling that food is dispensed.
   - After the feeding time, the servo will close, and the buzzer will turn off.

## Libraries Used:
- `Wire.h` (for I2C communication)
- `RTClib.h` (for RTC functionality)
- `LiquidCrystal_I2C.h` (for controlling the LCD display)
- `Keypad.h` (for keypad functionality)
- `Servo.h` (for controlling the servo motor)

## Installation:
1. Install the required libraries via the Arduino Library Manager:
   - **RTClib**
   - **LiquidCrystal_I2C**
   - **Keypad**
   - **Servo**
   
2. Upload the code to your Arduino using the Arduino IDE.

3. Connect the hardware according to the wiring diagram provided above.

4. After the setup is complete, power the system on, and it will start showing the current time and the set feeding time on the LCD.

## Troubleshooting:
- **LCD not displaying:** Ensure the `LiquidCrystal_I2C` library is correctly installed and the LCD is wired properly.
- **Keypad not responding:** Check the connections to ensure the keypad is connected to the correct pins on the Arduino.
- **Servo not working:** Verify the servo is properly connected to pin 10 and that the servo library is correctly installed.


## Acknowledgements:
- The Arduino community for providing excellent resources.
- Libraries from Adafruit and other contributors.

## Author:
- **Y. Naga Teja Reddy**

