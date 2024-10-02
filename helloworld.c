#include<stdio.h>
void docso(int digit)
{
    if(digit==0) printf("khong");
    else if(digit==1) printf("mot");
    else if(digit==2) printf("hai");
    else if(digit==3) printf("ba");
    else if(digit==4) printf("bon");
    else if(digit==5) printf("nam");
    else if(digit==6) printf("sau");
    else if(digit==7) printf("bay");
    else if(digit==8) printf("tam");
    else if(digit==9) printf("chin");
    else printf("ERROR");
}
int main()
{
    int a,b,c;
    char s[4];
    //fgets(s,sizeof(s),stdin);
    gets(s);
    if(s[1]=='\0')
    {
        a=s[0]-'0';
        docso(a);
    }
    else if(s[2]=='\0')
    {
        a=s[0]-'0';
        b=s[1]-'0';
        if(a==1 && b==0)
            printf("muoi");
        else if (a==1)
        {
            printf("muoi ");
            docso(b);
        }
        else
            {docso(a); printf(" muoi "); docso(b);}
    }
    else if(s[3]=='\0')
    {
        a=s[0]-'0';
        b=s[1]-'0';
        c=s[2]-'0';
        if(a==1 && b==0 &c==0)
        {
            printf("mot tram");
        }
        else if(b==0)
        {
           docso(a); printf(" tram le "); docso(c);
        }
        else if(b==1)
        {
            docso(a); printf(" tram muoi"); docso(c);
        }
        else
        {
            docso(a); printf(" tram "); docso(b); printf("muoi "); docso(c);
        }
    }
}
