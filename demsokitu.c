#include<stdio.h>
int main()
{
    char a[100];
    char b[100];
    fgets (a,sizeof(a),stdin);
    fgets (b,sizeof(b),stdin);
    int M;
    if (sizeof(a) < sizeof(b)) M=sizeof(b);
    else M=sizeof(a);
    int h=0;
    for (int i=0;i<M;i++)
    {
        if (b[i]!=a[i])
        {
            printf("khac nhau");
            h=1;
            break;
        }
    }
    if (h!=1) printf("giong nhau");
    return 0;
}
