#include<stdio.h>
struct complex
{
	int real;
	int img;
};
void sum(struct complex a, struct complex b)
{
	int realSum,imgSum;
	realSum=a.real+b.real;
	imgSum=a.img+b.img;
	printf("The sum is %d + %di\n",realSum,imgSum);
}
void diff(struct complex a, struct complex b)
{
	int realDiff,imgDiff;
	realDiff=a.real-b.real;
	imgDiff=a.img-b.img;
	printf("The difference is %d + %di\n",realDiff,imgDiff);
}
void pro(struct complex a, struct complex b)
{
	int realPro,imgPro;
	realPro=(a.real*b.real)-(a.img*b.img);
	imgPro=(a.real*b.img)+(a.img*b.real);
	printf("The product is %d + %di\n",realPro,imgPro);
}
int main()
{
	struct complex a;
	struct complex b;
	printf("Enter first complex number: ");
	scanf("%d %d", &a.real, &a.img);
	printf("Enter second complex number: ");
	scanf("%d %d", &b.real, &b.img);
	sum(a,b);
	diff(a,b);
	pro(a,b);

}