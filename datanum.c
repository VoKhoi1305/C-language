#include<stdio.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 20};
 typedef struct
 {
     char name[20];
     char tele[11];
     char email[25];
 }phoneaddress_t;

 int main()
{
    FILE *fp= NULL;
    phoneaddress_t phonearr[MAX_ELEMENT];
    int i,n, irc;
    scanf("%d",&n)
    for (int i=0; i<n; i++)
    {
        gets(phonearr[i].name);
        gets(phonearr[i].tele);
        gets(phonearr[i].email);
    }



}
