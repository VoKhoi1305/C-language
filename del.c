#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char time[100],s[100];
	int y,m,d;
    int n;
   struct node *next;
}node_t;
node* newnode(){
	node_t p=(node)malloc(sizeof(node));
	p->n=1;
	p->next=NULL;
	return p;

}
node*head;
node*head1;


void output()
{
	node*p=head1;
	while(p!=NULL)
	{
		printf("%s %d\n",p->time,p->n);
		p=p->next;
	}

}

void count()
{
	node*p1=head1;
	while(p1!=NULL)
	{
		if(head->y==p1->y&&head->m==p1->m&&head->d==p1->d)
		{
			p1->n++;
			head=head->next;
			return;
		}
	p1=p1->next;
	}
	if(p1==NULL)
	{
		node*k=head1;
		while(k->next!=NULL)
		{
			k=k->next;
		}
		k->next=head;
		head=head->next;
		k=k->next;
		k->next=NULL;
	}
}
void change()
{
    node*pk=newnode();
	node*p=head1;

	while(p!=NULL)
	{
		node *p1=p->next;
		while(p1!=NULL)
		{
			if(p1->y*12*30+p1->m*30+p1->d<p->y*12*30+p->m*30+p->d)
			{
				pk->y=p->y;
				pk->m=p->m;
				pk->d=p->d;
				pk->n=p->n;
				strcpy(pk->time,p->time);
				p->y=p1->y;
				p->m=p1->m;
				p->d=p1->d;
				p->n=p1->n;
				strcpy(p->time,p1->time);
				p1->y=pk->y;
				p1->m=pk->m;
				p1->d=pk->d;
				p1->n=pk->n;
				strcpy(p1->time,pk->time);
			}
			p1=p1->next;
		}
		p=p->next;
	}

}
int main(){
	node*p=newnode();
	scanf("%s",p->time);
	if(strcmp(p->time,"*")==0)
	return 0;
	fgets(p->s,100,stdin);
	sscanf(p->time,"%d-%d-%d",&p->y,&p->m,&p->d);
	head=p;
	while(1)
	{
	node*p1=newnode();

		scanf("%s",p1->time);
	if(strcmp(p1->time,"*")==0)
	break;
	fgets(p1->s,100,stdin);
	sscanf(p1->time,"%d-%d-%d",&p1->y,&p1->m,&p1->d);
	p1->next=head;
	head=p1;
	}
	head1=head;
	head=head->next;
	head1->next=NULL;
	while(head!=NULL)
	{
		count();

	}
	change();
	output();

}
