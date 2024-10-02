#include<stdio.h>
void tiencuoc(float n, int *p1, int *p2)
{
    int overwei= n/0.5-0.01;
    *p1= overwei*2500+21000;
    *p2= overwei*2500+29000;
}
int main(){
    float wei=0;
    scanf("%f", &wei);
    int p1 ; int p2;
    tiencuoc(wei,&p1,&p2);
    printf("%d-%d",p1,p2);
    return 0;
}
