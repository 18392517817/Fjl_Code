#include<stdio.h>
#include<stdlib.h>

int main(int argc,char ** argv[])
{
	int id=fork();//
	//int id=vfork();//child  beffor father;
	if(id>0)
	{
		printf("Parent is sleeping..\n");
		sleep(5);
	}
	if(id==0)
	{
		printf("Child process is done.\n");
	}
		exit(EXIT_SUCCESS);

	
return 0;
}
