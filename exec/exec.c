#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define FILE_NAME "log"

int main()
{
	pid_t id = fork();
	if(id<0){
	perror("fork");
	exit(1);
	}else if(id==0){
	sleep(3);	
//	execl("/bin/ls","ls","-l",NULL);
//	execl("/bin/touch","touch",FILE_NAME,NULL);
//	execlp("ls","ls","-l",NULL);
		char *my_env[]={
		"PATH=/bit/exec",
    	NULL,
		};
//	execle("mytest","mytest",NULL,my_env);//?
	char *my_arg[]={
	"mytest",
	NULL,
	};
//	execv("/bin/ls",my_arg);
//	execv("mytest",my_arg);
//	execvp("mytest",my_arg);//?
//	execve("/bin/ls",my_arg,my_env);
	execve("mytest",my_arg,my_env);
	printf("you shouldn't run here\n");
	}else{
	printf("father is begin wait ...\n");
	pid_t  child_id =waitpid(id,NULL,0);
	if(child_id==id){
	printf("wait success\n");
	}else{
	printf("wait failed\n");
	}
	}
	return 0;
}
