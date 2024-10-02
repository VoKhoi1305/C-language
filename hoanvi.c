#include<stdio.h>
#define MAX 100001
int is_permutation(int n, int arr[])
{
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
            if (arr[i] <= n) {
            count[arr[i]-1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            return 0;
        }
    }

    return 1;

}
int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        int n;
        scanf("%d",&n);
        int arr[MAX];
        for(int j=0;j<n;j++)
            scanf("%d ",&arr[j]);
        printf("%d\n",is_permutation(n,arr));
    }
    return 0;
}
