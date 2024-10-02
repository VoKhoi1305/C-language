#include<stdio.h>
#include<string.h>
int main()
{
    char s[10];
    scanf("%s",s);
    int check = 1;
    if (strlen(s)!=8)
    {
        check = 0;
    }
    if(s[2]!=':' || s[5]!=':')
    {
        check = 0;
    }
    if(s[3]<'0'|| s[4]<'0' || s[4]>'9' || s[3]>'9')
    {
        check = 0;
    }
    if(s[6]<'0' ||s[6] > '9'|| s[7]<'0' || s[7] > '9')
    {
        check = 0;
    }
    if(s[0]<'0' ||s[0] > '9'|| s[1]<'0' || s[1] > '9')
    {
        check = 0;
    }
    int hh=(s[0]-'0')*10 + (s[1]-'0');
    int mm=(s[3]-'0')*10 + (s[4]-'0');
    int ss=(s[6]-'0')*10 + (s[7]-'0');
    int converted=hh*3600+mm*60+ss;
    if(hh>23)
    {
        check = 0;
    }
    if(mm>59)
    {
        check =0;
    }
    if(ss>59)
    {
        check =0;
    }
    if(check == 1)
    {
        printf("%d",converted);
    }
    else
    {
        printf("INCORRECT");
    }
}
