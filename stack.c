        #include<stdio.h>
        #include<stdlib.h>
        #include<string.h>
        enum {EXIT_STACK_OVERFLOW = 1, EXIT_STACK_UNDERFLOW , EXIT_STACK_EMPTY};
        //======================================================CREAT=======================================================================================
        typedef int data_t;

        typedef struct Node {
            data_t data;
            struct Node* next;
        }Node_t, *root_t;

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

        //========================================================STACK=======================================================================================

        typedef root_t stack_t;

        int isEmpty(stack_t s) { return s == NULL; }
        int isFull(stack_t s) { return 0; }

        stack_t push(stack_t stack, const data_t data) {
          return llInsertHead(stack, data);
         }
        stack_t pop(stack_t stack) {
          return llDeleteHead(stack);
        }
        data_t top(stack_t stack) {
          if (isEmpty(stack)) {
            printf("ERROR: Empty Stack!!!\n");
            exit(EXIT_STACK_EMPTY);
          }
          data_t data = stack->data;
          return data;
        }
        stack_t popData(stack_t stack, data_t *pData) {
          *pData = top(stack);
          return pop(stack);
        }




        //====================================
        int main() {
          root_t s = llInit();
          printf("Them du lieu vao stack (-1 de ket thuc):\n");

          int t;
          while(1){
            scanf("%d",&t); if(t == -1) break;
            s = push(s, convert(t));
          }

          // Pop data from Stack and display to screen
          while (!isEmpty(s)) {
            showData(top(s));
            s = pop(s);
          }

          llDeleteAll(s); // <===

          return 0;
        }
