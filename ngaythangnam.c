#include<stdio.h>
#define MAX 100
int main()
{
    char a[MAX];
    scanf("%s",&a);
    int dem=0;
    for(int i=0;i<MAX;i++)
    {
        if(a[i]=='\0')
        {
            break;
        }
        dem++;
    }
    printf("%d",dem);
}
