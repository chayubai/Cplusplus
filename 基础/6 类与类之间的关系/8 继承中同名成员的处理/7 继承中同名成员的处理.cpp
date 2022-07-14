#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base
{
public:

	Base()
	{
		this->m_A = 10;

	}

	void func()
	{
		cout << "Base 成员函数调用 " <<endl;
	}

	void func(int a)
	{
		cout << "Base func(int a)成员函数调用 " << endl;
	}

	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		this->m_A = 20;
	}

	void func()
	{
		cout << "Son 成员函数调用 " << endl;
	}
	int m_A;
};

void test1()
{
	Son s1;
	//当父类和子类成员属性名相同时，调用本类中的成员属性
	cout << "s1.m_A = " << s1.m_A << endl;

	//如果想要访问父类中的成员属性，可以利用作用域访问父类中同名成员
	cout << "Base中的m_A = " << s1.Base::m_A << endl;
}

void test2()
{
	Son s2;
	//当父类和子类成员函数名相同时，调用本类中的成员函数
	cout << "s2.func(): "; 
	s2.func();

	//如果想要访问父类中的成员函数，可以利用作用域访问父类中同名成员
	cout << "Base中的func(): ";
	s2.Base::func();
}

void test3()
{
	Son s3;
	//s3.func(10);//报错
	//当子类重新定义了父类中的同名成员函数，子类的成员函数会，隐藏掉父类中所有重载版本的同名成员
	//可以利用作用域显式指定调用

	s3.Base::func(10);
}

int main()
{
	//stest1();
	//test2();
	test3();
	return 0;
}