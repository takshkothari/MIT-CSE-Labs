/ This is a single line comment

#include <stdio.h>
void main()
{
	FILE *fopen(), *fp;
	int c ;
	fp = fopen( “prog.c”, “r” ); 	
	c = getc( fp ) ;
	while ( c != EOF ) {
		putchar( c );
		c = getc ( fp );
	}
	
	fclose(fp );
}