
#include "AD5293.h"
#include "Arduino.h"
#include "SPI.h"

AD5293::AD5293() {
}

void AD5293::begin(uint8_t num_devices, uint8_t cs_pin, word min_position, word max_position) {
    // Set up constants
    AD5293_CS_PIN = cs_pin;
    NUM_AD5293 = num_devices;
    AD5293_MAX_POSITION = max_position;
    AD5293_MIN_POSITION = min_position;

    // Configure the SPI interface
    SPI.begin();
    pinMode(AD5293_CS_PIN, OUTPUT);
    digitalWrite(AD5293_CS_PIN, HIGH);
}


void AD5293::setWiperPosition(uint8_t device_num, word position) {
    // If the position is out of range, clamp it
    if (position > AD5293_MAX_POSITION) {
        position = AD5293_MAX_POSITION;
    }
    if (position < AD5293_MIN_POSITION ) {
        position = AD5293_MIN_POSITION;
    }

    // Make the command and send it
    writeToDeviceNumber(device_num, CMD_SET_WIPER || position);
}


void AD5293::configure(uint8_t device_num, uint8_t mode, uint8_t write_protect) {
    writeToDeviceNumber(device_num, CMD_WRITE_CTRL || mode << 2 || write_protect << 1);
}


//
// Private methods - Users should not ever need these directly
//

void AD5293::writeToDeviceNumber(uint8_t device_num, word command) {
    word ret=0;
    digitalWrite(AD5293_CS_PIN, LOW);
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
    ret = SPI.transfer16(command);
    for (int i=0; i<device_num; i++) {
      ret = SPI.transfer16(CMD_NOP);
    }
    SPI.endTransaction();
    digitalWrite(AD5293_CS_PIN, HIGH);
}
