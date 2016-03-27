#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main()
{
   int count=0;
   alarm(1);
	while(1)
	{
		printf("count is:%d\n",count++);
	}
	return 0;
}
