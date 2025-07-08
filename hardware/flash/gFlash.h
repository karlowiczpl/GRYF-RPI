#ifndef HARDWARE_FLASH_H
#define HARDWARE_FLASH_H

#include <stdint.h>

typedef struct
{
  uint8_t id;
  uint8_t* ip[4];
  uint8_t* sn[4];
  uint8_t* gw[4];
}EEPROM_DATA_T;
extern EEPROM_DATA_T eeprom_data;

void write_eeprom();
void read_eeprom();

uint8_t* get_ip();
uint8_t* get_sn();
uint8_t* get_gw();

#endif // !HARDWARE_FLASH_H
