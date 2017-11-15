#include "AD5293.h"

const uint8_t CS_PIN = 6;
AD5293 digPot;

void setup() {
  Serial.begin(115200);
  digPot.begin(3, CS_PIN);
  Serial.println("Setup complete!");
}

void loop() {
  Serial.println("Enabling write.");
  digPot.configure(0, 0, 1); // First device in performance mode and write enabled
  digPot.configure(1, 0, 1); // Second device in performance mode and write enabled
  digPot.configure(2, 0, 1); // Third device in performance mode and write enabled

  Serial.println("Setting to position 0, 256, 512");
  digPot.setWiperPosition(0, 0);
  digPot.setWiperPosition(1, 256);
  digPot.setWiperPosition(2, 512);
  delay(5000);

  Serial.println("Setting to position 256, 512, 1023");
  digPot.setWiperPosition(0, 256);
  digPot.setWiperPosition(1, 512);
  digPot.setWiperPosition(2, 1023);
  delay(5000);

  Serial.println("Setting to position 512, 1023, 0");
  digPot.setWiperPosition(0, 512);
  digPot.setWiperPosition(1, 1023);
  digPot.setWiperPosition(2, 0);
  delay(5000);

  Serial.println("Setting to position 1023, 0, 256");
  digPot.setWiperPosition(0, 1023);
  digPot.setWiperPosition(1, 0);
  digPot.setWiperPosition(2, 256);
  delay(5000);
}
