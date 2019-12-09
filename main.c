#include "msp.h"
#include <stdio.h>
#include <stdint.h>
#include "UART1config.h"
#include "RTCconfig.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	configUARTRed();
	RTC_Setup();

	int k;
	for(k=0;k<1000;k++);
    sendbyte(0x76);

	int state = 1;

	uint8_t dataIn1 = 1;
	uint8_t dataIn2 = 2;
	uint8_t dataIn3 = 1;
	uint8_t dataIn4 = 7;

	while(state == 1){
	if(EUSCI_A3 -> IFG & EUSCI_A_IFG_RXIFG){
	dataIn1 = EUSCI_A3 -> RXBUF;
	state = 2;
	    }
	}
    while(state == 2){
    if(EUSCI_A3 -> IFG & EUSCI_A_IFG_RXIFG){
    dataIn2 = EUSCI_A3 -> RXBUF;
    state = 3;
        }
    }
    while(state == 3){
    if(EUSCI_A3 -> IFG & EUSCI_A_IFG_RXIFG){
    dataIn3 = EUSCI_A3 -> RXBUF;
    state = 4;
        }
    }
    while(state == 4){
    if(EUSCI_A3 -> IFG & EUSCI_A_IFG_RXIFG){
    dataIn4 = EUSCI_A3 -> RXBUF;
    state = 5;
        }
    }
//************************** Hard-coding option
//    dataIn1 = 1;
//    dataIn2 = 2;
//    dataIn3 = 1;
//    dataIn4 = 7;
//**************************

	//convert HEX input to BCD

	uint8_t hourBCD = (dataIn1 << 4) | dataIn2;
	uint8_t minBCD = (dataIn3 << 4) | dataIn4;


    RTCHOUR = hourBCD;
    RTCMIN = minBCD;
    //RTCSEC = 0;




    while(state == 5){

        int p;

        for(p=0;p<1000;p++);
        sendbyte(0x76);

        for(p=0;p<1000;p++);
        sendbyte(0x77);
        for(p=0;p<1000;p++);
        sendbyte(16);

    uint8_t dataMin = RTCMIN;
    uint8_t dataHour = RTCHOUR;

    uint8_t dataHourLow = (dataHour & 0b00001111);
    uint8_t dataHourHigh = (dataHour >> 4);

    uint8_t dataMinLow = (dataMin & 0b00001111);
    uint8_t dataMinHigh = (dataMin >> 4);

    for(p=0;p<1000;p++);
    sendbyte(dataHourHigh);
    for(p=0;p<1000;p++);
    sendbyte(dataHourLow);
    for(p=0;p<1000;p++);
    sendbyte(dataMinHigh);
    for(p=0;p<1000;p++);
    sendbyte(dataMinLow);
    }
}
