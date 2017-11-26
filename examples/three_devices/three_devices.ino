#include "AD5293.h"

const uint8_t CS_PIN = 6;
AD5293 digPot;

void setup() {
  Serial.begin(115200);
  digPot.begin(3, CS_PIN);
  Serial.println("Setup complete!");
  digPot.configure(0, 0, 1); // First device in performance mode and write enabled
  digPot.configure(1, 0, 1); // Second device in performance mode and write enabled
  digPot.configure(2, 0, 1); // Third device in performance mode and write enabled
}

void loop() {
  Serial.println("Enabling write.");

  for (int i=0; i<1024; i++){
    Serial.println(i);
    // Uncomment to change a single pot
    //digPot.setWiperPosition(0, i);
    digPot.setWiperPosition(1, i);
    //digPot.setWiperPosition(2, i);
    delay(100);
  }
}
