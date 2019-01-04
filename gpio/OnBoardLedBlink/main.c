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
