#include<stdio.h>
int mut(int a, int b)
{
return a/b;
}
int main()
{
	int a=1;
	int b=2;
	int c=mut(b/a);
	printf("%d\n",c);
	return 0;
}
