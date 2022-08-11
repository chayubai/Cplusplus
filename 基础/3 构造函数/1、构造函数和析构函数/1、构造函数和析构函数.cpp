#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public://为了方便调用，构造函数和析构函数必须声明在公共控制权限下

	//构造函数：用于自动初始化成员变量
	//1、没有返回类型，也不用写void，没有返回值，没有return语句
	//2、函数名与类名相同
	//3、可以有参数，可以发生重载
	//构造函数由编译器自动调用一次，无需手动调用
	Person()
	{
		cout << "调用Person()无参构造函数" << endl;
		m_age = 0;
		m_y = 0;
	}
	//作用：在对象被创建出来的时候，同时初始化对象的函数

	//析构函数：用于自动释放堆区开辟的空间
	//1、没有返回类型，也不用写void，没有返回值，没有return语句
	//2、函数名与类名相同，函数名前加~
	//3、不可以有参数，不可以发生重载
	//析构函数由编译器自动调用一次，无需手动调用

	//Person类的析构函数：

	~Person()
	{
		cout << "调用~Person()析构函数" << endl;
		m_age = 0;
		m_y = 0;
	}

	int m_age;
	int m_y;
};

void test1()
{
	Person p;//构造函数由编译器自动调用一次，无需手动调用

	//p开辟在栈上，即栈上的对象被创建的时候，会自动调用无参的构造函数
	//函数执行完后，只要有对象被释放的时候，就会调用析构函数
}

int main()
{
	test1();
	return 0;
}
