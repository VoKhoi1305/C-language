#include<stdio.h>
#include<stdlib.h>
long mystery(int a, int b)
{
    if(a==0) return 0;
    if(a%2 ==0) return 2*mystery(a/2,b);
    return b+2*mystery((a-1)/2,b);
}

int main(){
    printf("%d",mystery(4,5));
return 0;
}
