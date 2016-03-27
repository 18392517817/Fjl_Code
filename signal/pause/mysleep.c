#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
void alarm_handler(int signo)
{
	
}
unsigned int mysleep(unsigned int msecs)
{

	struct sigaction act,oact;
	memset(&act,0,sizeof(act));
	memset(&oact,0,sizeof(oact));
	act.sa_handler = alarm_handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM,&act,&oact);
	alarm(msecs);
	pause();//`
	int ret=alarm(0);
	sigaction(SIGALRM,&oact,NULL);
	return ret;
}
int main()
{
	while(1)
	{
		mysleep(1);
		printf("haha ...\n");
	}
	return 0;

}
