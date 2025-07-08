#include <stdint.h>

#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/irq.h>

#include "gUart.h"

#include "GryfSmart_Config.h"

UART_DATA_T uart_data;

void setup_uart()
{
  uart_data.buf_num = 0;
  uart_data.buf_index = 0;

  uart_init(UART_CELL, UART_BAUDRATE);

  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

  irq_set_exclusive_handler(UART_IRQ_HANDLER, on_uart_rx);
  irq_set_enabled(UART_IRQ_HANDLER, true);
  uart_set_irqs_enabled(UART_CELL, true, false);
}

void uart_send(char* c_str)
{
  uart_puts(UART_CELL, c_str);
}

static void on_uart_rx()
{
  while(uart_is_readable(uart0))
  {
    char c = uart_getc(UART_CELL);

    if(c ==  '\n')
    {
      uart_data.buf[uart_data.buf_num][uart_data.buf_index] = '\0';
      uart_data.buf_index = 0;
      
      if(uart_data.buf_num <= UART_BUF_COUNT)     uart_data.buf_num++;
    }
    else
    {
      if(uart_data.buf_index < UART_BUFFER_SIZE - 1)
      {
        uart_data.buf[uart_data.buf_num][uart_data.buf_index++] = c;
      }
      else
      {
        // error 
        
        uart_data.buf_index = 0;
      }
    }
  }
}
