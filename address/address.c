#include<stdio.h>

int main()
{
	unsigned long tmp;
	tmp = 0x12345678;
	printf("tmp address :0x%081X\n",&tmp);
	return 0;
}
