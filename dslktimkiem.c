#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ELEMENT 100
typedef struct {
  char name[20];
  char tel[20], email[32];
} phoneAddr_t;
struct node
{
	phoneAddr_t data;
	struct  node *next;
};
typedef struct node node;


node *makeNode(phoneAddr_t a)
{
	node *newNode = (node*) malloc(sizeof(node));
	strcpy((newNode->data).name,a.name);
	strcpy((newNode->data).tel,a.tel);
	strcpy((newNode->data).email,a.email);
	newNode->next = NULL;
	return newNode;
}
int size(node *head)
{
	int cnt = 0;
	while(head != NULL) cnt++;
	return cnt;
}
void pushBack(phoneAddr_t a,node **head)
{
	node *newNode = makeNode(a);
	if(*head == NULL)
	{
		*head = newNode;return;
	}
	node *tmp = *head;
	while(tmp->next != NULL) tmp = tmp->next;
	tmp->next = newNode;
}

	void pushFront(node **head, phoneAddr_t x)
	{
		node* newNode = makeNode(x);
		newNode->next = (*head);
		(*head) = newNode;

	}
int search(node *head,char a[])
{
	int cnt = 0;
	while(head->next != NULL)
	{
		if(strcmp(a,(head->next->data).name)==0)
		{
			pushFront(&head,head->next->data);
			head->next = head->next->next;

			return cnt;
		}
		cnt++;
		head = head->next;
	}
	return -1;
}

int main()
{
	node *head = NULL;
	char key[] = "A";
	 phoneAddr_t a[MAX_ELEMENT] = { {"A", "1", "1@"},
                                 {"B", "2", "2@"},
                                 {"C", "3", "3@"},
                                 {"D", "4", "4@"},
                                 {"E", "5", "5@"}};
	for(int i=0;i<5;i++)
	{
		pushBack(a[i],&head);
	}


	printf("Search of %s returns %d\n", key, search(head, key));
	return 0;
}
