#include<stdio.h>
#include<signal.h>

volatile int falg=1;
void handler(int sig)
{
	printf("handler is %d\n",sig);
	falg=0;
}
int main()
{

	signal(SIGINT,handler);
	while(falg);
//	{
//		printf("haha...\n");
//		sleep(1);
//	}
	return 0;
}
