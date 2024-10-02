#include<stdio.h>
#include<String.h>
#define MAX 1001
int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}
int main()
{
    char a[100]= {0};
    char b[100]= {0};
    int check =0;
    gets(a);
    gets(b);
    for(int i=0;a[i]!='\0'|| b[i]!='\0';i++)
        {
            if (b[i]!=a[i])
            {
                printf("chuoi khac nhau");
                check = 1;
                break;
            }
        }
    if (check != 1)
    {
        printf("chuoi giong nhau");
    }

return 0;

}
