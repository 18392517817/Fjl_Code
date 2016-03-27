#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct _list
{
	struct _list *next;
	int _val;

}p_list;

p_list *head=NULL;
static pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t need_product=PTHREAD_COND_INITIALIZER;

void init_list(p_list *list)
{
	if(list!=NULL)
	{
		list->next=NULL;
		list->_val=0;
	}
}
void *consumer1(void *_val)
{
	p_list *p=NULL;
	for(;;){
		pthread_mutex_lock(&lock);
		while(NULL==head){
			printf("head is empty,consumer1 is done...\n");
			pthread_cond_wait(&need_product,&lock);
			printf("head have num ,consumer1 is going...\n");
		}
		{
			p=head;
			head=head->next;
			p->next=NULL;
			pthread_mutex_unlock(&lock);
			printf("consumer1 success ,val is : %d\n",p->_val);
			free(p);
			p=NULL;
		}
	}
		return NULL;
}
void *consumer2(void *_val)
{
	p_list *p=NULL;
	for(;;){
		pthread_mutex_lock(&lock);
		while(NULL==head){
			printf("head is empty,consumer2 is done...\n");
			pthread_cond_wait(&need_product,&lock);
			printf("head have num ,consumer2 is going...\n");
		}
		{
			p=head;
			head=head->next;
			p->next=NULL;
			pthread_mutex_unlock(&lock);
			printf("consumer2 success ,val is : %d\n",p->_val);
			free(p);
			p=NULL;
		}
	}
		return NULL;
}

void *product(void *_val)
{
	for(;;){
		sleep(rand()%2);
		p_list *p=malloc(sizeof(p_list));
		pthread_mutex_lock(&lock);
		init_list(p);
		p->_val=rand()%1000;
		p->next=head;
		head=p;
		pthread_mutex_unlock(&lock);
		printf("call allconsumer! product success,val is : %d\n",p->_val);
		pthread_cond_signal(&need_product);
	}
}

int main()
{
	pthread_t t_product;
	pthread_t t_consumer1,t_consumer2;
	pthread_create(&t_product,NULL,product,NULL);
	pthread_create(&t_consumer1,NULL,consumer1,NULL);
	pthread_create(&t_consumer2,NULL,consumer2,NULL);

	pthread_join(t_product,NULL);
	pthread_join(t_consumer1,NULL);
	pthread_join(t_consumer2,NULL);

	return 0;
}
