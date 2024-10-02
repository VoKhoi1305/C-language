#include<stdio.h>
int x[11]={0},n,M,B[11]={0},sum=0;
int cnt=0;
void ghinhancauhinh(){
    cnt++;
}


int TRY(int k){
    for(int v=0;v<=M;v++){
        if((sum + B[k]*v)<= M){
            x[k]=v;
            sum+=B[k]*v;
            if(k==n&&sum==M) ghinhancauhinh();
            else if(k<n) TRY(k+1);
            sum -= B[k]*v;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d", &n, &M);
    for(int i=1; i<=n;i++)
    {
        scanf("%d", &B[i]);
    }
    TRY(1);
    printf("%d",cnt);
}
