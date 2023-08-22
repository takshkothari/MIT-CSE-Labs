#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fa, *fb;
	int c;
	fa = fopen("q2in.c", "r");
	if (fa == NULL) {
		printf("Cannot open file \n");
		exit(0); 
	}
	fb = fopen("q2out.c", "w");
	c = getc(fa);
	while (c != EOF) {
		if(c =='\"') {
			putc(c, fb);
			c = getc(fa);
			putc(c, fb);
			while(c != '\"') {
				c = getc(fa);
				putc(c, fb);
			}
		}
		else if(c == '#') {
			while(c != '\n')
				c = getc(fa);
			// putc(c, fb);
		}
		else putc(c, fb);
		c = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}