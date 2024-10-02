#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

typedef struct {
    char name[50];
    char tel[12];
    char email[100];
} phoneAddr_t;

 typedef struct node
{
    phoneAddr_t data;
    struct node* next;
}node_t, *root_t;

 void showData(phoneAddr_t data) { printf("%s %s %s ", data.name, data.tel, data.email); }

node_t* createNewNode(const phoneAddr_t temp) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;
    strcpy((newNode->data).name,temp.name);
	strcpy((newNode->data).tel,temp.tel);
	strcpy((newNode->data).email,temp.email);
  newNode->next = NULL;
  return newNode;
}
root_t llInit() { return NULL; }

//node_t* llSearch(root_t root, char[] key) {
//  node_t* p = NULL;

 // for (p = root; strcmp(p->data.name,key) != 0 ;p = p->next)
 // return p;
//}//

root_t llInsertTail(root_t root, const phoneAddr_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}
root_t llPrint(root_t root) {
    printf("0");
  for (node_t* p = root; p != NULL; p = p->next) {
  //printf("%s %s %s",p->data.name,p->data.tel,p->data.email);
  printf("1");
  }
  printf("\n");
  return root;
}

int main() {
  root_t lst = llInit();
  printf("moi ban nhap so luong phan tu co san");
  int n=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  { phoneAddr_t temp;
    scanf("%s %s %s",temp.name,temp.tel,temp.email);
    llInsertTail(lst, temp);
  }
  llPrint(lst);
  return 0;
}
