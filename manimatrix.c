#include<stdio.h>
#define MAX 101
int main(){
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];
    int i,j,k=0;
    scanf ("%d %d", &i, &j);
    for (int n=0;n<i;n++)
        for(int m=0;m<j;m++)
    {
        scanf("%d",&A[n][m]);
    }

    scanf("%d %d",&j,&k);
    for (int n=0;n<j;n++)
        for(int m=0;m<k;m++)
    {
        scanf("%d",&B[n][m]);
    }
       for (int n=0;n<i;n++)
        for(int m=0;m<k;m++)
    {
        C[n][m] =0;
    };
    for (int l = 0; l < i; l++)
            for (int m = 0; m < k; m++)
                for (int n = 0; n < j; n++)
                    C[l][m] += A[l][n] * B[n][m];

    for (int n=0;n<i;n++){
        for(int m=0;m<k;m++)
        {
            printf("%d ",C[n][m]);
        }
        printf("\n");
    }

    return 0;
}
