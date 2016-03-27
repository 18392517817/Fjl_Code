#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node*next;
}node,*link;
link create(link head);
void show(link head);
