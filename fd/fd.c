#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

//#define _DEBUG_
const char *msg="hello change world!\n";
int main()
{
	int fd=open("./log",O_RDWR|O_CREAT,0775);
	if(fd<0){
	perror("open");
	exit(1);
	}
#ifdef _DEBUG_
	printf("fd : %d\n",fd);
#endif
	int i=100;
	while(i)
	{
		write(fd,msg,strlen(msg));		i--;
	}
//	char buf[64];
//	memset(buf,'\0',sizeof(buf));
//	ssize_t ret;
  // do{
	
	//   ret=read(fd,buf,sizeof(buf)-1);
	  // buf[ret]='\0';
	  // printf("%s",buf);
//   }while(ret>0);
 //  fflush(stdout);

	close(fd);
	return 0;
}
