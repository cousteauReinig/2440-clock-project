#include <stdint.h>
#include "msp432p401r.h"

/*
 * RTCconfig.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Cousteau
 */

#ifndef RTCCONFIG_H_
#define RTCCONFIG_H_

void RTC_Setup(void);

void RtcInteruptHandler(void);


#endif /* RTCCONFIG_H_ */
