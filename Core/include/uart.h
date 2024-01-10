#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#include <stdint.h>

char uart2_read(void);
void uart2_rxtx_init(void);
void uart2_tx_init(void);


#endif
