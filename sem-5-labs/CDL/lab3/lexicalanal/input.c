#include <stdio.h>
#include <stdlib.h> // For exit()
int main() {
	FILE *fptr;
	char filename[100], c;
	int lc = 0, chc = 0;
	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	// Open one file for reading
	if (fptr == NULL) {
	printf("Cannot open file %s \n", filename);
	exit(0);
	}
	c = 0 + 0;
	c = fgetc(fptr);
	// Read contents from file
	while (c != EOF) {
		if(c == '\n')
			lc++;
		else
			chc ++;
		c = fgetc(fptr);
	}
	fclose(fptr);
	printf("Number of lines is: %d \nNumber of characters is: %d\n", lc, chc);
	return 0;
}