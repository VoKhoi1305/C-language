#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
#define MAX_L 256
#define M 100
typedef struct Node {
    char Name[MAX_L];
    char Mail[MAX_L];
    struct Node* LeftChild;
    struct Node* RightChild;
}Node_t;

Node_t* root[M];

int h(char *s){
    int rs =0;
    int n= strlen(s);
    for(int i=0; i<n; i++)
    {
            rs = (rs*255 +s[i])%M;
    }
    return rs;
}

Node_t* MakeNode(char *Name, char* Mail){
 Node_t* p= (Node_t*)malloc(sizeof(Node_t));
    strcpy(p->Name,Name);
    strcpy(p->Mail,Mail);
    p->LeftChild = NULL;
    p->RightChild = NULL;
    return p;
}

Node_t* insert(Node_t* r, char* Name, char* Mail){
    if(r==NULL) return MakeNode(Name,Mail);
    int c = strcmp(r->Name, Name);
    if(c==0)
    {
        printf("cannot insert");
    }
    else if (c<0)
    {
        r->LeftChild = insert(r->LeftChild, Name, Mail); return r;
    }
    else
    {
        r->RightChild = insert(r->RightChild, Name, Mail); return r;
    }
}

Node_t* findintree(Node_t* r, char* Name){
    if(r==NULL) return NULL;
    int c = strcmp(r->Name, Name);
    if(c==0)
    {
        return r;
    }
    if (c < 0)
    {
        return findintree(r->RightChild,Name);
    }
    else
    {
       return findintree(r->LeftChild,Name);
    }
}

Node_t* findMin(Node_t* r){
    if(r==NULL) return NULL;
    Node_t * lmin = findMin(r->LeftChild);
    if(lmin != NULL) return lmin;
    return r;
    }

Node_t* Remove(Node_t* r, char* Name){
    if(r == NULL) return NULL;
    int c = strcmp( r->Name, Name);
    if(c <0 ) r->LeftChild = Remove(r->LeftChild, Name);
    else if(c>0) r->RightChild = Remove(r->RightChild, Name);
    else {
        if(r->LeftChild != NULL && r->RightChild != NULL){
            Node_t* tmp= findMin(r->RightChild);
            strcpy(r->Name, tmp->Name);
            strcpy(r->Mail, tmp->Mail);
            r->RightChild = Remove(r->RightChild,tmp->Name);
        }else{
            Node_t* tmp=r;
            if(r->LeftChild == NULL) r= r->RightChild;
            else r= r->LeftChild;
            free(tmp);
        }
    }
return r;}

void freetree(Node_t* r){
    if(r==NULL) return;
    freetree(r->LeftChild);
    freetree(r->RightChild);
    free(r);
}

void load(int n){
    for(int i=0;i<n; i++)
    {
        char Name[MAX_L];
        char Mail[MAX_L];
        scanf("%s %s",Name, Mail);
        int idx = h(Name);
        root[idx]= insert(root[idx],Name,Mail);
    }
}

void ProcessInsert(){
    char Name[MAX_L];
    char Mail[MAX_L];
    scanf("%s %s",Name, Mail);
    int idx = h(Name);
    root[idx]= insert(root[idx],Name,Mail);
}

void ProcessRemove(){
    char Name[MAX_L];
    scanf("%s",Name);
    int idx = h(Name);
    root[idx] = Remove(root[idx],Name);
}

void ProcessFind(){
    char Name[MAX_L];
    scanf("%s",Name);
    int idx = h(Name);
    Node_t* tmp= findintree(root[idx],Name);
    if(tmp!=NULL)
    {
        printf("%d %s\n",idx,tmp->Mail);
    }
    else printf("Not found\n");
}
void Inorder(Node_t* r){
    if(r== NULL) return;
    Inorder(r->LeftChild);
    printf("%s, %s\n",r->Name,r->Mail);
    Inorder(r->RightChild);
}
int main(){
    while(1){
        char cmd[256];
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit")==0) break;
        else if((strcmp(cmd,"Load")==0)) {int n; scanf("%d",&n); load(n);}
        else if((strcmp(cmd,"Insert")==0)) ProcessInsert();
        else if((strcmp(cmd,"Find")==0)) ProcessFind();
        else if((strcmp(cmd,"Remove")==0)) ProcessRemove();
        else if((strcmp(cmd,"Print")==0))
        {
            for(int i=0; i<M;i++)
                if(root[i]!= NULL)
            {
                Inorder(root[i]);
            }
        }
    }
    for(int i=0; i<M;i++)
        freetree(root[i]);
    printf("Bye");
}
