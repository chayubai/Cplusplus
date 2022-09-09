#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int myDivision(int a, int b)
{
	if (b == 0)
	{
		throw b;//抛出这个异常的值
	}
	return a / b;
}
void CallDivide(int x, int y)
{
	myDivision(x, y);
	//CallDivide这个函数内没有处理异常
}
void test()
{
	int a = 10;
	int b = 0;
	//尝试检查异常
	try//尝试执行以下代码检测是否异常，如果异常则进行处理，如果没有异常catch段代码是不会执行
	{
		CallDivide(a, b);
	}
	//异常捕获后，进行处理
	catch (int e)//异常时，根据抛出的值的类型进行匹配。可以接受抛出来的值
	{
		cout << "除数为" << e << endl;
	}

	//test这个函数处理了异常
}
int main()
{
	test();
	//注意：如果异常抛到顶层，还没有人处理，这个时候程序会调用terminate()终止程序
	//即：C++的异常机制：跨函数，且异常必须处理
	return 0;
}