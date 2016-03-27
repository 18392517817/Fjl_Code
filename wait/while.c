
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{	
	int num=0;
	int i=0;
	for(;i<2;++i){
	pid_t id=fork();
	 if(id==0){
	printf("i am child :\n");
	printf("num:%d\n",num++);
//	sleep(1);
	}else{sleep(10);
	printf("i am father:\n");
	printf("num:%d\n",num);
//	sleep(1);
	}
	}
	sleep(2);
	return 0;
}
