

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
  exit(6);
	}
	else{
	
	printf("this is father  ,pid : %d,ppid : %d\n",getpid(),getppid());
	int status=0;//shu chu xin can shu 
	pid_t child_id;
	do{
	child_id=waitpid(id,&status,WNOHANG);//WNOHANG
	sleep(1);
	}while(child_id<=0);
		printf("wait success, wait pid is :%d\n",child_id);
		printf("child quit code : %d\n ",0xff&(status>>8));//
		printf("child get signal no:%d\n",0xff&status);
	
	if(child_id>0){
	printf("wait success ,pid is :%d\n",getpid());
	}
	else{
	printf("wait fail\n");
	}
	
	}
//	printf("this proc is quit ,pid : %d\n",getpid());
	exit(9);
	return 0;
	}
	






