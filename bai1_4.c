#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data_s{
    int x;
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
  struct node_s *prev;
} node_t, *root_t;

node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = newNode->prev = NULL;
  return newNode;
}

void showData(data_t data) { 
  printf("%d ", data);
}

data_t convert(data_t data) {
  return data->x;
}

root_t llInit() { return NULL; }

root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  if (root == NULL) return (root_t)pNewNode;

  pNewNode->next = root;
  root->prev = pNewNode;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  pNewNode->prev = p;   // <===
  return root;
}
root_t llInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;
  pNewNode->prev = pAElem;  // <===
  return root;
}

root_t llInsertbefore(root_t root, node_t* pAElem, const data_t data) {
    if (pAElem == NULL) return root;
    node_t* pNewNode = createNewNode(data);
    pNewNode->prev = pAElem->prev;
    pNewNode->next = pAElem;
    pAElem->prev=pNewNode;
    return root;
}

root_t reverseLL(root_t root) {
  node_t *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;   
    prev = cur;
  }
  // to check
  return root;
}

int main()
{
     root_t lst = llInit();
      for (int i = 0; i < 5; i++) {
    lst = llInsertTail(lst, convert(i));
    lst = llInsertHead(lst, convert(-i));
  }
  llPrint(lst);
    return 0;
}