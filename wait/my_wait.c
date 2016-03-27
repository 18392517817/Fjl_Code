#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	pid_t id =fork();
	if(id<0){//filed
	perror("fork");
	exit(1);
	}
	else if(id==0){//child
	printf("this is child ,  pid : %d,ppid : %d\n",getpid(),getppid());
  sleep(10);
  exit(5);
	}else{//father
	
	printf("this is father , pid : %d,ppid : %d\n",getpid(),getppid());
	int status=0;//shu chu xin can shu 
	//pid_t  child_id=waitpid( id,&status,0);
	pid_t child_id=0;
	do{
	child_id = waitpid(id,&status,WNOHANG);
	sleep(1);
	printf("father is wait ...\n");
	}while(child_id<=0);
	printf("wait success,pid :  %d\n",child_id);
	printf("exit code        :  %d\n",WEXITSTATUS(status));
	printf("signal no        :  %d\n",WTERMSIG(status));
	}
//	printf("this proc is quit ,pid : %d\n",getpid());

	return 0;
	
}



