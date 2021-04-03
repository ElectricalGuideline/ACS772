#include "ACS772.h"
ACS772 sensor(ACS772ECB_250U_PF, A1);
void setup() {
  Serial.begin(9600);
  sensor.calibrate();
}
void loop() {
  float I = sensor.getCurrentDC();
  Serial.println(String("I = ") + I + " A");
  delay(1000);
}
