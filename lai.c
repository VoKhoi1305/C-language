#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct xe {

    char plate[MAX];
    char time[MAX];
}xe_t;

int main(){
    xe_t arr[3000];
    char s[MAX];
    char s1[MAX];
    char s2[MAX];
    int i=0;
   while(1){
       scanf("%s",s);
        if(strcmp(s,"*")== 0) break;
        else {scanf("%s",s1);
        strcpy(arr[i].time,s);
        strcpy(arr[i].plate,s1);}
        i++;
    }

while (1)
{
  scanf("%s",s);
     if(strcmp(s,"***")== 0) break;
     else if(strcmp(s,"list")==0)
     {
       for(int j=0;j<=i;j++)
       {
           printf("%s\n",arr[j].plate);
       }
     }
     else if(strcmp(s,"find")==0)
     {
      scanf("%s",s1);
     for(int j=0;j<=i;j++)
     {
        if(strcmp())
     }
     }
     else if(strcmp(s,"in")==0){
      scanf ("%s %s",s1,s2);
     // lst=llInsertTail1(lst,s1,s2);
     }
     else if(strcmp(s,"list")==0);
    // out
     else if(strcmp(s,"list")==0);
     else if(strcmp(s,"list")==0);
}

}
