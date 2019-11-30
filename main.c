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

	while(1){
	    //uint8_t i;
	    //for(i=0;i<100;i++){ //delay
	uint8_t data0 = 0b00000101;
	sendbyte(data0);
	int p;
	for(p=0;p<10000;p++);

	   //}
	//uint8_t data1 = 0x76;
	//sendbyte(data1);
	}
//	uint8_t data2 = 0b10101111;
//	sendbyte(data2);
//	uint8_t data3 = 0b10101111;
//	sendbyte(data3);
//	uint8_t data4 = 0b10101111;
//	sendbyte(data4);
}
