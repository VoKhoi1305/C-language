#include<stdio.h>
int main()
{
double V,S,mua;
double a;
scanf("%lf %lf %lf", &V, &S, &mua);
a = S * (mua/1000);
if (a >= V)
printf("%.2lf", V);
else
printf("%.2lf", a);
return 0;
}
