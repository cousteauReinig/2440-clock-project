

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "msp432p401r.h"

void sendbyte(uint8_t data);

void EUSCIA2_IRQHandler(void);

void configUARTRed(void);


void configUARTBlue(void);

#endif
