#include"list.h"

#define mutex PTHREAD_MUTEX_INITIALIZER

void *producer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("");
		pthread_mutex_unlock(&mutex);


	}
}
void * consumer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);

		pthread_mutex_unlock(&mutex);
	}
}
void main()
{
//	link head;
//	head=create(head);
//	show(head); 
}
