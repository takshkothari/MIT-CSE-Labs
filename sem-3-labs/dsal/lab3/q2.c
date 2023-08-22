#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char name[50];
	int roll;
	float cgpa;
}STUDENT;
void read(STUDENT* s,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter Name :");
		scanf("%s",(s+i)->name);
		printf("Enter Roll :");
		scanf("%d",&(s+i)->roll);
		printf("Enter CGPA :");
		scanf("%f",&(s+i)->cgpa);
		printf("\n");

	}
}
void disp(STUDENT* s,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Name : %s\n",(s+i)->name);
		printf("Roll : %d\n",(s+i)->roll);
		printf("CGPA : %.2f\n",(s+i)->cgpa);
		printf("\n");
	}
}
void sort(STUDENT *s,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((s+i)->roll>(s+j)->roll)
			{
				STUDENT t=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=t;
			}
		}
	}
}
int main()
{
	int n;
	printf("Enter no. of students :");
	scanf("%d",&n);
	STUDENT *s=(STUDENT*)calloc(n,sizeof(STUDENT));
	printf("\n");
	read(s,n);
	sort(s,n);
	printf("\n");
	disp(s,n);
}