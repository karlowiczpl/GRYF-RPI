#include <pico/time.h>
#include <stdint.h>
#include <stdio.h>

#include <pico/stdlib.h>
#include <pico/multicore.h>

#include "gUart.h"
#include "gIo.h"
#include "gCommand_builder.h"
#include "gFlash.h"

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
    if(uart_data.buf_num)
    {
      printf("UART BUFFOR: \n");
      for(uint8_t i = 0; i < 5; i++)
      {
        if(uart_data.buf[i][0] != '\0')     printf("%s\n", uart_data.buf[i]);
      }
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
