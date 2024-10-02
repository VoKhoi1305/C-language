#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   time_t t;
    srand((unsigned) time(&t));
    int slenum;
   int randnum = rand()%10;
   if(randnum>5)
    printf("lam bai");
   else
   printf("di ngu");
   return 0;
}
