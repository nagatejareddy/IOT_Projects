# 🕵️‍♂️ ESP8266 Motion Detection System with ThingSpeak Logging

This project is a simple motion detection system using an **ESP8266**, **PIR motion sensor**, **LED indicators**, a **buzzer**, and **ThingSpeak** integration to monitor and log motion events online.

## 🔧 Components Used

| Component         | Quantity |
|------------------|----------|
| ESP8266 (NodeMCU) | 1        |
| PIR Motion Sensor | 1        |
| Red LED           | 1        |
| Green LED         | 1        |
| 220Ω Resistors    | 2        |
| Active Buzzer     | 1        |
| Jumper Wires      | As needed |

## ⚡ Circuit Connections

| ESP8266 Pin | Connected To         |
|-------------|----------------------|
| D2 (GPIO4)  | PIR Sensor OUT       |
| D5 (GPIO14) | Red LED Anode        |
| D6 (GPIO12) | Green LED Anode      |
| D7 (GPIO13) | Buzzer Positive Lead |
| GND         | LED/Buzzer/PIR GND   |
| 3.3V/5V     | PIR Sensor VCC       |

- Red LED lights up and buzzer beeps when motion is detected.
- Green LED stays on when no motion is detected.
- Motion data is sent to ThingSpeak every 15 seconds.

## 🌐 ThingSpeak Setup

1. Create a free account at [thingspeak.com](https://thingspeak.com)
2. Create a new channel with at least **1 field**: `Motion Status`
3. Copy your **Channel Number** and **Write API Key**

## 📥 Arduino Libraries Required

Install these via **Arduino Library Manager**:

- `ESP8266WiFi`
- `ThingSpeak`

## 🧠 How It Works

- The **PIR sensor** detects motion and triggers the ESP8266.
- **Red LED** and **buzzer** activate on motion detection.
- The motion status is logged to **ThingSpeak**, viewable in a web dashboard.

## 🧾 Example ThingSpeak Output

| Timestamp           | Motion Status   |
|---------------------|-----------------|
| 2025-04-21 10:00:15 | Motion Detected |
| 2025-04-21 10:00:30 | No Motion       |

## 🚀 How to Use

1. Connect all components as described above.
2. Upload the provided Arduino sketch.
3. Open Serial Monitor at **115200 baud** to debug.
4. View live motion updates at your ThingSpeak channel.

## 📸 Future Upgrades

- Add email/SMS/Telegram alerts with IFTTT or Blynk
- Log motion duration and intervals
- Control system remotely via a web or mobile app

---

## 🛠 Made With

- ❤️ Arduino IDE
- 🔌 ESP8266 Wi-Fi
- 📊 ThingSpeak IoT Platform

> Feel free to fork, star ⭐, and modify this project for your smart home or surveillance applications!

## Author
Y. Naga Teja Reddy
