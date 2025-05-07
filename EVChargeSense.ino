#include <Wire.h>
#include <INA219.h>

#define SHUNT_MAX_V 0.01
#define BUS_MAX_V   16.0
#define MAX_CURRENT 20
#define SHUNT_R   0.015

INA219 monitor;

void setup() {
  Serial.begin(57600);
  monitor.begin();
  monitor.configure(INA219::RANGE_16V, INA219::GAIN_2_80MV, INA219::ADC_64SAMP, INA219::ADC_64SAMP, INA219::CONT_SH_BUS);
  monitor.calibrate(SHUNT_R, SHUNT_MAX_V, BUS_MAX_V, MAX_CURRENT);
}

void loop() {
  float voltage = monitor.busVoltage();
  //Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.println("");
  delay(1000);
}
