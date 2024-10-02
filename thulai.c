#include<stdio.h>
#include<string.h>
int main()
{
    int i=0;
    char a[100][6];
    int b[100];

    while (1)
    {
        scanf("%s",a[i]);
        int check =strcmp(a[i],"-1");
        if(!check) break;
        scanf ("%d",&b[i]);
        i++;
    }
    int s;
    int tong=0;
    scanf("%d",&s);
    char ma[100][6];
    int so;
    for ( int j=0;j<s;j++)
    {
        scanf("%s",ma);
        scanf("%d",&so);
        for (int k=0; k<=i; k++)
        {
            int var = strcmp( ma,a[k]);
            if(!var)
            {
               tong += so*b[k] ;
            }
        }
    }
    printf("%d",tong);
    return 0;
}
