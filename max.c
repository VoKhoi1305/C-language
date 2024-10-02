#include<stdio.h>
#include<stdlib.h>
int max(int a[],int size, int k){
    if(k==size)
    return a[k];
    int m =max(a,size,k+1);
     if (a[k]>m)
    return a[k];
     return m;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=1;i<=n;i++)
    {scanf("%d",&arr[i]);
    }
    printf("%d",max(arr,n,1));
    return 0;
}