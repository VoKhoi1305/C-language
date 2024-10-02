#include<stdio.h>
#include<stdlib.h>
int sum (int arr[],int i,int j)
{
    int tong=0;
    for(i=i-1;i<j;i++)
    {
        tong+= arr[i];
    }
    return tong;
}
int main()
{
    int n;
    scanf("%d",&n);
   int* ptr = (int*) malloc(n * sizeof(int));
   for(int in=0;in<n;in++)
    scanf("%d ",&ptr[in]);
   int k;
   int i,j;
   scanf("%d",&k);
   for (int m=0;m<k;m++)
   {
       scanf("%d %d",&i,&j);
       printf("%d\n",sum(ptr,i,j));

   }
    free(ptr);
   return 0;
}
