#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//异常的基类
class BaseException
{
public:
	virtual void printError() = 0;
};

//空指针异常
class NULLPointerException:public BaseException
{
public:
	void printError()
	{
		cout << "NULLPointerException异常" << endl;
	}
};

//越界异常
class OutOfRangeException :public BaseException
{
public:
	void printError()
	{
		cout << "OutOfRangeException异常" << endl;
	}
};

void doWork()
{
	//throw NULLPointerException();
	throw OutOfRangeException();
}

void test()
{
	try
	{
		doWork();
	}
	catch (BaseException& e)//BaseException& e = OutOfRangeException();父类引用指向子类对象
	{
		e.printError();
	}
}

int main()
{
	test();
	return 0;
}