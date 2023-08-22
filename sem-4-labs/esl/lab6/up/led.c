#include<LPC17xx.h>

unsigned int i,j;
unsigned long LED = 0x00000010;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	while(1)
	{
		for(i=0;i<256;i++)
		{
			LPC_GPIO0->FIOPIN=i<<4;
			for(j=0;j<50000;j++);
		}
	}
}