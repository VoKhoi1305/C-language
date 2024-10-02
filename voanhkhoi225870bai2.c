#include<stdio.h>
#define MAX 1000
    int isequal (int arr1[],int arr2[], int n)
{
    for (int i=0; i<n;i++)
      { if (arr1[i] != arr2[i]){
      return 0;}  }
      return 1;
}
int main()
{
    int arr1[MAX];
    int arr2[MAX];
    int n;
    scanf("%d",&n);
    for (int i=0; i<n;i++)
        {scanf("%d",&arr1[i]);}
    for (int j=0; j<n;j++)
        {scanf("%d",&arr2[j]);}
    printf("%d",isequal(arr1,arr2,n ));
    return 0;
}

