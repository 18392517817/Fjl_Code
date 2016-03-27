#include<signal.h>
#include<stdio.h>
#include<string.h>
struct sigaction{
	void (*sa_handler)(int);
	sigset_t sa_mask;
}
//void handler(int sig)
//{
//	printf("this is handler...\n");
//	
//}
int main()
{

	struct sigaction new_act;
	memset(&new_act,0,sizeof(new_act));
	
//	signal(SIGINT,handler);

	while(1)
	{
		printf("hello bit\n");
		sleep(1);
	}
	return 0;
}
