# Automatic Pet Feeder

## Description
This project is an **Automatic Pet Feeder** system built using an **Arduino** platform.  
The feeder is equipped with a **Real-Time Clock (RTC)**, **LCD display**, **keypad**, **servo motor**, and a **buzzer** to automate the feeding process.  
The system feeds the pet at a specified time and can be manually triggered or reprogrammed by the user via the keypad.

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

### Detailed Connections

| Component             | Arduino Pin          | Notes                                |
|-----------------------|-----------------------|--------------------------------------|
| **Servo Motor**        | Pin 10                | PWM capable pin                      |
| **Buzzer**             | Pin 11                | Active buzzer recommended            |
| **Keypad Rows**        | Pins 2, 3, 4, 5        | Connect to keypad row pins           |
| **Keypad Columns**     | Pins 6, 7, 8, 9        | Connect to keypad column pins        |
| **RTC Module (DS3231)**| SDA (A4), SCL (A5)     | I2C Communication (Wire Library)     |
| **LCD Display (16x2)** | SDA (A4), SCL (A5)     | Shares I2C bus with RTC               |

#### RTC DS3231 Connections
- **VCC** → **5V**
- **GND** → **GND**
- **SDA** → **A4**
- **SCL** → **A5**

#### LCD 16x2 I2C Connections
- **VCC** → **5V**
- **GND** → **GND**
- **SDA** → **A4**
- **SCL** → **A5**

#### Keypad Connections
- **Row Pins** → **Pins 2, 3, 4, 5**
- **Column Pins** → **Pins 6, 7, 8, 9**

#### Servo Motor Connections
- **Signal (Yellow/White Wire)** → **Pin 10**
- **VCC (Red Wire)** → **External 5V** (Recommended for stable power)
- **GND (Brown/Black Wire)** → **Common GND with Arduino**

#### Buzzer Connections
- **Positive (Long Leg)** → **Pin 11**
- **Negative (Short Leg)** → **GND**

> ⚡ **Important:** Use an external 5V supply for servo motor to avoid Arduino reset due to high current draw. Connect Arduino GND and external GND together.

## How It Works:
1. The **RTC module** keeps track of the current time.
2. The **LCD display** shows both the current time and the set feeding time.
3. The system compares the current time to the set feeding time.
4. When they match:
   - The **servo motor** opens the pet feeder (90°) to dispense food for 5 seconds.
   - The **buzzer** sounds during this time to indicate feeding.
5. After feeding:
   - The **servo** returns to the closed position (0°).
   - The **buzzer** stops.
6. The **keypad** is used to set a new feeding time by entering **HHMM**.

## Instructions:

### Setting the Feeding Time:
- Press the **'A'** key on the keypad.
- Enter the feeding time in **HHMM** format (e.g., 1200 for 12:00 PM).
- The system updates and displays the new feeding time.

### Feeding Process:
- At the set time, the servo motor will rotate to open the feeder.
- The buzzer will sound to alert the pet and user.
- After 5 seconds, the servo returns to the original position and the buzzer stops.

## Libraries Used:
- `Wire.h` (for I2C communication)
- `RTClib.h` (for RTC functionality)
- `LiquidCrystal_I2C.h` (for LCD display)
- `Keypad.h` (for keypad input)
- `Servo.h` (for servo motor control)

## Installation:
1. Install the required libraries via Arduino Library Manager:
   - **RTClib**
   - **LiquidCrystal_I2C**
   - **Keypad**
   - **Servo**

2. Upload the code to your Arduino board using Arduino IDE.

3. Make the hardware connections as described in the wiring section.

4. Power the system ON. The LCD will start displaying the current time and the feeding time.

## Troubleshooting:
- **LCD not displaying:** Check I2C address and wiring. Confirm correct installation of LiquidCrystal_I2C library.
- **Keypad not responding:** Verify keypad connections are correct as per row and column mapping.
- **Servo not working:** Ensure external 5V power for servo; check connections to pin 10.
- **RTC not working:** Double-check SDA and SCL connections. Ensure `RTClib` is properly installed.

## Acknowledgements:
- Arduino Community and forums for vast knowledge resources.
- Libraries from Adafruit and open-source contributors.

## Author:
- **Y. Naga Teja Reddy**
