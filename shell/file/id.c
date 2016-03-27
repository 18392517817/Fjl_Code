#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	printf("curret:%d, father:%d\n",getpid(),getppid());
	return 0;
}
