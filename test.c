#include<stdio.h>
#include<math.h>
int main()
{
    float x,y,z,wei,check,i;
    scanf("%f %f %f %f",&x,&y,&z,&wei);
    check = x*y*z/5000;
    i=check-wei;
  // if(i>0)
    printf("%.2f",i);
   // else printf("0.00");
}
