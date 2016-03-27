#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t id =fork();
	if(id<0){
	perror("fork");
	exit(1);
	}
	else if(id==0){
	printf("this is child ,pid : %d,ppid : %d\n",getpid(),getppid());
	sleep(5);
	}
	else{
	
	printf("this is father  ,pid : %d,ppid : %d\n",getpid(),getppid());
	int status=0;
	pid_t ret=wait(&status);
	if(ret<0){perror("wait");}
	else
	{
		printf("wait success, wait pid is :%d\n",ret);
		printf("child get signal no:%d\n",0xff&status);
		printf("child quit code : %d\n ",0xff&(status>>8));
	}
	}
	printf("this proc is quit ,pid : %d\n",getpid());
	exit(78);
	return 0;
	
}



