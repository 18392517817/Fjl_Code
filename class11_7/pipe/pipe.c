#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//father read chid write
	int fd[2];
	int ret=pipe(fd);
	if(ret<0)	{
		perror("pipe");
		exit(1);
	}
#ifdef _DEBUG_
		printf("pipe success ,fd[0]%d,fd[1] : %d\n",fd[0],fd[1]);
#endif 
	pid_t id =fork();
	if(id<0){
	perror("fork");
	close(fd[0]);
	close(fd[1]);
	exit(2);
	}else if(id==0){//child  read
		close(fd[1]);
#define _SIZE_  1024
		char buf[_SIZE_];
//#undef
		memset(buf,'\0',sizeof(buf));
	unsigned int count=0;   
		int i=10;
		while(i){
	ssize_t s=	read(fd[0],buf,sizeof(buf)-1);
	if(s>0){
		buf[s]='\0';
		printf("child  :   %d, father said:%s,   count  : %d\n",getpid(),buf,count++);
	}else if(s==0){
	printf("writer stop wrinting ,close fd[1]\n");
	break;
	}
	i--;
		}
	close(fd[0]);
	exit(0);
		
	}else {//father  write 
	close(fd[3]);
	printf("father   :%d \n",getpid());
	char *msg="you are a good man!";
	int i=10;
	unsigned int  count=0;
	while(i){
	write(fd[1],msg,strlen(msg));

	printf("i am write ... %d\n",count++);
	//if(i==5){
	//slepp(10);
	//}
	sleep(1);
	i--;
	
	}
	close(fd[1]);
    int ret  =  waitpid(id,NULL,0);
    if(ret==id){
    printf("wait success!");
    }else{
   perror("waitpid");
    exit(3);
    }
	}
	return 0;

}
