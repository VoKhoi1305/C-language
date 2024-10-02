#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=0,check=0;
    scanf("%d\n",&n);
    char* s1=(char*)malloc(sizeof(char)*n);
    char* s2=(char*)malloc(sizeof(char)*n);
    gets(s1);
    gets(s2);
    for(int i=0;i<n;i++)
    {
        if(s1[i]-s2[i]!=0)
        {
            check++;
        }
    }
    if (check == 0)
    {
        printf("giong");
    }
    else printf("khac");
    free(s1);
    free(s2);
    return 0;
}
