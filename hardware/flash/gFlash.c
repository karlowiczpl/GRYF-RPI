#include <string.h>
#include <stdint.h>

#include <hardware/flash.h>
#include <hardware/sync.h>

#include "gFlash.h"


#define FLASH_TARGET_OFFSET (256 * 1024)
const uint8_t* flash_target_contenst = (const uint8_t*)(XIP_BASE + FLASH_TARGET_OFFSET);

EEPROM_DATA_T eeprom_data;

void write_eeprom_options()
{
  uint32_t ints = save_and_disable_interrupts();
  
  flash_range_erase(FLASH_TARGET_OFFSET, 4096);
  flash_range_program(FLASH_TARGET_OFFSET, (const uint8_t*)&eeprom_data, sizeof(EEPROM_DATA_T));

  restore_interrupts(ints);
}

inline void set_eeprom_id(uint8_t id)
{
  eeprom_data.id = id;
  write_eeprom_options();
}

inline void read_eeprom()
{
  memcpy(&eeprom_data, flash_target_contenst, sizeof(EEPROM_DATA_T));
}

inline uint8_t* get_sn()
{
  return eeprom_data.sn[0];
}

inline uint8_t* get_ip()
{
  return eeprom_data.ip[0];
}

inline uint8_t* get_gw()
{
  return eeprom_data.gw[0];
}
