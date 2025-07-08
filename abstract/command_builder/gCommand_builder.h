#ifndef ABSTRACT_COMMAND_BUILDER_H
#define ABSTRACT_COMMAND_BUILDER_H

#include <stdint.h>

#define STATUS_COMMAND_BUFFOR_SIZE 50

extern char status_command_buffor[STATUS_COMMAND_BUFFOR_SIZE];

void build_input_status_command(uint8_t* states, uint8_t id);
void build_output_status_command(uint8_t* states, uint8_t id);
void build_temperature_status_command(uint8_t* temp, uint8_t id, uint8_t pin);

#endif // !ABSTRACT_COMMAND_BUILDER_H
