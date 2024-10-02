#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

typedef struct Node {
    int malop;
    char mahp[MAX];
    int cnt =0;
    int var =0;
    struct Node* next;
}Node_t, *root_t;

root_t llinit(){return NULL;}

//===================================================================================================
void showData(const int malop, char mahp[]){
    printf("%d ",malop);
    printf("%s ",mahp);
}
void showData1(root_t root,char str[]){
     Node_t* p = NULL;
    p = root;
  while(p != NULL)
  {
      if(strcmp(p->mahp,str)==0) {
        printf("%d\n",p->malop);
      }
      p = p->next;
  }
}

root_t llPrint(root_t root) {
  for (Node_t* p = root; p != NULL; p = p->next){ showData(p->malop,p->mahp);
  printf("\n");}
  return root;
}//===================================================================================================
/*int llLength(root_t root) {
  int count;
  for (count = 0; root != NULL; root = root->next) count++;
  return count;
}*/
Node_t* llSeek(root_t root, char str[]) {
  Node_t* p = NULL;
  p = root;
  while ((p!=NULL) && (strcmp(p->mahp,str) != 0)){

        p=p->next;
    }
    return p;
}
Node_t* llSeekBefore(root_t root, int index) {
  Node_t* p = NULL;
  p = root; if(p->malop == index) return root;
  while ((p->next!=NULL) && (p->next->malop!=index)){

        p=p->next;
    }
    return p;
}
//==============================================================================
Node_t* createNewNode(int mal, char str[]) {
  Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
  if (newNode == NULL) return NULL;

  newNode->malop = mal;
  strcpy(newNode->mahp,str);
  newNode->next = NULL;
  return newNode;
}

root_t llInsertHead(root_t root, int mal, char str[]) {
    Node_t* pNewNode = createNewNode(mal,str);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, int mal, char str[]) {
  Node_t* pNewNode = createNewNode(mal,str);

  if (root == NULL) return (root_t)pNewNode;

  Node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}
//======================================================================================
root_t llDeleteAfter(root_t root, Node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;
  if (pA == root){root = pA->next; return root;}
  Node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}
root_t Remove(root_t root , int mal ){
    Node_t* p= root;
    while(p!= NULL)
    {
        Node_t* temp;
        temp = llSeekBefore(root,mal);
        root = llDeleteAfter(root, temp);
        p=p->next;
    }
    return root;
}

root_t llcount(root_t root)){


int main(){
    int n;
    char str[MAX];
  root_t lst = llinit();

    while(1)
    {
    	printf("-------------------------\n");
    	printf("1. doc thong tin\n");
    	printf("2. hien thi thoi khoa bieu\n");
    	printf("3. tim kiem lop\n");
    	printf("4. Them lop vao dau danh sach\n");
    	printf("5. Them lop vao cuoi danh sach\n");
    	printf("6. Xoa thong tin\n");
    	printf("7. Luu ra file\n");
    	printf("8. Dem so luong lop\n");
    	printf("9. Exit\n");
    	printf("-------------------------\n");
    	printf("Vui long chon chuc nang:\n");
    	int choice;
    	scanf("%d", &choice);
    	if(choice == 2)
        {
            lst = llPrint(lst);
        }
        else if(choice == 1)
        {
            FILE *f3=fopen("C:\\Users\\AD\\OneDrive - Hanoi University of Science and Technology\\Schedule.txt","r");
            while(fscanf(f3,"%d\t%s", &n, str) == 2){
           lst = llInsertTail(lst,n,str);
            }
            fclose(f3);
        }
        else if(choice == 3)
        {
            scanf("%s",str);
            showData1(lst,str);
        }
        else if(choice == 4)
        {
            scanf("%d\t%s", &n,str);
            lst = llInsertHead(lst,n,str);
        }
        else if(choice == 5)
        {
            scanf("%d\t%s", &n,str);
            lst = llInsertTail(lst,n,str);
        }
        else if(choice == 6)
        {
            scanf("%d",&n);
            lst = Remove(lst,n);
        }
        else if(choice == 7)
        {
            FILE *f1=fopen("C:\\Users\\AD\\OneDrive - Hanoi University of Science and Technology\\Schedule2.txt","w");
            for (Node_t* p = lst; p != NULL; p = p->next){
                fprintf(f1,"%d ",p->malop);
                fprintf(f1,"%s ",p->mahp);
                fprintf(f1,"\n");}
        fclose(f1);
        }
        else if(choice == 8) {printf("8");}
        else if(choice == 9)
        {
            break;
        }
    }
    return 0;
}
