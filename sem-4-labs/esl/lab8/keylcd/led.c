#include <LPC17xx.h>
#include "lcdfn.h" // use all the functions of lcd program

void scan(void);
unsigned char Msg1[13] = "KEY PRESSED=";
unsigned char row, var, flag, key;
unsigned long int i, var1, temp, temp1, temp2, temp3;
unsigned char SCAN_CODE[16] = {0x11,0x21,0x41,0x81,
															0x12,0x22,0x42,0x82,
															0x14,0x24,0x44,0x84,
															0x18,0x28,0x48,0x88};
unsigned char ASCII_CODE[16] = {'0','1','2','3',
																'4','5','6','7',
																'8','9','A','B',
																'C','D','E','F'};

int main(void) {
	LPC_GPIO2->FIODIR |= 0x00003C00; //made output P2.10 to P2.13 (rows)
	LPC_GPIO1->FIODIR &= 0xF87FFFFF; //made input P1.23 to P1.26(cols) ;not required since it is by default
	LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
	clear_ports();
	delay_lcd(3200);
	lcd_init();
	lcd_comdata(0x80, 0); //point to first line of LCD
	delay_lcd(800);
	lcd_puts(&Msg1[0]); //display the message
	while(1) {
		while(1) {
			for(row=1;row<5;row++) {
				if(row == 1)
					var1 = 0x00000400;
				else if(row == 2)
					var1 = 0x00000800;
				else if(row == 3)
					var1 = 0x00001000;
				else if(row == 4)
					var1 = 0x00002000;
				temp = var1;
				LPC_GPIO2->FIOCLR = 0x00003C00; //first clear the port and send appropriate value for
				LPC_GPIO2->FIOSET = var1; //enabling the row
				flag = 0;
				scan(); //scan if any key pressed in the enabled row
				if(flag == 1)
					break;
			} //end for
			if(flag == 1)
				break;
		} //2nd while(1)
		for(i=0;i<16;i++) {//get the ascii code for display
			if(key == SCAN_CODE[i]) {
				key = ASCII_CODE[i];
				break;
			} //end if(key == SCAN_CODE[i]) 
			}//end for(i=0;i<16;i++)
		lcd_comdata(0xc0, 0);//display in the second line
		delay_lcd(800);
		lcd_puts(&key);
	}//end while 1
}//end main
void scan(void) {
	temp3 = LPC_GPIO1->FIOPIN;
	temp3 &= 0x07800000; //check if any key pressed in the enabled row
	if(temp3 != 0x00000000) {
		flag = 1;
		temp3 >>= 19;//Shifted to come at HN of byte
		temp >>= 10; //shifted to come at LN of byte
		key = temp3|temp; //get SCAN_CODE
	}//if(temp3 != 0x00000000)
}//end scan