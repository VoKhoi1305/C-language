#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   time_t t;
    srand((unsigned) time(&t));
    int slenum;
   int randnum = rand()%10;
   for(int i=0;i<=randnum;i++)
   {
       scanf("%d",&slenum);
       if (slenum == randnum)
       {
           printf("you win the game\n");
       }
       else if (slenum< randnum)
       {
           printf("your guess was too small\n");
       }
       else printf("your guess was too big\n");
   }
   return 0;
}
