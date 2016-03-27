#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * thread_run(void *_val)
{
//	printf("%s  :pid is : %d, tid is : %u \n",(char*)_val,(int)getpid(),(unsigned long long )pthread_self());
   int count=5;
	while(count){
		printf("this is thread run: pid %d thread_id%u \n",getpid(),pthread_self());
		count--;
	}
	return NULL;
}
void * thread_run_exit(void *_val)
{
	int count=5;
	while(count){
		printf("this is thread run_exit: pid %d thread_id%u \n",getpid(),pthread_self());
		sleep(1);
		count--;
	}
	pthread_exit((void*)1);	
	return NULL;
	
}
void * pthread_run_cancel(void *_val)
{
	pthread_t tid;
	int count=5;
	while(count){
		printf("this is thread cancel: pid %d thread_id%u \n",getpid(),pthread_self());
		sleep(1);
	count--;
	}
	pthread_exit((void*)32);
	return NULL;
	
}

int main()
{

	pthread_t tid;
	void *tret;
	printf("new tid:%u\n",tid);
//	int ret=pthread_create(&tid , NULL ,pthread_run_cancel,(void *)3);
//	int ret=pthread_create(&tid , NULL ,thread_run_exit,(void *)2);
	int ret=pthread_create(&tid , NULL ,thread_run,(void *)1);
//  int count=5;
//	while(count){
//		printf("this is main thread run: pid%d  main  thread_id: %u\n",getpid(),pthread_self());
//		sleep(1);
//		count--;
//
//	}
//
//	pthread_cancel((tid));	

	pthread_join(tid,&tret);
	printf("thread id is : %u calcel code is: %d\n",tid,(int)tret);//-1
	return 0;
}
