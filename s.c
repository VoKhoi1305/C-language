#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char plate[20];
    struct Node *next;
};

typedef struct Node Node;


Node* makeNode(char data[]){
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    strcpy(pNewNode->plate, data);
    pNewNode->next = NULL;
    return pNewNode;
}

int checkKey(char data[], Node *lst){
    int cnt = 0;
    while(lst != NULL){
        if (strcmp(lst->plate, data) == 0) return cnt;
        lst = lst->next;
        ++cnt;
    }
    return -1;
}
//thêm phần tử có key=data vào cuối danh sách
int addLast(char data[], Node **lst){
    if (checkKey(data,*lst) >= 0) return 0;
    Node *p = makeNode(data);
    if (*lst == NULL) *lst = p;
    else{
        Node *q = *lst;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
    return 1;
}


int remove(char data[], Node **lst){
    if (checkKey(data,*lst) == -1) return 0;
    else if (strcmp((*lst)->plate, data) == 0){
        *lst = (*lst)->next;
        return 1;
    }
    Node *truoc = *lst, *sau=NULL;
    while(truoc != NULL){
        sau=truoc;
        truoc = truoc->next;
        if(strcmp(truoc->plate, data) == 0) break;
    }
    sau->next = truoc->next;
    return 1;
}

//in dslkd
void print(Node *lst){
    while(lst != NULL){
        printf("%s\n",lst->plate);
        lst = lst -> next;
    }
}

//dem so xe dap trong bai
int cntbic(Node *lst){
    int cnt = 0;
    while(lst != NULL){
        if(!strncmp(lst->plate, "xxxx",4)) ++cnt;
        lst = lst->next;
    }
    return cnt;
}
int checkout(char data[], Node *lst){
    return -1;
}
int main(){
    Node *lst = NULL;
    char arr1[30];
    //qua trinh nhap
    char s1[30], s2[30];
    while(scanf("%s", s2) && strcmp(s2, "*") != 0){
        scanf("%s", s1);
        addLast(s1, &lst);
    }
    while(scanf("%s", arr1) && strcmp(arr1, "*") != 0){
        if(!strcmp(arr1, "list")){
            print(lst);
        }
        else if(!strcmp(slc, "find")){
            char plate1[20];
            printf("%d\n", checkKey(plate1, lst));
        }
        else if(!strcmp(arr1, "in")){
            char t[20], info[20];
            scanf("%s %s", t, info);
            printf("%d\n", addLast(info, &lst));
        }
        else if(!strcmp(arr1, "out")){
            char t[20], info[20];
            scanf("%s %s", t, info);
            printf("%d\n", deleteKey(info, &lst));
        }
        else if(!strcmp(arr1, "cnt-bicycle")){
            printf("%d\n", cntbic(lst));
        }
        else if(!strcmp(arr1, "has-checkout")){
            char inf[30];
            scanf("%s", inf);
            printf("%d\n", checkout(inf, lst));
        }
    }
    return 0;
}
