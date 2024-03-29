#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//函数重载
//一定是同一个作用域下。
#if 0
int main()
{ 
	void func()
	{
		
	}
	void func(int a)
	{

	}
	return 0;
}
#endif

//重定义：发生在两个不同的类中，一个是父类，一个是子类
//1、普通函数重定义：如果父类中是普通成员函数，被子类重写，就说是重定义
//2、虚函数重写：如果父类的虚函数，被子类重写，就是虚函数重写，这个函数会发生多态

//重定义：
#if 0
class A
{
public:
	void print()
	{
		cout << "A :" << endl;
	}

};
class B :public A
{
public:
	void print()
	{
		cout << "B :" << endl;
	}
};
#endif

//重写：
#if 0
class A
{
public:
	virtual void print()
	{
		cout << "A :"  << endl;
	}
};

class B :public A
{
public:
	virtual void print()
	{
		cout << "B :" << endl;
	}
};
#endif