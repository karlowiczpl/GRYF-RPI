#include <stdint.h>

#include <hardware/gpio.h>
#include <pico/time.h>

#include "GryfSmart_Config.h"

#include "gIo.h"
#include "abstract/command_builder/gCommand_builder.h"
#include "gFlash.h"
#include "gUart.h"

uint8_t input_states[8] = {0};
uint8_t output_states[8] = {0};

const uint8_t input_pins[GPIO_IN_COUNT] = GPIO_IN_PINS;
const uint8_t output_pins[GPIO_OUT_COUNT] = GPIO_OUT_PINS;

absolute_time_t last_change_time[GPIO_IN_COUNT];
uint8_t pl_enabled[GPIO_IN_COUNT] = {0};

void setup_io()
{
  for(uint8_t i = 0; i < GPIO_IN_COUNT; i++)
  {
    gpio_init(input_pins[i]);
    gpio_set_dir(input_pins[i], GPIO_IN);

    input_states[i] = gpio_get(input_pins[i]);
    last_change_time[i] = get_absolute_time();
  }
  for(uint8_t i = 0; i < GPIO_OUT_COUNT; i++)
  {
    gpio_init(output_pins[i]);
    gpio_set_dir(output_pins[i], GPIO_OUT);

    output_states[i] = gpio_get_out_level(output_pins[i]);
  }

  build_input_status_command(input_states, eeprom_data.id);     
  uart_send(status_command_buffor);
}

uint8_t update_inputs()
{
  for(uint8_t i = 0; i < GPIO_IN_COUNT; i++)
  {
    if(gpio_get(input_pins[i]) != input_states[i])
    {
      if(absolute_time_diff_us(last_change_time[i], get_absolute_time()) >= DEBOUNCE_TIME_US)
      {
        input_states[i] = !input_states[i];
        check_ps(i);
        last_change_time[i] = get_absolute_time();
        pl_enabled[i] = 1;

        for(uint8_t j = i; j < GPIO_IN_COUNT; j++)    
        {
          if(absolute_time_diff_us(last_change_time[j], get_absolute_time()) >= DEBOUNCE_TIME_US && input_states[j] != gpio_get(input_pins[j]))
          {
            input_states[j] = gpio_get(input_pins[j]);
            check_ps(j);
            last_change_time[j] = get_absolute_time();
            pl_enabled[j] = 1;
          }


          check_pl();
          return 1;
        }
      }
    }
  }

  check_pl();
  return 0;
}

uint8_t update_outputs()
{
  for(uint8_t i = 0; i < GPIO_OUT_COUNT; i++)
  { if(gpio_get_out_level(output_pins[i]) != output_states[i])
    {
      output_states[i] = !output_states[i];
      for(uint8_t j = i; j < GPIO_OUT_COUNT; j++)   output_states[j] = gpio_get_out_level(output_pins[j]);

      return 1;
    }
  }

  return 0;
}

void gpio_set_out(const uint8_t num, const uint8_t state)
{
  if(state == 3)
  {
    gpio_put(output_pins[num], !gpio_get_out_level(output_pins[num]));
  }
  else if(state != 0)
  {
    gpio_put(output_pins[num], state == 1 ? 1 : 0);
  }
}

void check_ps(const uint8_t num)
{
  if(input_states[num] == eeprom_data.inputs_negation[num])
  {
    if(absolute_time_diff_us(last_change_time[num], get_absolute_time()) <= (eeprom_data.input_ps_time[num] * 10000))
    {
      build_ps_status_command(eeprom_data.id, num + 1);     
      uart_send(status_command_buffor);
    }
  }
}

static void check_pl()
{
  for(uint8_t i = 0; i < GPIO_IN_COUNT; i++)
  {
    if(input_states[i] != eeprom_data.inputs_negation[i] && 
      pl_enabled[i] && 
      absolute_time_diff_us(last_change_time[i], get_absolute_time()) >= (eeprom_data.input_pl_time[i] * 10000))
    {
      pl_enabled[i] = 0;

      build_pl_status_command(eeprom_data.id, i + 1);
      uart_send(status_command_buffor);
    }
  }
}
