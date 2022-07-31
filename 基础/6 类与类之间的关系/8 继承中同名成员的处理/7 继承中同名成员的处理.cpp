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
//如果子类和父类拥有同名的函数或属性，子类不会覆盖父类的成员
//通过开发者命令工具，可以查看对象模型

void test3()
{
	Son s3;
	//s3.func(10);//报错
	//当子类重新定义了父类中的同名成员函数，子类的成员函数会，隐藏掉父类中所有重载版本的同名成员
	//包括无参函数，可以利用作用域显式指定调用父类隐藏掉的同名函数

	s3.Base::func(10);
}
//如果子类和父类拥有同名的成员函数，子类会把父类所有的同名版本的函数隐藏掉
//想调用父类隐藏掉的函数，必须加作用域
//如：当父类和子类成员函数名相同时，调用本类中的成员函数
//cout << s2.func();
//s2.func();调用本类中的成员函数因为隐藏掉了父类中所有同名函数
int main()
{
	//stest1();
	//test2();
	test3();
	return 0;
}