#ifndef HARDWARE_GPIO_INPUTS_H
#define HARDWARE_GPIO_INPUTS_H

#include <stdint.h>

#include "GryfSmart_Config.h"

void setup_io();

uint8_t update_inputs();
uint8_t update_outputs();

void gpio_set_out(uint8_t num, uint8_t state);

#endif // !HARDWARE_GPIO_INPUTS_H
