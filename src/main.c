#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/multicore.h>

#include "AT-Commands-Lib/parser.h"
#include "gUart.h"
#include "gIo.h"
#include "gCommand_builder.h"
#include "gFlash.h"

#include "parser.h"

void communication_core();
void task_core();

int main()
{
  stdio_init_all();
  read_eeprom();

  multicore_launch_core1(communication_core);

  task_core();
}

void communication_core()
{
  setup_uart();

  while(1)
  {
    for(uint8_t i = 0; i < uart_data.buf_num; i++)
    {
      char at_command[50];
      strncpy(at_command, (const char*)uart_data.buf[i], sizeof(at_command) - 1);

      parse_at_command(at_command);
    }

    sleep_ms(5000);
  }
}

void task_core()
{
  setup_io();

  while(1)
  {
    if(update_inputs())
    {
      build_input_status_command(input_states, eeprom_data.id);
      uart_send(status_command_buffor);
    }
    
    if(update_outputs())
    {
      build_output_status_command(input_states, eeprom_data.id);
      uart_send(status_command_buffor);
    }
  }
}
