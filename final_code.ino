#define BLYNK_TEMPLATE_ID "TMPL35Vfa3VDw"
#define BLYNK_TEMPLATE_NAME "Smart Energy Meter"
#define BLYNK_AUTH_TOKEN "dEfSlbUgyXezKxkJfIjtqE-9YdnCTce1"
#define BLYNK_PRINT Serial

#include "EmonLib.h"
#include <EEPROM.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal.h>

// LCD Pin Mapping
LiquidCrystal lcd(21, 22, 4, 5, 18, 19);  // RS, E, D4, D5, D6, D7

// Calibration constants
const float vCalibration = 800.0;
const float currCalibration = 0.15;

// WiFi credentials
const char auth[] = "dEfSlbUgyXezKxkJfIjtqE-9YdnCTce1"; //Your auth code in blynk mobile app one time only
const char ssid[] = "Narayan"; // name of the wifi
const char pass[] = "12345678"; // password of wifi

// EnergyMonitor setup
EnergyMonitor emon;
BlynkTimer timer;

float totalUnits = 0.0;
float totalCost = 0.0;
const float costPerUnit = 8.5;
const int addrUnits = 0;

float powerAccum = 0.0;
int sampleCount = 0;

void saveUnitDataToEEPROM() {
  EEPROM.put(addrUnits, totalUnits);
  EEPROM.commit();
}

void readUnitDataFromEEPROM() {
  EEPROM.get(addrUnits, totalUnits);
  if (isnan(totalUnits) || totalUnits < 0) {
    totalUnits = 0.0;
    saveUnitDataToEEPROM();
  }
}

void samplePower() {
  emon.calcVI(20, 2000);
  powerAccum += emon.apparentPower;
  sampleCount++;

  Serial.printf("Sampled: Vrms=%.2f V | Irms=%.2f mA | P=%.2f W\n", 
                emon.Vrms, emon.Irms * 1000, emon.apparentPower);
}

void updateData() {
  if (sampleCount == 0) return;

  float avgPower = powerAccum / sampleCount;                 // W
  float unitsThisInterval = (avgPower * 30.0 / 3600.0) / 1000.0; // kWh for 30 sec
  float costThisInterval = unitsThisInterval * costPerUnit;

  totalUnits += unitsThisInterval;
  totalCost += costThisInterval;

  saveUnitDataToEEPROM();

  // Send to Blynk
  Blynk.virtualWrite(V0, String(emon.Vrms, 2));
  Blynk.virtualWrite(V1, String(emon.Irms * 1000, 2));
  Blynk.virtualWrite(V2, String(avgPower, 2));
  Blynk.virtualWrite(V3, String(totalUnits, 6));
  Blynk.virtualWrite(V4, String(totalCost, 6));

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(emon.Vrms, 2);
  lcd.print(" I:");
  lcd.print(emon.Irms * 1000, 2);

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(avgPower, 2);
  lcd.print(" U:");
  lcd.print(totalUnits, 2);

  Serial.printf("Updated: AvgP=%.2f W | +%.6f kWh | Rs %.6f | Total=%.6f kWh\n", 
                avgPower, unitsThisInterval, totalCost, totalUnits);

  powerAccum = 0.0;
  sampleCount = 0;
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  lcd.begin(16, 2);
  delay(100);       // Allow LCD time to initialize
  lcd.clear();

  EEPROM.begin(32);
  readUnitDataFromEEPROM();

  emon.voltage(35, vCalibration, 1.7); // Voltage: GPIO 35
  emon.current(34, currCalibration);  // Current: GPIO 34

  timer.setInterval(10000L, samplePower);   // Every 10 seconds
  timer.setInterval(30000L, updateData);    // Every 30 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}


