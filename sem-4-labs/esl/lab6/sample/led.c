#include <LPC17xx.h>

unsigned int i,j; 
unsigned long LED = 0x00000010;

int main(void)
{
	SystemInit(); //Add these two function for its internal operation
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
		//Configure Port0 PINS P0.4-P0.11 as GPIO function
	LPC_GPIO0->FIODIR |= 0x00000FF0;
		//Configure P0.4-P0.11 as output port 
	while(1)
	{
		LED = 0x00000010; //Initial value on LED 
		for(i=1;i<9;i++) //On the LED's serially
		{
			LPC_GPIO0->FIOSET = LED; 
				// Turn ON LED at LSB (LED connected to p0.4) 
			for(j=0;j<10000;j++);//a random delay
			LED <<= 1; //Shift the LED to the left by one unit
		} //loop for 8 times
		LED = 0x00000010;
		for(i=1;i<9;i++) //Off the LED's serially
		{
			LPC_GPIO0->FIOCLR = LED;
				//Turn OFF LED at LSB (LED connected to p0.4)
			for(j=0;j<10000;j++);
			LED <<= 1;
		}
	}
}