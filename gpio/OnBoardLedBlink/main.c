#include <msp430g2553.h>


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR = 0b00000001;
	P1OUT = 0b00000001;

	return 0;
}
