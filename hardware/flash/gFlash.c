// #include <string.h>
// #include <stdint.h>
//
// #include <hardware/flash.h>
// #include <hardware/sync.h>
//
// #include "gFlash.h"
//
//
// #define FLASH_TARGET_OFFSET (256 * 1024)
// const uint8_t* flash_target_contenst = (const uint8_t*)(XIP_BASE + FLASH_TARGET_OFFSET);
//
// EEPROM_DATA_T eeprom_options;
//
// inline void write_eeprom_options()
// {
//   uint32_t ints = save_and_disable_interrupts();
//   
//   flash_range_erase(FLASH_TARGET_OFFSET, 4096);
//   flash_range_program(FLASH_TARGET_OFFSET, (const uint8_t*)&eeprom_data, sizeof(EEPROM_OPTIONS_T));
//
//   restore_interrupts(ints);
// }
//
// inline void set_eeprom_id(uint8_t id)
// {
//   is_readed_options();
//
//   eeprom_options.id = id;
//   write_eeprom_options();
// }
//
// uint8_t get_id()
// {
//   is_readed_options();
//
//   return eeprom_options.id;
// }
//
// static inline void read_eeprom()
// {
//   memcpy(&eeprom_options, flash_target_contenst_options, sizeof(EEPROM_OPTIONS_T));
// }
