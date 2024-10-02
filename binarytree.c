#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char plate[20];
    struct Node *next;
}Node_t;




Node_t* makeNode(char data[]){
    Node_t *tmp = (Node_t*)malloc(sizeof(Node_t));
    strcpy(tmp->plate, data);
    tmp->next = NULL;
    return tmp;
}


int addLast(char data[], Node_t **list){
    if (findf(data,*list) >= 0) return 0;
    Node_t *p1 = makeNode(data);
    if (*list == NULL) *list = p1;
    else{
        Node_t *p2 = *list;
        while(p2->next != NULL){
            p2 = p2->next;
        }
        p2->next = p1;
    }
    return 1;
}

int timkiem(char data[], Node_t *list){
    int cnt = 0;
    while(list != NULL){
        if (strcmp(list->plate, data) == 0) return cnt;
        list = list->next;
        ++cnt;
    }
    return -1;
}

int xoa(char data[], Node_t **list){
    if (timkiem(data,*list) == -1) return 0;
    else if (strcmp((*list)->plate, data) == 0){
        *list = (*list)->next;
        return 1;
    }
    Node_t *front = *list, *after=NULL;
    while(front != NULL){
        after=front;
        front = front->next;
        if(strcmp(front->plate, data) == 0) break;
    }

    after->next = front->next;
    return 1;
}

int demxe(Node_t *list){
    int cnt = 0;
    while(list != NULL){
        if(!strncmp(list->plate, "xxxx",4)) ++cnt;
        list = list->next;
    }
    return cnt;
}
void llprint(Node_t *list){
    while(list != NULL){
        printf("%s\n",list->plate);
        list = list -> next;
    }
}

int main(){
    Node_t *list = NULL;
    Node_t *list2 = NULL;
    char order[30];
    char input[30], time[30];
    while(scanf("%s", time) && strcmp(time, "*") != 0){
        scanf("%s", input);
        addLast(input, &list);
       int i= addLast(input, &list2);
    }

    while( 1){
            scanf("%s", order);
            if(strcmp(order, "list") == 0){
            llprint(list);
        }
            else if(strcmp(order, "find") == 0){
            char plate1[20];
            printf("%d\n", timkiem(plate1, list));
        }
            else if(strcmp(order, "in")==0){
            char t[20], info[20];
            scanf("%s %s", t, info);
            printf("%d\n", addLast(info, &list));

        }
            else if(strcmp(order, "out")==0){
            char t[30], info[30];
            scanf("%s %s", t, info);
            printf("%d\n", xoa(info, &list));
        }
            else if(strcmp(order, "cnt-bicycle")==0){
            printf("%d\n", demxe(list));
        }
            else if(strcmp(order, "***") == 0) {break;}

    }
    return 0;
}

