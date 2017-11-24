#include "AD5293.h"
#include "SPI.h"

const uint8_t CS_PIN = 6;
AD5293 digPot;

void setup() {
  Serial.begin(115200);
  digPot.begin(1, CS_PIN);
  Serial.println("Setup complete!");
  Serial.println("Enabling write.");
  digPot.configure(0, 0, 1); // First device in performance mode and write enabled
}

void loop() {
  for (int i=0; i<1024; i++){
    Serial.println(i);
    digPot.setWiperPosition(0, i);
    delay(100);
  }
}
