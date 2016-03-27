#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t id=fork();
     if(id==0){

printf("this is child:%p\n",getpid());
}else if(id>0){

printf("this is father:%p\n",getpid());
}else{}
printf("this is all:\n");
	return 0;
}
