# IoT-Based Pulse Monitoring System

This project is an IoT-enabled pulse monitoring system that measures a person’s heart rate using a pulse sensor and displays the data on an OLED screen. It can be extended to transmit data over the internet for remote health monitoring.

## 🔧 Features

- Real-time heart rate monitoring
- Display pulse on a 0.96" OLED screen (SSD1306)
- Potential for IoT integration for remote tracking
- Compact and portable design

## 🛠️ Hardware Required

- Arduino UNO / Nano
- Pulse Sensor (e.g., SEN-11574)
- OLED Display (SSD1306, 128x64, I2C)
- Jumper Wires
- Breadboard
- USB Cable for programming
- (Optional) ESP8266/ESP32 for IoT data transmission

## 📦 Software Required

- Arduino IDE
- PulseSensor Playground Library
- Adafruit SSD1306 Library
- Adafruit GFX Library

### Install Libraries

Go to **Sketch > Include Library > Manage Libraries** and install the following:

- `PulseSensor Playground`
- `Adafruit SSD1306`
- `Adafruit GFX Library`

## 🔌 Circuit Diagram

| Component    | Arduino Pin |
| ------------ | ----------- |
| Pulse Signal | A0          |
| OLED SDA     | A4 (SDA)    |
| OLED SCL     | A5 (SCL)    |
| OLED VCC     | 5V          |
| OLED GND     | GND         |
| Pulse VCC    | 5V          |
| Pulse GND    | GND         |

> Note: For Arduino UNO. Pin mapping may vary for other boards.

## 🚀 Getting Started

1. Connect all components as per the circuit diagram.
2. Open the `IOT_based_Pulse_Monitoring_System.ino` file in Arduino IDE.
3. Select your board and port from **Tools** menu.
4. Upload the sketch.
5. Open the Serial Monitor (optional) to view BPM readings.
6. BPM is displayed live on the OLED screen.

## 📡 IoT Extension (Optional)

To enable remote monitoring:

- Integrate an ESP8266/ESP32
- Send BPM data to platforms like Blynk, Thingspeak, or Firebase
- Add Wi-Fi connectivity code to publish data

## 📚 References

- [Pulse Sensor Documentation](https://pulsesensor.com/)
- [Adafruit SSD1306 Guide](https://learn.adafruit.com/monochrome-oled-breakouts)
- [Arduino Getting Started](https://www.arduino.cc/en/Guide/HomePage)

## 🧑‍💻 Author

Made with ❤️ by Y. Naga Teja Reddy
