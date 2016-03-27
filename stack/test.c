#include<stdio.h>
#include<stdlib.h>

void bug()
{
	printf("you are a good man!\n");
    sleep(5);
  //  exit();
}

int  stack_test(int x,int y);

int main()
{
	int a=0x1111;
	int b=0x2222;
	int ret=stack_test(a,b);
	printf("you should run here!,ret: %x\n",ret);
  return ;
}
int  stack_test(int x,int y)
{
	int *p=&x;
//	*(--p)=(int)bug;
	int z=0x3333;
	return z;
}

