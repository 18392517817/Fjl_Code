#include<stdio.h>
#include<pthread.h>

void * thread_run(void *arg)
{
	printf("thread_run arg:%d\n",arg);
	int count=3;
	while(count)
	{
		printf("this is thread_run ,pid:  %d  thread_run id: %u\n",getpid(),pthread_self());
		count--;
		sleep(1);
	}
		
	return NULL;
}
int main()
{
	pthread_t tid;
	int ret=pthread_create(&tid,NULL,thread_run,(void*)3);
	if(ret!=0){
		perror("pthread_create");
		return 1;
	}
	else{
		printf("this is thread main run ,pid:  %d  main thread id: %u\n",getpid(),pthread_self());
		sleep(3);
	}
	void *tret;
//	pthread_join(tid,NULL);
	pthread_join(tid,&tret);
	printf("thread id is :%u  code is :%d\n",tid,(int)tret);
	return 0;
}
