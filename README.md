# Web Integrated Smart Energy Meter

**Web Integrated Smart Energy Meter** is an IoT-based system designed to monitor electrical parameters in real-time. It measures voltage, current, power, and energy consumption, displaying the data locally on an LCD and remotely via the Blynk IoT app.

## Project Description
This project eliminates the need for manual meter reading by providing digital, real-time feedback.
* **Real-time Monitoring:** Measures AC Voltage (V), Current (A), and Power (W).
* **Remote Access:** Syncs live data to the Blynk mobile app over Wi-Fi.
* **Cost Estimation:** Automatically calculates electricity costs based on energy usage (set at 8.5 per unit).
* **Data Persistence:** Saves total energy readings to EEPROM memory so data is not lost during power cuts.

## Components Used
* **Microcontroller:** ESP32 (Wi-Fi + Bluetooth).
* **Voltage Sensor:** ZMPT101B.
* **Current Sensor:** ACS712.
* **Display:** 16x2 LCD.
* **Software:** Arduino IDE & Blynk IoT Platform.

## Pin Connections
Connect the components to the ESP32 as defined in the source code:

| Component | ESP32 GPIO Pin |
| :--- | :--- |
| **Voltage Sensor (ZMPT101B)** | GPIO 35 |
| **Current Sensor (ACS712)** | GPIO 34 |
| **LCD RS** | GPIO 21 |
| **LCD EN** | GPIO 22 |
| **LCD D4** | GPIO 4 |
| **LCD D5** | GPIO 5 |
| **LCD D6** | GPIO 18 |
| **LCD D7** | GPIO 19 |

## Software & Libraries
The code is written in C++ using the Arduino IDE. You will need the following libraries:
1.  `BlynkSimpleEsp32.h`
2.  `EmonLib.h` (Energy Monitor Library)
3.  `LiquidCrystal.h`
4.  `EEPROM.h`

## How to Run
1.  Connect the hardware according to the pin connections table.
2.  Open the `.ino` file in Arduino IDE.
3.  Install the required libraries.
4.  Update the **Wi-Fi SSID**, **Password**, and **Blynk Auth Token** in the code.
5.  Upload the code to your ESP32 board.
