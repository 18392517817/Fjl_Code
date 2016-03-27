#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t id=fork();
	if(id<0){
	perror("fork");
	exit(1);
	}else if {
	printf("this is child:");
	sleep(1);
	exit(1);
	}
	else{
	printf("this is father:");
	int status=0;
	pit_t child_id =waitpid(id,&status,0);
	if(child_id>0){
	if(WIFEXITED(status)){
	printf("happy, proc is ok \n");
	int code = WEXITSTATUS(status);
	if(code=0){
	printf("proc is success\n");
	
	}
	}else{
	perror("problem hapand");
	}else{
	
	}
	}

	}
return 0;
}
