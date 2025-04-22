
# 🌧️ Rain Detection System using Arduino

This project implements a basic rain detection system using an analog rain sensor and an Arduino board. The system provides real-time feedback using LEDs and logs data to the Serial Monitor.

## 📦 Features

- Real-time rain detection using an analog sensor
- LED indication:
  - 🔴 Red LED when rain is detected
  - 🟢 Green LED when no rain is detected
- Serial output of rain sensor readings and status

## 🛠️ Hardware Requirements

- Arduino Uno or compatible board
- Rain Sensor Module (Analog output)
- Red LED
- Green LED
- 2 x 220Ω Resistors
- Breadboard and Jumper Wires

## 🔌 Circuit Diagram

| Component     | Arduino Pin |
|---------------|-------------|
| Rain Sensor   | A0          |
| Red LED       | D3          |
| Green LED     | D2          |

      [Rain Sensor Module]
          VCC ----- 5V (Arduino)
          GND ----- GND (Arduino)
           AO ----- A0 (Arduino)

      [Red LED]
    Anode ----- 220Ω ----- D3 (Arduino)
    Cathode ---------------- GND

      [Green LED]
    Anode ----- 220Ω ----- D2 (Arduino)
    Cathode ---------------- GND


## 💡 Working Principle

The rain sensor outputs an analog value based on the presence of water droplets. The Arduino reads this value and:

- Turns **on** the **Red LED** if rain is detected (sensor value < 500)
- Turns **on** the **Green LED** if no rain is detected
- Logs the sensor value and status to the Serial Monitor

## 🧾 Code

The main code is in [`Rain_system.ino`](./Rain_system.ino). Customize the rain threshold (`500`) to calibrate for your sensor.




Built with ❤️ using Arduino.

by Y. Naga Teja Reddy
