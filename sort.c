#include <stdio.h>
int maxlengthofsubsequence(int a[],const int size)
{
    int maxlen=0;
    int tmplen=0;
    for (int i=0; i<size; i++){
        if(a[i]==0){
            tmplen++;}
        if(a[i]!=0)
        {
            if(tmplen>maxlen)
            {
                maxlen=tmplen;
                tmplen=0;
            }
        }
    }
    if(tmplen>maxlen)
       maxlen=tmplen;
    return maxlen;
}
int main()
{
    int s1[1002];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&s1[i]);
    printf("%d",maxlengthofsubsequence(s1,n));
}
