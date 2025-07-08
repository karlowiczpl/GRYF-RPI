#ifndef HARDWARE_GPIO_INPUTS_H
#define HARDWARE_GPIO_INPUTS_H

#include <stdint.h>

#include "GryfSmart_Config.h"

#define DEBOUNCE_TIME_US 20000

extern uint8_t input_states[8];
extern uint8_t output_states[8];

void setup_io();

uint8_t update_inputs();
uint8_t update_outputs();

void gpio_set_out(uint8_t num, uint8_t state);

#endif // !HARDWARE_GPIO_INPUTS_H
