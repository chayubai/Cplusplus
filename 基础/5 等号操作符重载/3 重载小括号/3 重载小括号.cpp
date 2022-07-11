#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
void MyPrint2(string str)
{
	cout << str << endl;
}
void test1()
{
	MyPrint myPrint;
	myPrint("hello world");//仿函数，对象调用重载的()运算符。本质是一个对象，通常称这种对象为函数对象。
	//使用的时候很像函数的调用，因此称为仿函数

	MyPrint2("hello world");//普通函数
}

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test2()
{
	MyAdd myAdd;
	cout << myAdd(1, 1) << endl;

	//()的重载很灵活

	cout << MyAdd()(1, 1) << endl;// MyAdd() - 匿名对象调用重在的()运算符，可以称为匿名的函数对象
	//匿名对象特点：当前行执行完立即释放，更多用于仿函数
}
int main()
{
	//test1();
	test2();
	return 0;
}








#if 0

class Sqr
{
public:
	Sqr(int a)
	{
		this->a = a;
	}
	int operator()(int value)
	{
		return value * value;
	}
	int operator()(int value1,int value2)
	{
		return value1 * value2;
	}
private:
	int a;
};
int main()
{
	Sqr s(10);
	int value = s(2);//s.operator()(2)
	//将一个对象当成普通函数来调用。称这种对象是仿函数/伪函数/函数对象
	cout << value << endl;
	value = s(10, 20);
	cout << value << endl;

	return 0;
}
#endif