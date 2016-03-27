#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void printsigset(sigset_t *set)
{
	int i=0;
	for(;i<32;i++)
	{
		if(sigismember(set,i)){
			putchar('1');
		}else{
			putchar('0');
		}
	}
printf("\n");
}
int main()
{
	sigset_t new,old;
	sigemptyset(&new);
	sigaddset(&new,SIGINT);
	sigprocmask(SIG_BLOCK,&new,NULL);
	while(1)
	{
		sigpending(&old);
		printsigset(&old);
		sleep(1);
	}
	return 0;
}
