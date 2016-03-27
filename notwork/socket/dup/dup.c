#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#define OPEN_FILE "./log"
int main()
{
	close(0);
    int fd=open(OPEN_FILE,O_RDWR|O_CREAT,0666);
//	FILE *f_d=fopen(OPEN_FILE,'w+');
//	if(NULL==f_d){
//		perror("fopen");
//		return 1;
//	}
	if(fd<0){
		perror("fopen");
		return 1;
	}
	int count=10;
	while(count){
		printf("hello world : %d\n",count--);
		count--;
	}
	fflush(stdout);
//	fclose(f_d);
   close(fd);
	return 0;
}
