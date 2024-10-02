#include<stdio.h>
int main()
{
    int i=0;
    int a[100],b[100];
    while (1)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1) break;
        scanf ("%d",&b[i]);
        i++;
    }
    int s;
    int tong=0;
    scanf("%d",&s);
    int ma,so;
    for ( int j=0;j<s;j++)
    {
        scanf("%d %d",&ma,&so);
        for (int k=0; k<=i; k++)
        {
            if(ma == a[k])
            {
               tong += so*b[k] ;
            }
        }
    }
    printf("%d",tong);
    return 0;
}
