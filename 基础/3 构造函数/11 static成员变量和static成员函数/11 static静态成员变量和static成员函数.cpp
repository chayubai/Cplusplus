#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	//1、静态成员变量
	
	//static修饰的静态成员变量，编译阶段就分配了内存
	//在类内只是声明，没有分配内存，类外初始化，才分配内存
	//静态成员变量，所有对象都共享同一份数据
	static int m_A;

	//2、静态成员函数
	//所有对象都共享同一个函数
	static void func()
	{
		cout << "调用静态func()" << endl;
		m_A = 100;//静态成员函数，能访问静态成员变量
		//m_C = 200;//静态成员函数，不能访问非静态成员变量

		//由于非静态成员变量不是共享数据，当不同对象调用同一个静态函数时
		//无法区分是哪个对象调用了非静态成员变量m_C，所有静态成员函数不能访问非静态成员变量

		//而静态成员变量可以在静态函数中被访问，是因为调用时不需要做区分
	}

	//普通成员函数，可以访问普通成员变量，也可以访问静态成员变量
	void myfunc()
	{
		m_A = 100;
		m_C = 200;
	}
	int m_C;
private:
	static int m_B;

	static void func2()
	{

	}
};

//不管是public还是private权限下的静态成员变量的初始化，一定写在类的外边
int Person::m_A = 0;
int Person::m_B = 200;

void test1()
{
	//1、通过对象进行访问
	Person p1;

	cout << p1.m_A << endl;

	//C和C++的static功能相同：延长的静态变量的作用域，限制了静态函数只能在本文件中使用
	Person p2;
	p2.m_A = 200;

	cout << p1.m_A << endl;
	cout << p2.m_A << endl;

	//2、通过类名访问成员变量

	//由于静态变量不属于任何一个对象，可以不需要通过对象访问
	cout << Person::m_A << endl;

	//注意：由于静态成员变量访问有两种，单一通过构造函数初始化静态成员变量，第二种方式达不到初始化要求

	//静态成员变量，也是有访问权限的，私有权限类外无法访问
	//cout << Person::m_B << endl;//报错
}

void test2()
{
	//1、通过对象调用
	Person p1;
	p1.func();
	//2、通过类名调用
	Person::func();

	//Person::func2();//静态成员函数也是有访问权限的
}
int main()
{
	//test1();

	return 0;
}
#endif

#include <iostream>
using namespace std;
class AA
{
public:
	AA(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	//获取私有的  静态成员变量  ，需要设计static的成员方法
	//如果函数当左值，返回引用
	static int& getC()
	{
		return m_c;
	}

	//public的static静态成员变量
	static int m_d;

	int getD()
	{
		m_d++;
		return m_d;
	}
private:
	int m_a;
	int m_b;
	//private的static静态成员变量
	static int m_c;
};

int AA::m_c = 100;
int AA::m_d = 200;

int main()
{
	AA a1(10, 20);//a1.m_a和a1.m_b与a2.m_a和a2.m_b互相独立的
	AA a2(20, 40);
	//static变量是共享的
	cout << a1.getC() << endl;
	cout << a2.getC() << endl;

	//通过类名访问public的静态成员变量
	AA::m_d = 200;
	//通过对象.公有成员变量
	a1.m_d = 300;

	//通过类名访问public的成员函数
	//cout << AA::getD() << endl;
	//非静态成员函数，无法访问静态成员变量，需要加static，将其变为静态成员函数
	
	//通过对象.公有成员函数
	cout << a1.getD() << endl;

	//通过类名访问公有get成员函数，来访问private的成员变量
	cout << AA::getC() << endl;

	AA::getC() = 300;//返回引用可作左值，方便对变量的修改
	//通过对象.公有成员函数，来访问private的成员变量
	
	cout << a1.getC() << endl;

	return 0;
}