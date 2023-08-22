#include<stdio.h>
#define max(a,b) (a>b?a:b)
void main()
{
    int a[10][10]={0};              //n+1 rows and W+1 columns
    int w[]={0,2,1,3,2};            //append 0 at the start since accessing from w[1]-w[n]
    int val[]={0,12,10,20,15};      //append 0 at the start since accessing from val[1]-val[n]
    int kn[10],m=0;
    int i,j,k,n=4, W=5;
    //calculating 2D array
    for(i=1;i<n+1;i++)
        for(j=1;j<W+1;j++) {
            if(j<w[i])
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max( a[i-1][j] , (val[i]+a[i-1][j-w[i]]) );
        }

    for(i=0;i<n+1;i++) {
        for(j=0;j<W+1;j++)
            printf("%d       ",a[i][j]);
        printf("\n");
    }
    //calculating which items to include using bottom up
    i=n; j=W;
    while(i>0 && j>=0) {
        if(a[i][j]>a[i-1][j]) {
            kn[m++]=i;
            j=j-w[i];
            i--; //don't write it before reducing j by w[i]
        }
        else    i--;
    }
    for(i=m-1;i>=0;i--)
        printf("%d ",kn[i]);
    printf("\n");
}