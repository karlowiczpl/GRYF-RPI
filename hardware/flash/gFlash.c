#include <string.h>
#include <stdint.h>

#include <hardware/flash.h>
#include <hardware/sync.h>

#include "gFlash.h"

#define FLASH_TARGET_OFFSET (256 * 1024)
const uint8_t* flash_target_contenst = (const uint8_t*)(XIP_BASE + FLASH_TARGET_OFFSET);

EEPROM_DATA_T eeprom_data;

void write_eeprom()
{
  uint32_t ints = save_and_disable_interrupts();
  
  flash_range_erase(FLASH_TARGET_OFFSET, 4096);
  flash_range_program(FLASH_TARGET_OFFSET, (const uint8_t*)&eeprom_data, sizeof(EEPROM_DATA_T));

  restore_interrupts(ints);
}

inline void set_eeprom_id(uint8_t id)
{
  eeprom_data.id = id;
  write_eeprom();
}

inline void read_eeprom()
{
  memcpy(&eeprom_data, flash_target_contenst, sizeof(EEPROM_DATA_T));

  if(eeprom_data.defatult)
  {
    write_default_settings();
    write_eeprom();
  }
}

static void write_default_settings()
{
  eeprom_data.id = 1;

  eeprom_data.ip[0] = 192;
  eeprom_data.ip[1] = 168;
  eeprom_data.ip[2] = 0;
  eeprom_data.ip[3] = 95;

  eeprom_data.gw[0] = 192;
  eeprom_data.gw[1] = 168;
  eeprom_data.gw[2] = 0;
  eeprom_data.gw[3] = 1;

  eeprom_data.sn[0] = 255;
  eeprom_data.sn[1] = 255;
  eeprom_data.sn[2] = 255;
  eeprom_data.sn[3] = 0;

  for(uint8_t i = 0; i < GPIO_IN_COUNT; i++)
  {
    eeprom_data.inputs_negation[i] = 0;
    eeprom_data.input_pl_time[i] = 200;
    eeprom_data.input_ps_time[i] = 50;
  }

  eeprom_data.defatult = 0;
}

inline uint8_t* get_sn()
{
  return eeprom_data.sn;
}

inline uint8_t* get_ip()
{
  return eeprom_data.ip;
}

inline uint8_t* get_gw()
{
  return eeprom_data.gw;
}
