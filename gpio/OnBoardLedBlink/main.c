#include <msp430g2553.h>


/**
 * main.c
 */
/**
 *  MSP430G2X53 Series Mixed Signal Microcontroller
 *  ===============================================
 *
 *                                                     ____________
 *                                               DVCC |1    o    20| DVSS
 *                            P1.0/TA0CLK/ACLK/A0/CA0 |2         19| XIN/P2.6/TA0.1
 *                 P1.1/TA0.0/UCA0RXD/UCA0SOMI/A1/CA1 |3         18| XOUT/P2.7
 *                 P1.2/TA0.1/UCA0TXD/UCA0SIMO/A2/CA2 |4         17| TEST/SBWTCK
 *            P1.3/ADC10CLK/CAOUT/VREF-/VEREF-/A3/CA3 |5         16| RST-B/NMI/SBW/TDIO
 * P1.4/SMCLK/UCB0STE/UCA0CLK/VREF+/VEREF+/A4/CA4/TCK |6         15| P1.7/CAOUT/UCB0SIMO/UCB0SDA/A7/CA7/TDO/TDI
 *              P1.5/TA0.0/UCB0CLK/UCA0STE/A5/CA5/TMS |7         14| P1.6/TA0.1/UCB0SOMI/UCB0SCL/A6/CA6/TDI/TCLK
 *                                         P2.0/TA1.0 |8         13| P2.5/TA1.2
 *                                         P2.1/TA1.1 |9         12| P2.4/TA1.2
 *                                         P2.2/TA1.1 |10        11| P2.3/TA1.0
 *                                                    |____________|
 *
 */

/**
 *   ----+-------------+-----------------------------------------------------------------------------------------------+-
 *    S# |  REGISTER   |  DESCRIPTION                                                                                  |
 *   ----+-------------+-----------------------------------------------------------------------------------------------+-
 *    01 |   PxIN      | Each Bit in each PxIN register reflects the value of the input signal at the corresponding    |
 *       |             | I/O pin when the pin is configured as I/O function.                                           |
 *       |             | Bit = 0 ==> The input is Low                                                                  |
 *       |             | Bit = 1 ==> The input is High                                                                 |
 *       |             | (Writing to Read Only pins will leads to increase in current consumption)                     |
 *       |             |                                                                                               |
 *    02 |   PxOUT     | Each Bit in each PxOUT register is the value to be output on the corresponding I/O pin when   |
 *       |             | the pin is configured as I/O function, output direction and Pull up/down resistor is disabled |
 *       |             | Bit = 0 ==> The output is Low                                                                 |
 *       |             | Bit = 1 ==> The output is High                                                                |
 *       |             |                                                                                               |
 *       |             | If the pin's pull up/down resistor is enabled, the corresponding bit in the PxOUT register    |
 *       |             | selects PullUp or PullDown                                                                    |
 *       |             | Bit = 0 ==> The pin is pulled down                                                            |
 *       |             | Bit = 1 ==> The pin is pulled up                                                              |
 *       |             |                                                                                               |
 *    03 |   PxDIR     | Each Bit in each PxDIR register selects the direction of the corresponding I/O pin, regardless|
 *       |             | of the selected function of the pin. PxDIR bits for the I/O that are selected for other       |
 *       |             | functions must be set as required by the other function                                       |
 *       |             | Bit = 0 ==> The Port Pin is switched to input direction                                       |
 *       |             | Bit = 1 ==> The Port Pin is switched to output direction                                      |
 *       |             |                                                                                               |
 *    04 |   PxREN     |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *    05 |   PxSEL     |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *    06 |   PxSEL2    |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *       |             |                                                                                               |
 *
 *
 */

/*
 *
 * */

void delay2(long i)
{
    while(i!=0)
        i--;
}
void config_clock()
{
     // Set system DCO to 8MHz
     BCSCTL1 = CALBC1_8MHZ;
     DCOCTL = CALDCO_8MHZ;

     // Set LFXT1 to the VLO @ 12kHz
     BCSCTL3 |= LFXT1S_2;
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	config_clock();
	P1DIR = 0b01000001;
	while(1)
	{
	    int i=0;
	    P1OUT = 0b00000001;
	    for(i=0; i<30000; i++){if(i==5000) i = 5005;}

//	    delay2(50000000);
        P1OUT = 0b01000000;
        for(i=0; i<30000; i++){if(i==5000) i = 5005;}
  //      delay2(50000000);
	}

	return 0;
}
