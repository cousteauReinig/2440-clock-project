# 2440-clock-project
This code configures registers on the MSP432 to communicate with two peripherals using the UART communication protocol.
Information about the MSP432P401R can be found in the technical reference manual https://www.ti.com/lit/ug/slau356i/slau356i.pdf
and the datasheet http://www.ti.com/lit/ds/symlink/msp432p401r.pdf

This repository contains the main.c which calls our configuration files: RTCconfig.c RTCconfig.h UART1config.c UART1config.h
as well as some example arduino code that we used for testing in hm-10Arduino.ino
