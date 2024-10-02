#include<stdio.h>
#define MAX 1000

int check(int a[],int b[],int n, int m)
{
    if (n != m)
        return 0;
    for (int i=0;i<m;i++)
    {   if (a[i] != b[i])
        {
        return 0;
        }
    }
    return 1;
}
int main()
{
    int s1[MAX],s2[MAX];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&s1[i]);
    int m;
    scanf("%d",&m);
    for (int j=0;j<m;j++)
        scanf("%d",&s2[j]);
    printf("%d",check(s1,s2,n,m));
    return 0;

}
