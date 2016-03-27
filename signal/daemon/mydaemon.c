#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

void mydaemon()
{
	umask(0);
	pid_t pid;
	pid=fork();
	if(pid<0){
	}else if(pid!=0){
		exit(0);
	}
	setsid();
    if(pid<0){
	return ;
	}else if(pid!=0){
		exit(0);
	}
	chdir("/");
	close(0);
	close(1);
	close(2);
	return ;

}

int main()
{
	mydaemon();
//	daemon(0,0);
	while(1)
	{
		sleep(1);
	}
	return 0;
}
