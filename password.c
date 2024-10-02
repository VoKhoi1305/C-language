#include<stdio.h>
#include<string.h>
#define MAX 100
int checkStrongPassword(char* password)
{
    if(length(password)<=6)
         {printf("false"); return 0;}
    int flag1= 0;
    int flag2= 0;
    int flag3= 0;
    int i=0;
    for(i=0; password[i] != '\0';i++)
    {
        if('0'<=password[i] && password[i] <=9)
        flag1=1;
        if('a'<=password[i] && password[i]<='z')
        flag2=1;
        if('A'<=password[i] && password<='Z')
            flag3=1;
    }
    if(flag1+flag2+flag3==3)
        printf("true");
    else printf("false");
}
int main()
{   char s[MAX]="Binlo123";
    char* p = s;
    checkStrongPassword(*p);
   return 0;
}
