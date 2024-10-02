#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_strcat(char s1[], char s2[])
{
    int len1= strlen(s1);
    int len2= strlen(s2);
    int n= len1 + len2 +1;
    int i,j;
    char *p= (char*)malloc(n*sizeof(char));
    for ( i=0; i < len1; i++)
    {
        p[i]=s1[i];
    }
    for ( j=0;j < len2; j++)
    {
        p[i+j]=s2[j];
    }
    p[i+j] = '\0';
        return p;
}


int main()
{
    char s1[100]; char s2[100];
    gets(s1);
    gets(s2);
    char *str = my_strcat(s1,s2);
    if(str == NULL) return -1;
    printf("%s",str);
    free(str);
    return 0;
}
