#include<stdio.h>
#include<string.h>
#define MAX 10
int main()
{
int n = 0;
int tmp=1;
int a[MAX] ;
int b[MAX] ;
scanf("%d",&n);
for(int i =0;i <n;i++)
    {
        scanf ("%d %d",&a[i], &b[i]);
    }
for (int d=0;d<n;d++)
    {
        if (b[d] == tmp)
        printf("%d", a[d]);
    tmp++;
    }
    return 0;
}
