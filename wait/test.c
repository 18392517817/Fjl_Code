#include<stdio.h>
#include<string.h>

char *msg ="hello world!";

int main()
{
	write(1,msg,strlen(msg));
fwrite(msg,1,strlen(msg),stdout);

	return 0;

}
