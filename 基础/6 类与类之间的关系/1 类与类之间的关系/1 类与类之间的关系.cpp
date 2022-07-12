#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	void funcA()
	{
		cout << "funcA()" << endl;
	}
	int a;
};
//类B拥有类A的成员变量，即B has A，也称类B依赖于类A
class B
{
public:
	void funcB()
	{
		cout << "funcB()" << endl;
	}
	A a;
};
//内聚度、耦合度：高内聚、低耦合
//高内聚：每个函数的功能独立单一，互不干扰
//低耦合：类之间的关系相对独立，互不干扰，例如类C的耦合度较低

//类C的成员方法，需要类A的形参，即C uses A，也称类B依赖于类A
class C
{
public:
	void funcC(A* a)
	{
		cout << "funcC()" << endl;
	}
	void funcC2()
	{

	}
};

//类D继承与类A，即D is A，继承的耦合度是最高的
class C:public A
{
public:
	void funcD(A* a)
	{
		cout << "funcD() a = " << a << endl;
	}

};
int main()
{
	return 0;
}