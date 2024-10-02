#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {EXIT_QUEUE_OVERFLOW = 1, EXIT_QUEUE_UNDERFLOW , EXIT_QUEUE_EMPTY};
//======================================================CREAT=======================================================================================
typedef int data_t;

typedef struct Node {
    data_t data;
    struct Node* next;
}Node_t, *root_t, *llst_t;

root_t llInit(){return NULL;}


    data_t convert(int n) {
  return n;
}
Node_t* llSeek(root_t root, int index) {
  Node_t* p = NULL;
  p = root;
  while ((p!=NULL) && (p->data!= convert(index))){

        p=p->next;
    }
    return p;
}
Node_t* llSeekBefore(root_t root, int index) {
  Node_t* p = NULL;
  p = root; if(p->data == convert(index)) return root;
  while ((p->next!=NULL) && (p->next->data!= convert(index))){

        p=p->next;
    }
    return p;
}
//=================================================================================================================================================
//========================================================PRINT=====================================================================================
void showData(const data_t data){
    printf("%d ",data);
}

/*root_t llPrint(root_t root) {
  for (Node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}*/
//==================================================================================================================================================


Node_t* createNewNode(const data_t data) {
  Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
//================================================================================================================================================
//======================================================INSERT===================================================================================
root_t llInsertHead(root_t root, const data_t data) {
  Node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  Node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  Node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, Node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  Node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}


//========================================================DELETE=========================================================================================
root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  Node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  Node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

root_t llDeleteAfter(root_t root, Node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;
  if (pA == root){root = pA->next; return root;}
  Node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
  Node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

root_t Remove(root_t root , int u ){
    Node_t* p= root;
    while(p!= NULL)
    {
        Node_t* temp;
        temp = llSeekBefore(root,u);
        root = llDeleteAfter(root, temp);
        p=p->next;
    }
    return root;
}
//==================================================================================================================================================

//=========================================================== Tools ================================================================================
int llLength(root_t root) {
  int count;
  for (count = 0; root != NULL; root = root->next) count++;
  return count;
}

root_t reverse(root_t root)
{
     Node_t* prev = NULL;
    Node_t* current = root;
    Node_t* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    root = prev;
    return root;
}
//=====================================================================QUEUE==========================================================================
typedef struct {
  llst_t front;
  Node_t *rear;
} queue_t;

queue_t queueInit() {
  queue_t q;
  q.front = llInit();
  q.rear = NULL;      // <===
  return q;
}
int isEmpty(queue_t q) { return q.front == NULL; }

int isFull(queue_t q) { return 0; }

data_t top(queue_t q) {
  if (isEmpty(q)) {
    printf("ERROR: Empty Queue!!!\n");
    exit(EXIT_QUEUE_EMPTY);
  }
  data_t data = q.front->data;
  return data;
}

queue_t enqueue(queue_t q, const data_t data) {
  if (isEmpty(q)) 
    q.rear = q.front = llInsertHead(q.front, data); // <=== 
  else {
    q.rear->next = createNewNode(data);
    q.rear = q.rear->next;  // <===
  }

  return q;
}

queue_t dequeue(queue_t q) {
  q.front = llDeleteHead(q.front);
  if (isEmpty(q)) q.rear = NULL; // <===
  return q;
}
// ================================================

queue_t dequeueData(queue_t q, data_t *pData) {
  *pData = top(q);
  return dequeue(q);
}

// Tra ve phan tu dau tien cua queue, khong loai phan tu nay khoi queue
int main() {
  queue_t q = queueInit();
  // queueInit(&q);
  printf("Them du lieu vao stack (-1 de ket thuc):\n");

  data_t t;
  for (scanf("%d", &t); t != -1; scanf("%d", &t)) {
    q = enqueue(q, t);    
  }

  // Pop data from Stack and display to screen
  while (!isEmpty(q)) {
    showData(top(q));
    q = dequeue(q);
  }

  llDeleteAll(q.front);

  return 0;
}

