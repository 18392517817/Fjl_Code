#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>
int main()
{
	int _pipe[2];
	int ret =pipe(_pipe);
	if(ret==-1){
	printf("creat pipe error! errno code is :%d\n",errno);
	return 1;
	}
	pid_t id=fork();
	if(id<0){
	printf("fork error!");
	return 2;
	}else if(id==0){
	close(_pipe[0]);
	int i=0;
	char *_mesg_c=NULL;
	while(i<20){
	if(i<10){
	_mesg_c="i am child!\n";
	write(_pipe[1],_mesg_c,strlen(_mesg_c)+1);
	}
	sleep(1);
	++i;
	}
	}else{//father read
	close(_pipe[1]);
	char _mesg[100];
	int j=0;
	while(j<3){
	memset(_mesg,'\0',sizeof(_mesg));
	int ret=read(_pipe[0],_mesg,sizeof(_mesg));
	printf("%s :code is :%d\n",_mesg,ret);
	j++;
	}
//	close(_pipe[0]);
	sleep(3);
//	if(waitpid(id,NULL,0)<0)
//	{
//		return 3;
//	}
	}
	return 0;
}
