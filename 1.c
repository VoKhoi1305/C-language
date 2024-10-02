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
void pushBack(phoneAddr_t a,node **head)
{
	node *newNode = makeNode(a);

		*head = newNode;


}

int search(node *head,char a[])
{
	int cnt = 0;
	while(head != NULL)
	{
		if(strcmp(a,(head->data).name)==0)
		{
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
	phoneAddr_t a[MAX_ELEMENT];
		int i=0;
	while(scanf("%s",a[i].name)&&strcmp(a[i].name,"#")!=0)
	{

		scanf("%s %s %s",a[i].tel,a[i].email);
		pushBack(a[i],&head);
		i++;
	}
	char key[20];
	scanf("%s",key);



	printf("%d\n", search(head, key));
	return 0;
}
