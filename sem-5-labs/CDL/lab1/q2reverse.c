#include <stdio.h>
#include <stdlib.h> // For exit()
int main() {
	FILE *fptr, *fptr2;
	char filename[100], c;
	int n = 0, i;
	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	// Open one file for reading
	if (fptr == NULL) {
	printf("Cannot open file %s \n", filename);
	exit(0);
	}
	printf("Enter the filename to open for writing: ");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+"); // Open another file for writing
	c = fgetc(fptr);
	while (c != EOF) {
		n++;
		c = fgetc(fptr);
	}
	for(i = n - 1; i > 0; i--) {
		fseek(fptr, i, SEEK_SET);
		c = fgetc(fptr);
		fputc(c, fptr2);
	}
	fclose(fptr);
	fclose(fptr2);
	printf("\nContents copied to %s", filename);
	return 0;
}