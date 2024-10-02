#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char plate[20];
    struct Node* next;
}Node_t, *root_t;

root_t llinit(){return NULL;}


int llSeek(root_t root, char info[]) {
  Node_t* p = NULL;
  p = root;
  int cnt =0;
  while (p!=NULL) {
        if(strcmp(p->plate,info)== 0) return cnt;
        p=p->next;
        ++cnt;
    }
    return -1;
}
Node_t* createNewNode(char info[]) {
  Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
 strcpy(newNode->plate,info);
  newNode->next = NULL;
  return newNode;
}
int llInsertTail(root_t *root, char plate[]) {
     if (llSeek(*root, plate) >= 0) return 0;
  Node_t* pNewNode = createNewNode(plate);

  if (*root == NULL) {*root=pNewNode;}
else{
  Node_t* p = NULL;
  for (p = *root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
}
  return 1;
}
void llprint(root_t list){
    while(list != NULL){
        printf("%s\n",list->plate);
        list = list -> next;
    }
}

int xoa(char data[], root_t *list){
    if (llSeek(*list,data) == -1) return 0;
    else if (strcmp((*list)->plate, data) == 0){
        *list = (*list)->next;
        return 1;
    }
    Node_t *tmp1 = *list, *tmp2=NULL;
    while(tmp1 != NULL){
        tmp2=tmp1;
        tmp1 = tmp1->next;
        if(strcmp(tmp1->plate, data) == 0) break;
    }

    tmp2->next = tmp1->next;
    return 1;
}
int main(){
    root_t list = llinit();
    char order[30];
    char input[30], time[30];
    while(scanf("%s", time) && strcmp(time, "*") != 0){
        scanf("%s", input);
        llInsertTail(&list,input);
    }

    while(1){
            scanf("%s", order);
            if(strcmp(order, "list") == 0){
            llprint(list);
        }
            else if(strcmp(order, "find") == 0){
            char plate1[20];
            printf("%d\n", llSeek(list, plate1));
        }
            else if(strcmp(order, "in")==0){
            char time1[20], info[20];
            scanf("%s %s", time1, info);
            printf("%d\n", llInsertTail(&list,info));

        }
          else if(strcmp(order, "out")==0){
            char time1[30], info[30];
            scanf("%s %s", time1, info);
            printf("%d\n", xoa(info, &list));
        }
        /*    else if(strcmp(order, "cnt-bicycle")==0){
            printf("%d\n", demxe(list));
        }*/
            else if(strcmp(order, "***") == 0) {break;}

    }
    return 0;
}

