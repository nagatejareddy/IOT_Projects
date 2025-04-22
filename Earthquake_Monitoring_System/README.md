# 🌍 IoT Earthquake Vibration Monitor using ESP8266 and ThingSpeak

This project is an **IoT-based Earthquake Vibration Monitor** using the ESP8266 Wi-Fi module. It measures vibrations using a digital vibration sensor and displays the real-time status on an OLED display. The data is also uploaded to [ThingSpeak](https://thingspeak.com/) for remote monitoring and visualization.

---

## 📷 Project Overview

This system detects vibrations, displays the percentage of detected vibrations on an OLED screen, and sends the data to ThingSpeak every 15 seconds. If the vibration percentage crosses a predefined threshold (default: 40%), the system triggers an alert message indicating a possible earthquake.

---

## 📦 Components Used

| Component               | Description                        |
|-------------------------|------------------------------------|
| ESP8266 NodeMCU         | Wi-Fi microcontroller board        |
| OLED Display (128x64)   | I2C SSD1306 for data display       |
| SW-420 Vibration Sensor| Detects surface vibrations         |
| Jumper Wires            | For circuit connections            |
| Breadboard              | For prototyping                    |

---

## 🔧 Features

- 🧠 Real-time vibration monitoring
- 📟 OLED display for live status
- 🌐 Data logging to ThingSpeak
- ⚠ Earthquake alerts based on threshold
- 💡 Lightweight and beginner-friendly

---

## ⚙️ Circuit Diagram


```markdown
## ⚙️ Circuit Diagram

### 🧭 Connections

#### 🔌 Vibration Sensor (SW-420)
| ESP8266 Pin | Vibration Sensor |
|-------------|------------------|
| D5 (GPIO14) | OUT              |
| 3.3V        | VCC              |
| GND         | GND              |

#### 📟 OLED Display (I2C SSD1306)
| ESP8266 Pin | OLED Display |
|-------------|--------------|
| D1 (GPIO5)  | SCL          |
| D2 (GPIO4)  | SDA          |
| 3.3V        | VCC          |
| GND         | GND          |

---

### 2. Install Required Libraries

In the **Arduino IDE**, go to **Sketch > Include Library > Manage Libraries** and install the following:

- `ESP8266WiFi`
- `Adafruit SSD1306`
- `Adafruit GFX`

---

### 3. Configure Wi-Fi & ThingSpeak

Open the `.ino` file and update these variables with your details:

```cpp
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
String apiKey = "YourThingSpeakAPIKey";
```

> 📝 Make sure you have created a ThingSpeak channel and enabled **Field 1** for data.

---

### 4. Upload the Code

- Board: `NodeMCU 1.0 (ESP-12E Module)`
- Port: Select the correct COM port
- Upload via Arduino IDE

---

### 5. Monitor Serial Output

- Open **Serial Monitor** (baud rate: `115200`)
- Check Wi-Fi status, vibration readings, and ThingSpeak update logs

---

## 📊 Vibration Logic

- The system samples the vibration pin 100 times over 1 second.
- Each HIGH signal counts as vibration.
- Vibration % = `(HIGH count / 100) * 100`
- If the result exceeds the threshold (default: `40%`), an earthquake warning is shown.

---

## 📺 OLED Display Output

- **Top Line**: "Vibration Monitor"
- **Middle (Large Text)**: Current Vibration Percentage
- **Bottom**:
  - `⚠ EARTHQUAKE ALERT ⚠` if above threshold
  - `Vibration Detected` for low values
  - `No Vibration` if stable

---

## 📈 ThingSpeak Visualization

ThingSpeak will display a real-time chart of vibration percentages. You can use Field 1 for plotting.

> Visit [ThingSpeak](https://thingspeak.com/) and navigate to your channel to view data.

---

## 🧪 Adjusting Sensitivity

You can modify the detection threshold in code:

```cpp
const int vibrationThreshold = 40; // Default: 40%
```

Raise or lower this based on testing conditions.

---

## 🚀 Future Enhancements

- Add a buzzer for audible alerts
- Integrate with IFTTT for push notifications
- Add SD card support for local data logging
- Add GPS for location-tagged data
- Integrate with advanced dashboards like Grafana

---

## 🙋‍♂️ Author

Developed with ❤️ by Y. Naga Teja Reddy(https://github.com/nagatejareddy)  

```
