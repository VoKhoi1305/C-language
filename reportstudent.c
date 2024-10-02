#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
int cnt;
char ngay[20]} check_t;

int main(){
    char date[11]; int j=0;
    char time[10];
    char name[50];
    char ques[50];
    check_t counts[366];
    for(int i=0; i <366; i++){
        strcpy(counts[i].ngay,"0");
        counts[i].cnt=0;
        }
    while(1){
        scanf("%s",date);
        if (strcmp(date,"*") == 0) break;
        scanf("%s %s %s",time,name,ques);
        for(int k=0;k<j;k++){
            if(strcmp(counts[k].ngay,date) == 0) counts[k].cnt++;
        }
         if(strcmp(counts[j].ngay,"0") == 0) {
            strcpy(counts[j].ngay,date);
            counts[j].cnt++; j++;
        }
        for(int l=0;l<j-1;l++)
        for(int f=l+1;f<j;f++){
            if(strcmp(counts[l].ngay,counts[f].ngay)== 0) strcpy(counts[f].ngay,"0");
        }
    }
    for(int m=0; m<j; m++)
    {   if(strcmp(counts[m].ngay,"0") != 0)
        printf("%s %d\n",counts[m].ngay,counts[m].cnt);
    }
    return 0;
}
