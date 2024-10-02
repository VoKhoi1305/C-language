#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int arr[],int n)
{
    int max = arr[0];
    for (int i=0; i<n; i++)
    {
        if (arr[i]>max)
            max= arr[i];
    }
    return max;
}
int min(int arr[],int n)
{
    int min = arr[0];
    for (int i=0; i<n; i++)
    {
        if (arr[i]<min)
            min= arr[i];
    }
    return min;
}
int max_seg(int arr[],int i, int j )
{
    int max=arr[i-1];
    for(i=i-1;i<j;i++)
    {
        if (arr[i]>max)
            max= arr[i];
    }
    return max;
}
int sum(int arr[],int n)
{   int tong=0;
    for(int i=0;i<n;i++)
        tong+= arr[i];
    return tong;
}
int main()
{
    int n;
    scanf("%d",&n);
    int* ptr = (int*) malloc(n * sizeof(int));
    for(int i=0;i<n; i++)
        scanf("%d ",&ptr[i]);
    char a[5]={0};
    scanf("%s",a);
    int rs=0;
    int i,j;
    char s[100]={0};
    char s1[]="find-max";
    char s2[]="find-min";
    char s3[]="find-max-segment";
    char s4[]="sum";
    char s5[]="***";
    if(a[0]=='*')
    {
        while(strcmp(s,s5)!=0)
        {
        scanf("%s",s);
        if(strcmp(s,s1)==0)
            {rs=max(ptr,n);
            printf("%d\n",rs);}
        if(strcmp(s,s2)==0)
            {rs=min(ptr,n);
            printf("%d\n",rs);}
        if(strcmp(s,s3)==0)
        {
            scanf(" %d %d",&i,&j);
            rs=max_seg(ptr,i,j);
            printf("%d\n",rs);
        }
        if(strcmp(s,s4)==0)
            {rs=sum(ptr,n);
        printf("%d\n",rs);}
        }
    }

    free(ptr);
    return 0;
}

