#include<stdio.h>
int main()
{
    double uv;
    scanf("%lf", &uv);
    if(uv <0) return 0;
    if(uv>0 && uv <3) printf("muc thap");
    else if (uv < 6) printf("muc trung binh");
    else if (uv < 8) printf("muc cao");
    else if (uv <= 11) printf("muc rat cao");
    else printf("muc nguy hiem");
    return 0;
}
