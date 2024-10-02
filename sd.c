#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char plate[20];
    struct Node *next;
};

typedef struct Node Node;


Node* makeNode(char data[]){
    Node *tmp = (Node*)malloc(sizeof(Node));
    strcpy(tmp->plate, data);
    tmp->next = NULL;
    return tmp;
}


int findf(char data[], Node *lst){
    int cnt = 0;
    while(lst != NULL){
        if (strcmp(lst->plate, data) == 0) return cnt;
        lst = lst->next;
        ++cnt;
    }
    return -1;
}

int addLast(char data[], Node **lst){
    if (findf(data,*lst) >= 0) return 0;
    Node *tmp = makeNode(data);
    if (*lst == NULL) *lst = tmp;
    else{
        Node *p = *lst;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
    return 1;
}


int deleteKey(char data[], Node **lst){
    if (findf(data,*lst) == -1) return 0;
    else if (strcmp((*lst)->plate, data) == 0){
        *lst = (*lst)->next;
        return 1;
    }
    Node *front = *lst, *after=NULL;
    while(front != NULL){
        after=front;
        front = front->next;
        if(strcmp(front->plate, data) == 0) break;
    }

    after->next = front->next;
    return 1;
}

void llprint(Node *lst){
    while(lst != NULL){
        printf("%s\n",lst->plate);
        lst = lst -> next;
    }
}

int cntbic(Node *lst){
    int cnt = 0;
    while(lst != NULL){
        if(!strncmp(lst->plate, "xxxx",4)) ++cnt;
        lst = lst->next;
    }
    return cnt;
}
int checkout(char data[], Node *lst2, Node *lst){
    if((findf(lst2, data) == -1) || (findf(lst, data) >= 0)) return -1;

   return 0;
}
int main(){
    Node *lst = NULL;
    Node *lst2 = NULL;
    char slc[30];
    char input[30], time[30];
    while(scanf("%s", time) && strcmp(time, "*") != 0){
        scanf("%s", input);
        addLast(input, &lst);
       int i= addLast(input, &lst2);
    }

    while(scanf("%s", slc) && strcmp(slc, "***") != 0){
        if(!strcmp(slc, "list")){
            llprint(lst);
        }
        else if(!strcmp(slc, "find")){
            char plate1[20];
            printf("%d\n", findf(plate1, lst));
        }
        else if(!strcmp(slc, "in")){
            char t[20], info[20];
            scanf("%s %s", t, info);
            printf("%d\n", addLast(info, &lst));
            int i =addLast(input, &lst2);
        }
        else if(!strcmp(slc, "out")){
            char t[20], info[20];
            scanf("%s %s", t, info);
            printf("%d\n", deleteKey(info, &lst));
        }
        else if(!strcmp(slc, "cnt-bicycle")){
            printf("%d\n", cntbic(lst));
        }
        else if(!strcmp(slc, "has-checkout")){
            char info[30];
            scanf("%s", info);
            printf("%d\n", checkout(info, lst2, lst));
        }
    }
    return 0;
}
