
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char arr1[MAX_SIZE];
    char arr2[MAX_SIZE];
    for (int i=0;i<strlen(arr1);i++)
    {
        scanf("%c", &arr1[i]);
    }
    for (int i=0;i<strlen(arr2);i++)
    {
        arr2[i]= '0';
    }
    int i=0;
    int j=0;
    arr2[++j]=arr1[i++];
    arr2[++j]=arr1[i];
    printf("%s",arr2);
    return 0;
}
