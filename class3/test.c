#include<stdio.h>

int accum=0;

int sum(int x, int y)
{
	int t=x+y;
	accum+=t;
	return t;
}

int main()
{
int j=sum(2,3);
printf("j is :%d\n",j);
return 0;

}
