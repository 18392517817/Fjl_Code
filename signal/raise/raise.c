#include<stdio.h>
#include<signal.h>

int main()
{

	while(1)
	{
		sleep(1);
		printf("begin wait raise...\n");
		sleep(3);
//		raise(2);
		kill(getpid(),2);
		printf("end wait raise...\n");

	}
	return 0;
}
