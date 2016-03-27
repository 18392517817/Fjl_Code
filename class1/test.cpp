#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<iostream.h>
//using namespace std;

int  main()
{
	pid_t  id =fork();
  if(id==0){
   printf("i am child:%p\n",getpid());	
     exit(0);}
  else if(id>0){	
   printf("i am father:%p\n",getpid());	

}
    else{}
return 0;
}
