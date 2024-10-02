#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct {int x,y;} sv;
int main()
{
int n = 0; int j,k;
int i=1;
//int a[MAX] ;
//int b[MAX] ;
int c[MAX] ;
int check[MAX];
sv edge[MAX];
int degree[MAX] = {0};
scanf("%d",&n);
for(int i =1;i<=n;i++)
    {
        scanf ("%d %d",&edge[i].x,&edge[i].y);
        degree[edge[i].x]++;
        degree[edge[i].y]++;
    }
  i=1;  k=0;
while(i<=n)
{
    for(j=1;j<=n;j++)

        if (edge[j].x==i && degree[edge[j].x]==1 && check[j] == 0 )
        {
            c[k]= edge[j].y;
            degree[edge[j].x]=0;
            degree[edge[j].y]--;
            i=0;
            k++;
            check[k]++;
            break;
        }
        else if (edge[j].y==i && degree[edge[j].y]==1 && check[j] == 0)
        {
            c[k]= edge[j].x;
            degree[edge[j].y]=0;
            degree[edge[j].x]--;
            i=0;
            k++;
            check[k]++;
            break;
        }

    i++;
}
  for (k=0;k<n-1;k++)
    {
    	printf("%d ",c[k]);
	}
}

