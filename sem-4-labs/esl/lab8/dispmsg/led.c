#include <lpc17xx.h>
#include "lcdfn.h"

int main(void) {
	unsigned char Msg1[7] = {"peepee"};
	unsigned char Msg2[7] = {"poopoo"};
	SystemInit();
	SystemCoreClockUpdate(); 
	lcd_init();
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg1[0]);
	lcd_comdata(0xC0, 0);
	delay_lcd(800);
	lcd_puts(&Msg2[0]);
}