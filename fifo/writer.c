
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define _PATH_  "/bit/fifo/fifo.tmp"
int main()
{
	char *msg = "you are a good man !";
	umask(0);
	if(mkfifo(_PATH_,S_IFIFO|0666)==0){//succes 
	int fd = open(_PATH_,O_WRONLY);
	if(fd==0){
		perror("open");
		exit(2);
		}
		int count=10;
		while(count){
			write(fd,msg,strlen(msg));
			sleep(1);
			count--;
		}
		close(fd);
	}else{
		perror("mkfifo");
		exit(1);
	}
	return 0;
}
