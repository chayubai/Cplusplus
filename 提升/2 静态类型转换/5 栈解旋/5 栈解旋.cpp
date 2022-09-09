#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		cout << "我自己的异常" << endl;
	}
};

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

int myDivision(int a, int b)
{
	Person p1;//释放
	if (b == 0)
	{
		//从try代码块开始，到throw抛出异常之前，所有栈上的数据都会被释放掉，释放的顺序和调用构造函数的顺序相反
		//这个过程称为栈解旋
		Person p2;//释放

		throw MyException();//抛出MyException的匿名对象
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try//尝试执行以下代码检测是否异常，如果异常则进行处理，如果没有异常catch段代码是不会执行
	{
		Person p3;//释放
		myDivision(a, b);
	}
	catch (int)//处理：异常的捕获
	{
		cout << "int类型异常捕获" << endl;
	}
	//注意：如果没有人去处理抛出的异常，程序就会终止
	catch (char)
	{
		cout << "char类型异常捕获" << endl;
	}
	catch (MyException e)//自定义类型的异常处理
	{
		e.printError();
	}
	catch (double)
	{
		throw;//捕获到了异常，但是不想处理，继续向上抛出这个异常
	}
	catch (...)//...代表其他类型
	{
		cout << "其他类型异常捕获" << endl;
	}
}
int main()
{
	try
	{
		test();
	}
	catch (double)
	{
		cout << "main函数中 double类型异常捕获" << endl;
	}
	catch (...)
	{
		cout << "main函数中 其他类型异常捕获" << endl;
	}

	return 0;
}
