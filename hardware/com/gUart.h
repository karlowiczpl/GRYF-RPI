#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

#define UART_BUFFER_SIZE 50
#define UART_BUF_COUNT 5

typedef struct
{
  volatile char buf[UART_BUF_COUNT][UART_BUFFER_SIZE];
  volatile uint8_t buf_index;
  volatile uint8_t buf_num;
}UART_DATA_T;

extern UART_DATA_T uart_data;

void setup_uart();
void uart_send(char* c_str);

static void on_uart_rx();

#endif // !UART_H
