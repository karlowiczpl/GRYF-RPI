#include <stdint.h>
#include <stdio.h>

#include "gCommand_builder.h"

#include "GryfSmart_Config.h"

char status_command_buffor[STATUS_COMMAND_BUFFOR_SIZE];

const char inputStatePrefix[] = "I";
const char outputStatePrefix[] = "O";
const char shutterStatePrefix[] = "R";
const char tempStatePrefix[] = "T";
const char psStatePrefix[] = "PS";
const char plStatePrefix[] = "PL";

void build_input_status_command(uint8_t* states, uint8_t id)
{
  sprintf(status_command_buffor, "%s=%d,%d,%d,%d,%d,%d,%d,%d,%d\n\r",
          inputStatePrefix,
          id,
          states[0],
          states[1],
          states[2],
          states[3],
          states[4],
          states[5],
          states[6],
          states[7]
  );
}
void build_output_status_command(uint8_t* states, uint8_t id)
{
  #if GPIO_OUT_COUNT == 6
    sprintf(status_command_buffor, "%s=%d,%d,%d,%d,%d,%d,%d\n\r",
            outputStatePrefix,
            id,
            states[0],
            states[1],
            states[2],
            states[3],
            states[4],
            states[5]
    );
  #else
    sprintf(status_command_buffor, "%s=%d,%d,%d,%d,%d,%d,%d,%d,%d\n\r",
            outputStatePrefix,
            id,
            states[0],
            states[1],
            states[2],
            states[3],
            states[4],
            states[5],
            states[6],
            states[7]
    );
  #endif
}

void build_temperature_status_command(uint8_t* temp, uint8_t id, uint8_t pin)
{
  sprintf(status_command_buffor, "%s=%d,%d,%d,%d\n\r",
          tempStatePrefix,
          id,
          pin,
          temp[1],
          temp[0]
  );
}

void build_ps_status_command(uint8_t id, uint8_t pin)
{
  sprintf(status_command_buffor, "%s=%d,%d\n\r", psStatePrefix, id, pin);
}

void build_pl_status_command(uint8_t id, uint8_t pin)
{
  sprintf(status_command_buffor, "%s=%d,%d\n\r", plStatePrefix, id, pin);
}
