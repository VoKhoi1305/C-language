#include<stdio.h>
int main()
{
    float s[4];
    int i;
    int tui=1;
    for (i=0; i<4;i++)
        scanf("%f", &s[i]);
 int k= ((s[0]+s[1]+s[2])/s[3])+0.99;

    printf("%d",k);
    return 0;
}
