# Web Integrated Smart Energy Meter

**Web Integrated Smart Energy Meter** is an IoT-based system designed to monitor electrical parameters in real-time. It measures voltage, current, power, and energy consumption, displaying the data locally on an LCD and remotely via the Blynk IoT app.

## Project Description
This project eliminates the need for manual meter reading by providing digital, real-time feedback.
* [cite_start]**Real-time Monitoring:** Measures AC Voltage (V), Current (A), and Power (W)[cite: 29, 30].
* [cite_start]**Remote Access:** Syncs live data to the Blynk mobile app over Wi-Fi[cite: 30, 47].
* [cite_start]**Cost Estimation:** Automatically calculates electricity costs based on energy usage (set at 8.5 per unit)[cite: 4, 91].
* [cite_start]**Data Persistence:** Saves total energy readings to EEPROM memory so data is not lost during power cuts[cite: 6].

## Components Used
* [cite_start]**Microcontroller:** ESP32 (Wi-Fi + Bluetooth)[cite: 39].
* [cite_start]**Voltage Sensor:** ZMPT101B[cite: 42].
* [cite_start]**Current Sensor:** ACS712[cite: 41].
* [cite_start]**Display:** 16x2 LCD[cite: 40].
* [cite_start]**Software:** Arduino IDE & Blynk IoT Platform[cite: 46, 47].

## Pin Connections
Connect the components to the ESP32 as defined in the source code:

| Component | ESP32 GPIO Pin |
| :--- | :--- |
| **Voltage Sensor (ZMPT101B)** | [cite_start]GPIO 35 [cite: 16] |
| **Current Sensor (ACS712)** | [cite_start]GPIO 34 [cite: 17] |
| **LCD RS** | [cite_start]GPIO 21 [cite: 1] |
| **LCD EN** | [cite_start]GPIO 22 [cite: 1] |
| **LCD D4** | [cite_start]GPIO 4 [cite: 1] |
| **LCD D5** | [cite_start]GPIO 5 [cite: 1] |
| **LCD D6** | [cite_start]GPIO 18 [cite: 1] |
| **LCD D7** | [cite_start]GPIO 19 [cite: 1] |

## Software & Libraries
The code is written in C++ using the Arduino IDE. You will need the following libraries:
1.  [cite_start]`BlynkSimpleEsp32.h` [cite: 1]
2.  [cite_start]`EmonLib.h` (Energy Monitor Library) [cite: 1]
3.  [cite_start]`LiquidCrystal.h` [cite: 1]
4.  [cite_start]`EEPROM.h` [cite: 1]

## How to Run
1.  Connect the hardware according to the pin connections table.
2.  Open the `.ino` file in Arduino IDE.
3.  Install the required libraries.
4.  [cite_start]Update the **Wi-Fi SSID**, **Password**, and **Blynk Auth Token** in the code[cite: 1, 3].
5.  Upload the code to your ESP32 board.
