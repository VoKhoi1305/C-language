#include <stdio.h>
int main()
{
    double cost,sale,price;
    scanf("%lf",&cost);
    if (cost>=500000)
    {
        sale= 50000;
    }
    else if (cost>=100000)
    {
        sale= cost/10.0;
    }
    else sale=0;
    price=(cost*11/10)-sale;
    printf("%.2lf",price);
}
