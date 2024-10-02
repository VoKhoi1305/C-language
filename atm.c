#include <stdio.h>
#include<stdlib.h>
#include<string.h>

enum {EXIT_STACK_OVERFLOW = 1, EXIT_STACK_UNDERFLOW , EXIT_STACK_EMPTY};

typedef struct data_s {
    int data
} data_t;
typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(const data_t data)
{
    printf("%d",data);
};

// Traversing a list and show
root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer


node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

root_t llInit() { return NULL; }

node_t* llSeek(root_t root, int index) {
  node_t* p;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}

/* === Delete ============================================== */

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root) {
  int count;
  for (count = 0; root!=NULL; root = root->next) count++;
  return count;
}

// to check
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
typedef root_t stack_t;

stack_t stackInit();

int isEmpty(stack_t stack);
int isFull(stack_t stack);

root_t push(stack_t stack, const data_t data);
stack_t pop(stack_t stack);
stack_t popData(stack_t stack, data_t *pData);

// Tra ve phan tu tren cung cua stack, khong loai phan tu nay khoi stack
data_t top(stack_t stack);


stack_t stackInit() { return llInit(); }

int isEmpty(stack_t s) { return s == NULL; }

int isFull(stack_t s) { return 0; }

stack_t push(stack_t stack, const data_t data) {
  return llInsertHead(stack, data);
 }

stack_t pop(stack_t stack) {
  return llDeleteHead(stack);
}

stack_t popData(stack_t stack, data_t *pData) {
  *pData = top(stack);
  return pop(stack);
}

data_t top(stack_t stack) {
  if (isEmpty(stack)) {
    printf("ERROR: Empty Stack!!!\n");
    exit(EXIT_STACK_EMPTY);
  }
  data_t data = stack->data;
  return data;
}


int main() {
  stack_t s = llInit();
  printf("Them du lieu vao stack (-1 de ket thuc):\n");

  data_t t;
  for (scanf("%d", &t.data); t.data != -1 ; scanf("%d", &t)) {
    s = push(s, t);
  }

  // Pop data from Stack and display to screen
  while (!isEmpty(s)) {
    showData(top(s));
    s = pop(s);
  }

  llDeleteAll(s); // <===

  return 0;
}
