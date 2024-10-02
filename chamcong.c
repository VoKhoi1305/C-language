#include<stdio.h>
#define MAX 100
int main()
{
    int n;
    int tong=0;
    scanf("%d",&n);
    int h[100];
    int m[100];

    for (int i=0;i<2*n;i++)
    {
        scanf("%d:%d",&h[i],&m[i]);
    }
    for (int j=0;j<n;j++)
    {
        int a = h[j]*60 +m[j];
        int b = h[n+j]*60 +m[n+j];
        tong += b - a;
    }
    printf("%d:%d",tong/60,tong%60);
return 0;
}
