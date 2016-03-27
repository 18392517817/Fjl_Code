#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int val=0;
	while(1)
	{
		sleep(1);
		printf("%u  ",getpid());
		printf("%d\n",val++);
	}
	return 0;
}
