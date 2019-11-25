#include "msp.h"
#include <stdio.h>
#include <stdint.h>
#include "UART1config.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	configUARTRed();
	uint8_t data = 0b10101111;
	sendbyte(data);
}
