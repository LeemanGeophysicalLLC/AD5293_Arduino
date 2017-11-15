#ifndef AD5293_h
#define AD5293_h

#include "Arduino.h"

// Commands
#define CMD_NOP 0x0000
#define CMD_SET_WIPER 0x0400
#define CMD_WRITE_CTRL 0x1800

class AD5293 {
public:
    AD5293();
    uint8_t AD5293_CS_PIN;
    uint8_t NUM_AD5293;
    word AD5293_MAX_POSITION;
    word AD5293_MIN_POSITION;

    void begin(uint8_t num_devices, uint8_t cs_pin, word min_position=0, word max_position=1023);
    void setWiperPosition(uint8_t device_num, word position);
    void configure(uint8_t device_num, uint8_t mode, uint8_t write_protect);

private:
    void writeToDeviceNumber(uint8_t device_num, word command);

};
#endif
