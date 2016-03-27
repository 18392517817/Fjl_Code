#include<stdio.h>
#include<errno.h>

#include<stdlib.h>
#include<string.h>

const	char *msg ="hello bit!\n";
int g_val = 0;
int main()
{
	int val=0;
	 printf("beffor fork!\n");//you huan chong qu //xing neng  gao 
	write(1,msg,strlen(msg));//wu huanchong qu 
//fwrite(msg,1,strlen(msg),stdout);
	pid_t  id=fork();
while(1){
	sleep(2);
    if(id<0){
    //perror("fork");
    	printf("%d : %s :\n",errno,strerror(errno));
    }else if(id==0){
    	g_val++;
    	val++;
    	printf("i am child ,pid is :%d ppid is :%d\n",getpid(),getppid());
    	printf("child  :  %d %d\n",g_val,val);
    
    	printf("child  :  %d %d\n",&g_val,&val);
    }
    else
    {
    
    	printf("i am father ,pid is :%d ppid is :%d\n",getpid(),getppid());
    	sleep(1);
    	printf("father :  %d %d\n",g_val,val);
    
    	printf("father :  %d %d\n",&g_val,&val);
    }
}
return 0;



}
