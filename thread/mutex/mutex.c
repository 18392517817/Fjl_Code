#include<stdio.h>
#include<pthread.h>
pthread_mutex_t _mutex;
int count=0;
int  lock_init(pthread_mutex_t *_lock)
{
	//flag=1;//bu shi yuan zi cao zuo 
  return pthread_mutex_init(_lock,NULL);

}
int  lock(pthread_mutex_t *_lock)
{
	//flag=0;
	return 	pthread_mutex_lock(_lock);
}
int  lock_delete(pthread_mutex_t *_lock)
{
	//flag=1;
	return 	pthread_mutex_destroy(_lock);
}
int  unlock(pthread_mutex_t *_lock)
{
	//flag=1;
	return 	pthread_mutex_unlock(_lock);
}
void * thread1(void *arg)
{
	int i=50;
	while(i){
		//i--;
		//count++;
		lock(&_mutex);
		int tmp=count;
		printf("this is thread1:%d\n",tmp);
		count=tmp+1;
		i--;
		unlock(&_mutex);
	}
	return NULL;
	
}
void * thread2(void *arg)
{
	int i=50;
	while(i){
		//i--;
		//count++;
		lock(&_mutex);
		int tmp=count;
		printf("this is thread2:%d\n",tmp);
		count=tmp+1;
		i--;
		unlock(&_mutex);
	}
	return NULL;
	

}

int main()
{
	pthread_t tid1,tid2;
	lock_init(&_mutex);	
	int ret1=pthread_create(&tid1,NULL,thread1,NULL);
	int ret2=pthread_create(&tid2,NULL,thread2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("res :%d\n",count);
	lock_delete(&_mutex);
	return 0;
}
