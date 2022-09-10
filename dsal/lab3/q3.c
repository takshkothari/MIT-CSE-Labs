#include<stdio.h>
#include<stdlib.h>
typedef struct Employee
{
	char name[100];
	struct DOB
	{
		int day;
		int month;
		int year;
	} DMY;
	struct address 
	{
		int housno;
		int zip;
		char state[100];
	}add;
};
void read ( struct Employee *p)
{	printf("Enter name: ");
	scanf("%s", p->name);
	printf("Enter date of birth: ");
	scanf("%d %d %d", &(p)->DMY.day, &(p)->DMY.month, &(p)->DMY.year);
	printf("Enter address (state,house-number, zip code) : ");
	scanf("%s %d %d", p->add.state, &(p)->add.housno, &(p)->add.zip);
}
void display(struct Employee *p)
{
	printf("Name: %s\n", p->name);
	printf("Date of Birth: %d/%d/%d\n",p->DMY.day, p->DMY.month, p->DMY.year);
	printf("Address: %d, %d, %s\n", p->add.housno, p->add.zip, p->add.state);
	printf("\n");
}
int main()
{
	int i, n;
	struct Employee *p;
	printf("Enter number of employees: ");
	scanf("%d", &n);
	p = (struct Employee*) malloc (n*sizeof(struct Employee));
	for (i=0; i<n; i++)
	{
		read(p+i);
		fflush(stdin);
	}	
	for (i=0; i<n; i++)
	{
		display(p+i);
}}