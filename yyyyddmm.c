#include<stdio.h>
#include<string.h>
int main()
{
    char s[10];
    scanf("%s",s);
    int check = 1;
    if (strlen(s)!=10)
    {
        check = 0;
    }
    if(s[4]!='-' || s[7]!='-')
    {
        check = 0;
    }
    if(s[0]<'0'|| s[1]<'0' || s[2]<'0'|| s[3]<'0'|| s[0]>'9' ||s[2]>'9' ||s[3]>'9' || s[1]>'9')
    {
        check = 0;
    }
    if(s[5]<'0' ||s[5] > '9'|| s[6]<'0' || s[6] > '9')
    {
        check = 0;
    }
    if(s[8]<'0' ||s[8] > '9'|| s[9]<'0' || s[9] > '9')
    {
        check = 0;
    }
    int y=(s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 +(s[3]-'0');
    int m=(s[5]-'0')*10 + (s[6]-'0');
    int d=(s[8]-'0')*10 + (s[9]-'0');

    if(m<1 || m>12)
    {
        check =0;
    }
    if(d<1 || d>31)
    {
        check =0;
    }
    if(check == 1)
    {
        printf("%d %d %d",y,m,d);
    }
    else
    {
        printf("INCORRECT");
    }
}


