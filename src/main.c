#include <pico/time.h>
#include <stdint.h>
#include <stdio.h>

#include <pico/stdlib.h>

#include "gFlash.h"

int main()
{
  stdio_init_all();

  sleep_ms(2000);

  // set_eeprom_id(1);
  //
  // for(uint8_t i = 0; i < 10; i++)
  // {
  //   uint8_t id = get_id();
  //   printf("id: %d\n", id);
  //
  //   set_eeprom_id(id + 1);
  // }
  // 
  // EEPROM_OPTIONS_T sdadsa;
}
