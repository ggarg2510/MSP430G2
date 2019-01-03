#include <msp430g2553.h>


/**
 * main.c
 */
void delay2(long i)
{
    while(i!=0)
        i--;
}
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR = 0b00000001;
	while(1)
	{
	    P1OUT = 0b00000001;
	    delay2(50000000);
        P1OUT = 0b00000000;
        delay2(50000000);
	}

	return 0;
}
