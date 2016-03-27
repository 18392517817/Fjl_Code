#include<stdio.h>
#include<poll.h>

int main()
{
	int timeout = 300;//3000   3s
	char buf[1024];
	struct pollfd fd_poll[1];
	while(1){
		fd_poll[0].fd=0;
		fd_poll[0].events = POLLIN;
    	fd_poll[0].revents = 0;
		memset(buf,'\0',sizeof(buf));
		switch(poll(fd_poll,1,timeout)){
			case 0:
				perror("timeout");
				break;
			case -1:
				perror("poll");
				break;
			default:
				if(fd_poll[0].revents | POLLIN){
					gets(buf);//
					printf("%s\n",buf);//
				
				}
				break;
		}
	}
	return 0;
}
