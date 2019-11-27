#include "UART1config.h"
#include "msp.h"
#include <stdint.h>




void sendbyte(uint8_t data){
    while(!(EUSCI_A0 -> IFG & EUSCI_A_IFG_TXIFG)); //delay while there is something in the buffer
    //EUSCI_A0 -> TXBUF = data; //send data to buffer
    UCA0TXBUF = data;
}


void configUARTRed(void){

    EUSCI_A0 -> CTLW0 |= EUSCI_A_CTLW0_SWRST; //set UCSWRST
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_PEN; //disable parity
    EUSCI_A0 -> CTLW0 &= ~EUSCI_B_CTLW0_MSB; //configure MSB or LSB*************
    EUSCI_A0 -> CTLW0 &= ~EUSCI_B_CTLW0_SEVENBIT; //8 data bits
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_SPB; //1 stop bit
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_MODE_MASK; //select UART mode, we might want automatic baud rate detection
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_SYNC; //asynchronous
    EUSCI_A0 -> CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK; //select SMCLK
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_DORM; //not dormant

    EUSCI_A0 -> BRW = 0x4E; //78
    EUSCI_A0 -> MCTLW |= (0x02 << EUSCI_A_MCTLW_BRF_OFS) | EUSCI_A_MCTLW_OS16; //set UCBRF = 2, UCOS16 = 1
    EUSCI_A0 -> MCTLW &= ~EUSCI_A_MCTLW_BRS_MASK; // UCBRS = 0x00

    EUSCI_A0 -> IE |= EUSCI_A_IE_TXIE;  //enable transmit interrupt

    P3->SEL0 |= (BIT3);
    P3->SEL1 &= ~(BIT3);
    EUSCI_A0 -> MCTLW &= ~EUSCI_A_CTLW0_SWRST; //reset UCSWRST

}


void configUARTBlue(void){

    EUSCI_A0 -> CTLW0 |= EUSCI_A_CTLW0_SWRST; //set UCSWRST
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_PEN; //disable parity
    EUSCI_A0 -> CTLW0 |= EUSCI_B_CTLW0_MSB; //configure MSB or LSB*************
    EUSCI_A0 -> CTLW0 &= ~EUSCI_B_CTLW0_SEVENBIT; //8 data bits
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_SPB; //1 stop bit
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_MODE_MASK; //select UART mode, we might want automatic baud rate detection
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_SYNC; //asynchronous
    EUSCI_A0 -> CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK; //select SMCLK
    EUSCI_A0 -> CTLW0 &= ~EUSCI_A_CTLW0_DORM; //not dormant

    EUSCI_A0 -> BRW = 0x4E; //78
    EUSCI_A0 -> MCTLW |= (0x02 << EUSCI_A_MCTLW_BRF_OFS) | EUSCI_A_MCTLW_OS16; //set UCBRF = 2, UCOS16 = 1
    EUSCI_A0 -> MCTLW &= ~EUSCI_A_MCTLW_BRS_MASK; // UCBRS = 0x00

    EUSCI_A0 -> IE |= EUSCI_A_IE_TXIE;  //enable transmit interrupt

    P9->SEL0 |= (BIT6);
    P9->SEL1 &= ~(BIT6);
    EUSCI_A0 -> MCTLW &= ~EUSCI_A_CTLW0_SWRST; //reset UCSWRST

}



/*
 *  # load all the characters being sent
 * for i in rtc:
 *      tx_buffer[i] = i;
 *  # send all the characters over UART
 *  send_bytes(tx_buffer);
 */

/*
 * send(RTC->HOURS);
 * send(RTC->MINS);
 */


// uint8_t rx_counter = 0;
// uint8_t rx_buffer[10];

//**88888888888888888888888888888888888888
//void EUSCIA0_IRQHandler(void) {
//    if(EUSCI->IFG & TXIFG) {

//    }
//    if(EUSCI->IFG & RXIFG) {
        // read from RXBUFFER
        // put data somewhere
        // RTC stuff here --> could be long
//    }


//}
