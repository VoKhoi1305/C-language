#include<stdio.h>
#define MAX 100

int main()
{
    int s[MAX];
    int n;
    int sum=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for (int j=1;j<n-1;j++)
        if(s[j]>s[j-1]&&s[j]>s[j+1])
        {
            sum += s[j];
            j++;
        }
    printf("%d",sum);
    return 0;
}
