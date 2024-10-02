#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct Node {
    char plate[MAX];
    char time[MAX];
    struct Node* next;
}Node_t, *root_t;

void showData(char plate[]){
    printf("%s ",plate);
}
root_t llinit(){return NULL;}

root_t llPrint(root_t root) {
  for (Node_t* p = root; p != NULL; p = p->next){ showData(p->plate);
  printf("\n");}
  return root;

  Node_t* llSeek(root_t root, char str[]) {
  Node_t* p = NULL;
  p = root;
  int i=1;
  while ((p!=NULL) && (strcmp(p->plate,str) != 0)){

        p=p->next;
    }
    return p;
}
}

int timkiem(root_t root, char str[]) {
  Node_t* p = NULL;
  p = root;
  int i=-1;
  while ((p!=NULL) && (strcmp(p->plate,str) != 0)){

        p=p->next;
        i++;
    }
    if(p!= NULL) return i+1;
    else return -1;
}


Node_t* createNewNode1(char time[], char str[]) {
  Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
  if (newNode == NULL) return NULL;
    strcpy(newNode->time,time);
  strcpy(newNode->plate,str);
  newNode->next = NULL;
  return newNode;
}
root_t llInsertTail1(root_t root,char time[], char str[]) {
  Node_t* pNewNode = createNewNode1(time, str);
 Node_t* p = NULL;
  if (root == NULL) return (root_t)pNewNode;12:11
for (p = root; p->next != NULL; p = p->next){
  if(strcmp(p->plate,str)==0) {
    printf("-1");
    return root;
  }
}
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  printf("0");
  return root;
}
Node_t* llSeekBefore(root_t root, char str[]) {
  Node_t* p = NULL;
  p = root; if(strcmp(p->plate,str)==0) return root;
  while ((p->next!=NULL) && (strcmp(p->plate,str)==0)){

        p=p->next;
    }
    return p;
}
int main(){
    root_t lst = llinit();
    char s[MAX];
    char s1[MAX];
    char s2[MAX];
   while(1){
       scanf("%s",s);
        if(strcmp(s,"*")== 0) break;
        else scanf("%s",s1);
        lst = llInsertTail1(lst,s,s1);
    }

while (1)
{   
  scanf("%s",s);
     if(strcmp(s,"***")== 0) break;
     else if(strcmp(s,"list")==0)
     {
        lst=llPrint(lst);
     }
     else if(strcmp(s,"find")==0)
     {
      scanf("%s",s1);
      printf("%d", timkiem(lst,s1));
     }
     else if(strcmp(s,"in")==0){
      scanf ("%s %s",s1,s2);
      lst=llInsertTail1(lst,s1,s2);
     }
     else if(strcmp(s,"list")==0);
     out
     else if(strcmp(s,"list")==0);
     else if(strcmp(s,"list")==0);
}

}

