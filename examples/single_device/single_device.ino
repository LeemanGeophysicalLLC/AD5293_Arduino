#include "AD5293.h"

const uint8_t CS_PIN = 6;
AD5293 digPot;

void setup() {
  Serial.begin(115200);
  digPot.begin(1, CS_PIN);
  Serial.println("Setup complete!");
}

void loop() {
  Serial.println("Enabling write.");
  digPot.configure(0, 0, 1); // First device in performance mode and write enabled
  Serial.println("Setting to position 0");
  digPot.setWiperPosition(0, 0);
  delay(5000);
  Serial.println("Setting to position 256");
  digPot.setWiperPosition(0, 256);
  delay(5000);
  Serial.println("Setting to position 512");
  digPot.setWiperPosition(0, 512);
  delay(5000);
  Serial.println("Setting to position 1023");
  digPot.setWiperPosition(0, 1023);
  delay(5000);
}
