#ifndef HARDWARE_FLASH_H
#define HARDWARE_FLASH_H

#include <stdint.h>

typedef struct
{
  uint8_t id;
}EEPROM_DATA_T;

extern EEPROM_DATA_T eeprom_options;

void write_eeprom();
void read_eeprom();

#endif // !HARDWARE_FLASH_H
