#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id = fork();
	if(id<0){
exit(0);
}
else if(id==0){

	printf("pid=%d,ppid=%d\n",getpid(),getppid());
	printf("uid=%d,euid=%d\n",getuid(),geteuid());
	printf("gid=%d,egid=%d\n",getgid(),getegid());
}
else{
	printf("pid=%d,ppid=%d\n",getpid(),getppid());
	printf("uid=%d,euid=%d\n",getuid(),geteuid());
	printf("gid=%d,egid=%d\n",getgid(),getegid());
sleep(3);
}

	return 0;
}
