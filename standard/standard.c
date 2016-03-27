#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

const char * msg = "hello bit!\n";

int main()
{
	//close(2)
	int fd = open("./log",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
	perror("open");
		exit(1);
	}
	printf("fd : %d\n",fd);
	int i=10;
	while(i)
	{
		printf("%s",msg);
		i--;
	}
	fflush(stdout);
	perror("this is error msg ,should show on screen \n");
	fflush(stderr);
	close(fd);
	return 0;
}
