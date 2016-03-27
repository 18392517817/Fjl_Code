#include"list.h"
link create(link head)
{
	int temp;
 	link p,q;
	q=head=p=(node*)malloc(sizeof(node));
	printf("please input num ,0 is over\n ");
	while(scanf("%d",&temp),temp)
	{
		p->data=temp;
		if(p!=head)
		{
			q->next=p;
			q=p;
		}
		p=(node*)malloc(sizeof(node));
	}
	q->next=NULL;
	return head;
}
void push_front(link head,int data)
{
	cur=(node*)malloc(sizeof(node));
	assert(cur);
	cur->data=data;
	cur->next=head->next;
	head->next=cur;

}
void pop_front(link head)
{
	
}
void show(link head)
{
	link p=head;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
