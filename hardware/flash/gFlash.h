#ifndef HARDWARE_FLASH_H
#define HARDWARE_FLASH_H

#include <stdint.h>

#include <GryfSmart_Config.h>

typedef struct
{
  uint8_t id;
  uint8_t ip[4];
  uint8_t sn[4];
  uint8_t gw[4];
  uint8_t inputs_negation[GPIO_IN_COUNT];
  uint8_t input_ps_time[GPIO_IN_COUNT];
  uint8_t input_pl_time[GPIO_IN_COUNT];

  uint8_t defatult;
}EEPROM_DATA_T;
extern EEPROM_DATA_T eeprom_data;

void write_eeprom();
void read_eeprom();

uint8_t* get_ip();
uint8_t* get_sn();
uint8_t* get_gw();

static void write_default_settings();

#endif // !HARDWARE_FLASH_H
