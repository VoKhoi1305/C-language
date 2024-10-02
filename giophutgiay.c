#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct{char kitu; int dem} chuoi;

int main()
{ int n=1000;
chuoi a[60];
a[0].kitu='a';
char s[MAX];
    fgets(s,sizeof(s),stdin);
while (n !=0)
    {
  // char s[MAX];
   // fgets(s,sizeof(s),stdin);
    for (int i=0;i<MAX;i++)
    {
        if (s[i] >='A' && s[i]<='Z')
        {
            s[i] = (char) s[i] +'a' - 'A';
        }
    }

    n--;
    }
    for (int k=0;s[k]='\0';k++)
        for(int j=0;a[j].kitu<='z';a[j].kitu++,j++)
        {
            if(s[k]==a[j].kitu)
            {
            a[j].dem++;
            }
        }
    for (int m=0;a[m].kitu<='z';a[m].kitu++,j++)
    {
        if (a[m].dem!=0)
            printf("%s %d",a[m].kitu,a[m].dem);
        return 0;
    }
}

