#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base
{
public:

	static void func()
	{
		cout << "Base func()成员函数调用 " << endl;
	}
	//注意：静态成员函数不能访问非静态成员变量

	static void func(int a)
	{
		cout << "Base func(int a)成员函数调用 " << endl;
	}

	static int m_A;

	//静态成员变量的特点：
	//1、所有对象共享同一块内存数据
	//2、编译阶段分配内存
	//3、类内声明，类外初始化
};

int Base::m_A = 10;

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son func()成员函数调用 " << endl;
	}
	static int m_A;
};

int Son::m_A = 20;

void test1()
{
	//1、通过对象访问
	Son s;
	//当父类和子类成员属性名相同时，调用本类中的成员属性
	cout << "s.m_A = " << s.m_A << endl;
	//注意：静态成员属性，子类可以继承下来

	//如果想要访问父类中的成员属性，可以利用作用域访问父类中同名成员
	cout << "Base中的m_A = " << s.Base::m_A << endl;

	//2、通过类名访问
	cout << "Son.m_A = " << Son::m_A << endl;
	cout << "Son.m_A = " << Son::Base::m_A << endl;
	//前面的::表示通过类名的方式访问静态成员，后面的::表示Base作用域

	cout << "Base.m_A = " << Base::m_A << endl;
}

void test2()
{
	//1、通过对象访问
	Son s;
	//当父类和子类成员函数名相同时，调用本类中的成员函数

	cout << "s.func(): ";
	s.func();

	//如果想要访问父类中的成员函数，可以利用作用域访问父类中同名成员
	cout << "Base中的func(): ";
	s.Base::func();

	//2、通过类名访问
	cout << "s.func(): ";
	Son::func();
	cout << "Base中的func(): ";
	Son::Base::func();
	//前面的::表示通过类名的方式访问静态成员，后面的::表示Base作用域
}

void test3()
{
	Son s;
	//1、
	s.func();
	//s.func(10);//报错，父类所有同名函数被隐藏掉了
	s.Base::func(10);
	//2、
	//Son::func(10);//报错，父类所有同名函数被隐藏掉了
	Son::Base::func(10);

	//与普通成员函数结论一样
	//当子类重新定义了父类中的同名成员函数，子类的成员函数会，隐藏掉父类中所有重载版本的同名成员
	//可以利用作用域显式指定调用
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}