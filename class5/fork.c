#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void doit()
{
	fork();
	fork();
	printf("hello\n");
	return ;
}
int main()
{
//	doit();	
	fork();
	fork();
	printf("hello\n");
	sleep(1);
	printf("helllo\n");
	exit(0);

}
