#include<stdio.h>
#define MAX 101
int main()
{   int n;
    scanf("%d\n",&n);
    char s[MAX];
    char temp;
    fgets(s,sizeof(s),stdin);
    temp=s[1];
    for (int i=0;i<n;i++)
    {
        ;
        if (s[i]<temp)
        {
            temp = s[i];
        }
    }
    printf("%c",temp);
    return 0;
}
