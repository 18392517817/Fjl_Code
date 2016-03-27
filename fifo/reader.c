#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define _PATH_  "/bit/fifo/fifo.tmp"
#define _SIZE_ 256
int main()
{
	int fd=open(_PATH_,O_RDONLY);
	if(fd<0){
	perror("open");
	exit(1);
	}
	char msg[_SIZE_];
	while(1){
	memset(msg,'\0',sizeof(msg));
	ssize_t s=read(fd,msg,sizeof(msg)-1);
	if(s==0){
	printf("reader quit!\n");
	break;
	}else if(s>0){
	msg[s]='\0';
	printf("reader : %s\n",msg);
	}else {
	printf("read");
	exit(2);
	}

	}
	close(fd);
	return 0;
}
