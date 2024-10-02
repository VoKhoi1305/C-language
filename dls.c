

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct node{

	int data;

	struct node *next;

};

typedef struct node node;

node *makeNode(int x)

{

	node *newNode = (node*) malloc(sizeof(node));

	newNode->data = x;

	newNode->next = NULL;

	return newNode;

}

int size(node *head)// dem so phan tu trong danh sach

{	int cnt = 0;

	 while(head != NULL)

	 {

	 	++cnt;

	 	head = head->next;

	 }

	 return cnt;

}

void duyet(node *head)// in ra damh sach

{

	while(head != NULL)

	{

		printf("%d ",head->data);

		head = head->next;

	}

}

void addfirst(node **head,int x)// them vao dau

{

	node *newNode = makeNode(x);

	newNode->next = (*head);

	(*head) = newNode;

}

void addlast(node **head,int x)// them vao cuoi

{

	node *newNode = makeNode(x);

	if(*head == NULL)

	{

		(*head) = newNode;return;

	}

	node *tmp = (*head);

	while(tmp->next != NULL)

	{

		tmp = tmp->next;

	}

	tmp->next = newNode;

}

void insert(node **head,int x,int k)

{

	int n = size(*head);

	if(k<1 || k>n ) return;

	if(k==1)

	{

		addfirst(head,x);return;

	}

	node *tmp = (*head);

	for(int i=0;i<k-1;i++)

	{

		tmp = tmp->next;

	 }

	 node *newNode = makeNode(x);

	 newNode->next = tmp->next;

	 tmp->next = newNode;return;

}

void popFront(node **head){

	if(*head == NULL) return;

	node* tmp = *head;

	*head = tmp->next;

	free(tmp);

}

void erase(node **head, int k){

	int n = size(*head);

	if(k < 1 || k > n) return;

	if(k == 1) popFront(head);

	else{

		node *truoc = *head;

	node *sau = *head;

	for(int i = 1; i <= k - 1; i++){

	sau = truoc;

	truoc = truoc->next;

	}

	sau->next = truoc->next;

	free(truoc);

	}

}

int check(node *head, int x)

{



	while(head != NULL)

	{

		if(head->data == x) return 0;

		head = head->next;

	}

	return 1;

}

int seek(node *head,int x)

{

	int cnt = 0;

	while(head != NULL)

	{

		if(head->data != x)

		{

			cnt++;

			head = head ->next;

		 }


		else break;

	}

	return cnt;


}


void reverse(node *head)

{


}

int main()

{

	node *head=NULL;

	int n;

	scanf("%d",&n);

	int a[n];

	for(int i=0;i<n;i++)

	{

		scanf("%d",&a[i]);

		addlast(&head,a[i]);


	}

	char str[15];



	while(1)

	{

		scanf("%s",str);

		if(strcmp(str,"addfirst")==0)

		{

			int a;

			scanf("%d",&a);

			if(check(head,a)) addfirst(&head,a);

			}

		else if(strcmp(str,"addlast")==0)

		{

			int a;

			scanf("%d",&a);

			if(check(head,a)) addlast(&head,a);

			}

		else if(strcmp(str,"addafter")==0)

		{

			int a,b;

			scanf("%d %d",&a,&b);

			if(check(head,a)) insert(&head,a,b+1);

			}

		else if(strcmp(str,"addbefore")==0)

		{

			int a,b;

			scanf("%d %d",&a,&b);

			if(check(head,a)) insert(&head,a,b-1);

			}

		else if(strcmp(str,"remove")==0)

			{

				int a;

				scanf("%d",&a);


				erase(&head,seek(head,a)+1);

				}

		else break;

	}

	duyet(head);



}
