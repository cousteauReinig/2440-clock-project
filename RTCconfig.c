#include "RTCconfig.h"
/*
 * RTCconfig.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Cousteau
 */

void RTC_Setup(void)
{

    // Configure RTC
    RTCCTL0_H = RTCKEY_H;                 // Unlock RTC key
    RTCCTL0_L |= RTCTEVIE ;                 /*!< Real-time clock time event interrupt enable */
    RTCCTL0_L |= RTCTEVIFG;              // Real-time clock time event interrupt flag,time event occurred
    //In LPM3, all of the RTC register values are retained due to state retention. This section describes only the entry into LPM3.5,
    //because most of the RTC configuration registers are lost. In LPM3.5, only the counters and calibration registers are retained.
    RTCCTL1 = RTCTEV_0; //1 minute change,
    RTCCTL1 = RTCBCD ;  //BCD data type

//
//    RTCHOUR = hour;
//    RTCMIN = min;
//    RTCSEC = sec;




    //RTCCTL0_H = 0;                            // lock it.This register should be written with A5h to unlock RTC.
                                               // Any write with value other than A5h locks the module. Reads from this register always return 96h.

    RTCCTL1 &= ~(RTCHOLD);                    // Start RTC calendar mode

}



void RtcInteruptHandler(void)
{

    if ( RTCTEVIFG) //interrupt happens
    {
        //RTCCTL0_H = RTCKEY;//unlock, to prevent get locked.


        //do something we want, highlighted!


        RTCCTL0_L &= ~RTCTEVIFG; //clear the flag
        //RTCCTL0_H = 0; //lock it. This register should be written with A5h to unlock RTC.
                       // Any write with value other than A5h locks the module. Reads from this register always return 96h.
    }

}
