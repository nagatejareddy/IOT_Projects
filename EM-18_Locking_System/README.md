# 🔐 IoT-Based RFID Door Lock System

A simple and secure door access system using an Arduino, RFID module, relay, and LCD display. Only authorized RFID tags can unlock the door, making it ideal for labs, offices, or home automation.

## 📸 Project Overview

This project allows access to a door (or any controlled area) using an RFID card or tag. When a valid tag is scanned, the system displays "Access Granted" on an LCD and unlocks the door for a few seconds using a relay. If the tag is unauthorized, access is denied.

👨‍💻 Author
Y. Naga Teja Reddy
Founder: Draco-Botz, RCC Club
Hyderabad, India

---

## ⚙️ Components Used

| Component             | Description                       |
|-----------------------|-----------------------------------|
| Arduino Uno           | Microcontroller                   |
| RFID Reader (RC522/EM-18) | Reads RFID tags               |
| RFID Tag/Card         | Unique ID for authentication      |
| Relay Module          | Controls door locking mechanism   |
| 16x2 I2C LCD Display  | Displays messages                 |
| Jumper Wires          | For connections                   |
| Breadboard (optional) | For prototyping                   |
| Power Supply          | 5V USB or external adapter        |

---

## 🔌 Circuit Connections

### LCD (I2C Interface)

| LCD Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

### RFID Reader (using SoftwareSerial)

| RFID Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| TX       | Pin 2       |
| RX       | Pin 3       |

### Relay Module

| Relay IN | Arduino Pin 9 |
|----------|----------------|

> ⚠️ Note: The relay logic assumes **active-low** control. Adjust the `digitalWrite()` logic if your relay behaves differently.

---

## 🧠 How It Works

1. The system waits for an RFID tag to be scanned.
2. Once scanned, the tag ID is read and compared with the authorized ID.
3. If the ID matches, access is granted:
   - LCD displays "Access Granted"
   - Relay is activated to unlock the door for 3 seconds
4. If the ID doesn't match, access is denied.

---

## 🖥️ Code

The code is written in **Arduino C++**. You can find it in the [`em-18-lockingSystem.ino`](./em-18-lockingSystem.ino) file.

📦 Libraries Required
Make sure you install these libraries in your Arduino IDE:

LiquidCrystal_I2C

Wire (comes pre-installed)

SoftwareSerial (comes pre-installed)

### 💡 Key Variables

```cpp
String allowedTag = "5D00A3D51833"; // Replace with your RFID tag ID
const int relayPin = 9;             // Relay pin for door lock control

