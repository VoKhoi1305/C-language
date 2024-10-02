#include<stdio.h>
int main()
{
    char ten[53];
    int s;
    scanf("%d",&s);
    for (int i=0 ; i <= s; i++)
    {
       fgets(ten,sizeof(ten),stdin);
        for (int k=0; ten[k] != '\0'; k++)
        {
            if (ten[k]<='Z' && ten[k]>='A')
                ten[k] += -'A' +'a';
        }

       if(ten[0]<='z' && ten[0]>='a')
        ten[0] += 'A'-'a';
       for (int j=0; ten[j] != '\0'; j++)
        {if (ten[j]== ' ' && ten[j+1] != ' ' && ten[j+1]<='z' && ten[j+1]>='a')
        ten[j+1] += -'a'+'A';}
       printf("%s", ten);

    }
    return 0;

}
