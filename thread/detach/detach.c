#include<stdio.h>
#include<pthread.h>
void * thread_run(void *arg)
{
	printf("thread_run\n");
	sleep(10);
}
int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,thread_run,NULL);
	sleep(5);

	printf("main is run\n");
	pthread_detach(tid);
	printf("main thread set detach done...\n");
	sleep(2);
	printf("begin thread cancel\n");
		int ret=pthread_join(tid,NULL);
	if(ret!=0){
		perror("pthread_join");
	}else{
		printf("");
	}
	return 0;
}
