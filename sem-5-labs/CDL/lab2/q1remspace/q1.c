#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fa, *fb;
	int c;
	fa = fopen("q1in.c", "r");
	if (fa == NULL) {
		printf("Cannot open file \n");
		exit(0); 
	}
	fb = fopen("q1out.c", "w");
	c = getc(fa);
	while (c != EOF) {
		if(c == '\t' || c == ' ') {
			putc(' ', fb);
			while(c == ' ' || c == '\t')
				c = getc(fa);
			putc(c, fb);
		}
		else putc(c, fb);
		c = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}