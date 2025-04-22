# IoT Breathalyzer Logger

This project uses an **MQ-3 alcohol sensor** with an **ESP8266** (or compatible board) to measure the **Blood Alcohol Concentration (BAC)**. The BAC is displayed using LEDs and uploaded to **ThingSpeak** for remote monitoring. This system is ideal for real-time monitoring of alcohol levels in a given environment, such as a vehicle or workplace.

---

## Features
- Real-time alcohol concentration monitoring using the MQ-3 sensor.
- **LED Indicators** for different BAC levels:
  - **Level 1**: No Alcohol (BAC ≤ 0.00)
  - **Level 2**: Low Alcohol (0.00 < BAC ≤ 0.02)
  - **Level 3**: Moderate Alcohol (0.02 < BAC ≤ 0.05)
  - **Level 4**: High Alcohol (BAC > 0.05)
- Uploads BAC data to **ThingSpeak** for remote monitoring.
- Works with **ESP8266** boards (e.g., NodeMCU).
- **Wi-Fi** connectivity for cloud data logging and visualization.

---

## Components Required

- **ESP8266 Board** (NodeMCU or similar)
- **MQ-3 Alcohol Sensor** (Analog)
- **LEDs** (4 LEDs for BAC levels)
- **Resistors** (for LED current limiting)
- **Jumper Wires**
- **Breadboard**
- **ThingSpeak Account** (for remote data logging)
- **Wi-Fi Network** (to connect ESP8266 to the internet)

---

## Circuit Diagram

The connections for the MQ-3 sensor and the LEDs are as follows:

```plaintext
                               +---------------------------+
                               |        NodeMCU (ESP8266)  |
                               |                           |
+------------------+           |                           |
|    MQ-3 Sensor   |           |                           |
|------------------|           |                           |
|  VCC  ----------> 3V3        |                           |
|  GND  ----------> GND        |                           |
|  AOUT ---------> A0          |                           |
|  DOUT ---------> (Not Used)  |                           |
+------------------+           |                           |
                               |                           |
    D2 (GPIO4)  -------------> [LED1 Anode (+)] -----------|
                               |                           |
    D5 (GPIO14) -------------> [LED2 Anode (+)] -----------|
                               |                           |
    D6 (GPIO12) -------------> [LED3 Anode (+)] -----------|
                               |                           |
    D7 (GPIO13) -------------> [LED4 Anode (+)] -----------|
                               |                           |
    [LED1 Cathode (-)] ------> [220Ω Resistor] ------------> GND
                               |                           |
    [LED2 Cathode (-)] ------> [220Ω Resistor] ------------> GND
                               |                           |
    [LED3 Cathode (-)] ------> [220Ω Resistor] ------------> GND
                               |                           |
    [LED4 Cathode (-)] ------> [220Ω Resistor] ------------> GND
                               +---------------------------+

```
# Software Setup

## 1. Install Required Libraries
Before uploading the code, you need to install the following libraries in the Arduino IDE:

- **ESP8266WiFi**: For Wi-Fi functionality.
- **ThingSpeak**: For sending data to ThingSpeak.

You can install these libraries via the **Library Manager** in the Arduino IDE.

## 2. ThingSpeak Setup
1. Go to [ThingSpeak](https://thingspeak.com) and create an account.
2. Create a new **channel** and note down the **Channel Number** and **Write API Key**.
3. Replace the placeholders for `myChannelNumber` and `myWriteAPIKey` in the code with your ThingSpeak details.

## 3. Configure Wi-Fi
Replace the `ssid` and `password` variables in the code with your Wi-Fi credentials so the ESP8266 can connect to the internet.

## 4. Upload the Code
1. Open the Arduino IDE and select the appropriate **ESP8266** board and port.
2. Copy and paste the code into the Arduino IDE.
3. Click the **Upload** button to upload the code to your ESP8266 board.

---

# Code Explanation

## 1. Wi-Fi Setup
The ESP8266 connects to your Wi-Fi network using the provided credentials (`ssid` and `password`).

## 2. MQ-3 Sensor Reading
The code reads analog values from the MQ-3 sensor connected to the **A0** pin on the ESP8266. These values are then converted to voltage, and an approximation of the **BAC** (Blood Alcohol Concentration) is calculated based on the sensor's voltage output.

## 3. LED Indicators
Based on the BAC estimate, one of four LEDs will light up:

- **Level 1 (No Alcohol)**: BAC ≤ 0.00
- **Level 2 (Low Alcohol)**: 0.00 < BAC ≤ 0.02
- **Level 3 (Moderate Alcohol)**: 0.02 < BAC ≤ 0.05
- **Level 4 (High Alcohol)**: BAC > 0.05

## 4. Sending Data to ThingSpeak
The BAC value is sent to ThingSpeak every **15 seconds** (to comply with the free plan's rate limit). The code uses the ThingSpeak API to upload data to your channel.

## 5. Serial Monitoring
For debugging purposes, the sensor value, voltage, and BAC estimate are printed to the **Serial Monitor**.

---

# Visualization on ThingSpeak

Once the data starts coming in, you can visualize the BAC readings on ThingSpeak:

1. Log in to your **ThingSpeak** account.
2. Go to the **Channel View** of the channel you created.
3. View real-time graphs of the BAC levels.

---

# Notes

- The BAC estimation is an approximation based on the voltage from the MQ-3 sensor. Adjust the `bacEstimate` formula if needed for better accuracy.
- The MQ-3 sensor may require calibration to give more accurate readings.
- Make sure to use the correct voltage reference for your ESP8266 if it is different from 3.3V.
- ThingSpeak has a rate limit for free accounts. This project uploads data every **15 seconds** to stay within the limits.

---

# Future Improvements

- **Display Output**: Add an OLED or LCD display to show the BAC value on the device.
- **Mobile App**: Create a mobile app that shows the real-time BAC from the ThingSpeak channel.
- **Sensor Calibration**: Implement a more accurate BAC calculation based on sensor calibration and environmental factors.
- **Additional Sensors**: Integrate other sensors, such as a temperature sensor, to enhance the system's accuracy.
- **Alert System**: Set up an alert mechanism (via email or SMS) when the BAC exceeds a certain threshold.

---

# Acknowledgements

- **ThingSpeak**: For providing an easy-to-use platform for IoT data logging.
- **ESP8266**: For making Wi-Fi-enabled microcontroller projects accessible.
- **MQ-3 Alcohol Sensor**: For enabling alcohol detection in IoT applications.
