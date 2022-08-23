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
//更高的内聚：每个函数的功能独立单一，互不干扰，即一个函数内实现的功能越单一越好
//更低的耦合：类之间的关系相对独立，互不干扰，即两个类之间关联性越低越好

//类C的成员方法，需要类A的形参，即C uses A,也称类C依赖于类A
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

//比如：将所有的功能都放在main函数中实现，就属于低内聚

//B与A的关系和C与A的关系，B与A的关系更紧密
//因为构建B,一定要构建A，而构建C，只有调用C的方法void funcC(A* a)时，才需要构建A
//因此，类C与类A的耦合度比类B与类A的耦合度低

//类D继承与类A，即D is A，继承的耦合度是最高的
class D:public A
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