#include<stdio.h>
#define MAX 100
int main()
{
    char s[MAX+1]="apple";
    int j;
    int dem=0;
    int var=0;
    int check=1;
  /*  for(j=0;s[j]!='\0';j++)
    {
        if(s[j]=='a'||s[j]=='i'||s[j]=='u'||s[j]=='e'||s[j]=='o')
        {
            dem++;

        }

    }*/
    for(j=0;s[j]!='\0';j++)
    {
        if(s[j]!='a'||s[j]!='i'||s[j]!='u'||s[j]!='e'||s[j]!='o')
        {
            var++;
            if(var>4)
            {
                check=0;
            }
        }
        if(s[j]=='a'||s[j]=='i'||s[j]=='u'||s[j]=='e'||s[j]=='o') var =0;
    }
   // printf("so nguyen am: %d\n",dem);
   // printf("so phu am: %d\n",var);
    if(check==0)
    {
        printf("kho doc");
    }
    else printf("de doc");
    return 0;
}
