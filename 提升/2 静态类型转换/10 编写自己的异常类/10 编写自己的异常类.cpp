#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//为exception基类提供一个新的子异常类

#include <string>
//在exception基类下，创建新的子异常类
class MyOutOfRangeException:public exception
{
public:

	//MyOutOfRangeException("...")
	MyOutOfRangeException(const char* str)
	{
		//const char* 可以直接给string赋值
		this->m_errorInfo = str;//可以将const char* 隐式类型转换为string，但是不能将string隐式转换为const char*
	}
	//重载
	//MyOutOfRangeException(string("..."))
	MyOutOfRangeException(string str)
	{
		this->m_errorInfo = str;
	}

	//转到定义查看exception类有哪些需要重写的成员函数，即virtual关键字的成员函数需要重写
	virtual char const* what() const//必须有const关键字，否则不是重写(除了函数体剩余的都要一致)。const用于修饰this指针，
	{
		//return m_errorInfo;//报错：不能将string直接转为const char*.如何将string转为const char*

		return m_errorInfo.c_str();//string类内部，有一个成员方法c_str()，可以将string转为const char*
	}

	virtual ~MyOutOfRangeException(){}

	string m_errorInfo;
};

#if 0
class MyOutOfRangeException :public exception
{
public:

	MyOutOfRangeException(const char* error)
	{
		this->m_errorInfo = new char[strlen(error)+1];//可以将const char* 隐式类型转换为string，但是不能将string隐式转换为const char*
		strcpy(this->m_errorInfo, error);
	}
	~MyOutOfRangeException()
	{
		if (this->m_errorInfo)
		{
			delete[] this->m_errorInfo;
			this->m_errorInfo = NULL;
		}
	}
	//转到定义查看exception类有哪些需要重写的虚函数
	virtual char const* what() const//必须有const关键字，否则不是重写。const用于修饰this指针，
	{
		return this->m_errorInfo;
	}

	char* m_errorInfo;
};
#endif

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//throw MyOutOfRangeException("年龄必须在0~150之间");
			throw MyOutOfRangeException( string("年龄必须在0~150之间") );//string("年龄必须在0~150之间")是string类的匿名对象
		}
		else
		{
			this->m_Age = age;
		}
	}
	int m_Age;
};
void test()
{
	try
	{
		Person p(151);
	}
	//catch (MyOutOfRangeException& e)
	catch (exception& e)//父类引用指向子类对象
	{//注意：在没有实现拷贝构造的时候，这里使用exception e作为形参进行接收，会“Unknown exception”
		cout << e.what() << endl;
	}
}

int main()
{
	test();
	return 0;
}