#include<stdio.h>
#include<signal.h>
void handler(int sig)
{
	int status=0;
	pid_t id;
	while((id=waitpid(-1,&status,0))>0){
		printf("wait success  ... pid is :%d\n",id);
	
	}
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));

	act.sa_handler=handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NNULL);

	sigaction();

	pid_t id=fork();
	if(id>0){
	}else{
	
	}

	return 0;
}
