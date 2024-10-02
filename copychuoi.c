#include<stdio.h>
#define MAX 1001
int main()
{
    char a[MAX];
    char b[MAX];
    fgets(a,sizeof(a),stdin);
    for(int i=0;i<sizeof(a);i++)
        {
            b[i]=a[i];
        }
    printf("%s",b);
}
