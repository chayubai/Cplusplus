#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class MyException
{
public:
	MyException(const char* str)
	{
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}
	MyException(const MyException& ex)
	{
		error = new char[strlen(ex.error) + 1];
		strcpy(error, ex.error);
	}
	MyException& operator=(const MyException& ex)
	{
		if (error != NULL)
		{
			delete[] error;
			error = NULL;
		}

		error = new char[strlen(ex.error) + 1];
		strcpy(error, ex.error);

		return *this;
	}
	void printError()
	{
		cout << "异常信息：" << error << endl;
	}
	~MyException()
	{
		if (error != NULL)
		{
			delete[] error;
			error = NULL;
		}
	}
public://将属性和行为分离
	char* error;
};

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//抛出的异常数据类型，必须严格匹配
		//throw 变量;	抛出变量的类型的异常
		//throw -1;		//-1代表int类型，也可以用其他int数据。表示抛出int类型的异常
		//throw 'a';	//抛出char类型的异常
		//throw 3.14;	//抛出double类型的异常
		//...
		//throw "abc";	//抛出char*类型的异常
		/*
		string str = "abc";
		throw str;
		*/				//抛出string类型的异常

		throw MyException("自己写的异常");//抛出MyException的匿名对象
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}
	catch (char)
	{
		cout << "char类型异常捕获" << endl;
	}
	catch (MyException e)//自定义类型的异常处理，将匿名对象传入e，调用拷贝构造函数
	{//由于匿名对象里的error和形参e里的error都指向同一块空间。如果不重载拷贝构造函数，当匿名对象析构和e结束后，
		//对同一块空间释放两次，就会程序崩溃

		//技巧：注意：当如果可能需要用到拷贝或=赋值，最好把拷贝构造和=赋值操作符函数重载实现好
		e.printError();
	}
	/*catch (double)
	{
		throw;//捕获到了异常，但是不想处理，继续向上抛出这个异常
	}
	catch (...)//...代表其他类型
	{
		cout << "其他类型异常捕获" << endl;
	}*/
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