#include"bigdata.h"

void test1()
{
	cout<<"this is first"<<endl;
	cout<<BigData("123456789")+BigData("1234567890")<<endl;
}

int main()
{
	test1();
	return 0;
}
