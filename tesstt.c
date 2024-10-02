#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node_t;

Node_t* newnode(int u){
    Node_t* p = (Node_t*)malloc(sizeof(Node_t));
    
        p->data = u;
        p->next = NULL;
        return p;
}

int insert(Node_t **root, int u)
{
    Node_t *p = newnode(u);
    if(*root == NULL ) *root = p; 
 else{
        Node_t *p2 = *root;
        while(p2->next != NULL){
            p2 = p2->next;
        }
        p2->next = p;
    }
    return 1;
}
void ChenDau(Node_t **root, int u)
{
    Node_t *p = newnode(u);
    if(*root == NULL ) *root = p; 
    else
    {
        p->next = *root;
        *root = p;
    }
}
void print(Node_t *list){
    while(list != NULL){
        printf("%d\n",list->data);
        list = list -> next;
    }
}

int main(){
    Node_t *list = NULL;
    int u;
    while(scanf("%d", &u) && u != -1)
    {
        ChenDau(&list,u);
    }
    print(list);
    return 0;
}

