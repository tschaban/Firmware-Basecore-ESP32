#ifndef _ESP_DEVICE_Structure_h
#define _ESP_DEVICE_Structure_h

#include "arduino.h"

#include <Configuration.h>


struct DEVICE {
  char name[33];
#ifdef ESP_CONFIG_HARDWARE_I2C
  uint8_t noOfI2Cs;
#endif
#ifdef ESP_CONFIG_HARDWARE_UART
  uint8_t noOfUARTs;
#endif
#ifdef ESP_CONFIG_HARDWARE_SWITCH
  uint8_t noOfSwitches;
#endif
#ifdef ESP_CONFIG_HARDWARE_LED
  uint8_t noOfLEDs;
#endif
#ifdef ESP_CONFIG_HARDWARE_ADC
  uint8_t noOfADCs;
#endif
#ifdef ESP_CONFIG_HARDWARE_SENSOR_BINARY
  uint8_t noOfBinarySensors;
#endif

};

#endif