#include<stdio.h>
int d=0;
void thapHaNoi(int n, char a, char b, char c){
if(n == 1)
{
    printf("Lan %d chuyen 1 dia tu %c -> %c \n", ++d,a,c);
    return;
}
    thapHaNoi(n-1,a,c,b);
    thapHaNoi(1,a,b,c);
    thapHaNoi(n-1,b,a,c);
}

int main(){
    thapHaNoi(6,'A','B','C');
return 0;
}
