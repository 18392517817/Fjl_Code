#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define _READER_NUM_ 3
#define _WRITER_NUM_ 2

pthread_rwlock_t lock;
int buf=0;
void *reader(void *arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		if(pthread_rwlock_tryrdlock(&lock)!=0){
			printf("writer is writing ,reader waiting..\n");
		}else{
			printf("reader is :%u,read val is :%d\n",pthread_self(),buf);
			pthread_rwlock_unlock(&lock);
		}
		sleep(2);
	}
}
void *writer(void *arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		if(pthread_rwlock_trywrlock(&lock)!=0){
			printf("reader is writing ,writer waiting..\n");
			sleep(1);
		}else{
			buf++;
			printf("writer is :%u,write val is :%d\n",pthread_self(),buf);
			pthread_rwlock_unlock(&lock);
		}
		sleep(1);
	}
}

int main()
{
	pthread_rwlock_init(&lock,NULL);
	pthread_t id;
	int i;
	for(i=0;i<3;++i){
		pthread_create(&id,NULL,writer,NULL);
		
	}
	for(i=0;i<2;++i){
		pthread_create(&id,NULL,reader,NULL);

	
	}
	sleep(100);
	return 0;
}

int test()
{
/*
pthread_t write_id,read_id;

pthread_create(&write_id,NULL,writer,NULL);
pthread_create(&read_id,NULL,reader,NULL);

pthread_join(&write_id,NULL);
pthread_join(&read_id,NULL);

pthread_destroy(write_id);
pthread_destroy(read_id);
*/
return 0;
}
