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



	int p;
//	for(p=0;p<100000;p++);
//while(1){
	sendbyte(118);
    for(p=0;p<1000;p++);
    sendbyte(0x77);
    for(p=0;p<1000;p++);
    sendbyte(16);
	for(p=0;p<1000;p++);
    sendbyte(1);
    for(p=0;p<1000;p++);
    sendbyte(2);
    for(p=0;p<1000;p++);
    sendbyte(5);
    for(p=0;p<1000;p++);
    sendbyte(8);
//   for(p=0;p<100000;p++);
//}
//    sendbyte(2);
//    sendbyte(3);
//    sendbyte(4);
//    sendbyte(0x02);

//	for(p=0;p<1000000;p++);
//    uint8_t datac = 0x76;
//    sendbyte(datac);
//    for(p=0;p<1000000;p++);
//    sendbyte(data1);
	while(1);


}
