#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
class Building;//声明Building类

class GoodGay
{
public:
	GoodGay();
	void visit();
	Building* m_building;//声明Building类，否则这里用不了
};

class Building
{
	//让goodGay类作为Building的好朋友，可以访问私有成员
	friend class GoodGay;
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	this->m_building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友正在访问" << this->m_building->m_SittingRoom << endl;
	cout << "好基友正在访问" << this->m_building->m_BedRoom << endl;
}
void test()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test();
	return 0;
}

#if 0

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	void printA()
	{
		B objB(100);
		cout << "objB.b" << objB.b << endl;
		cout << "a = " << this->a << endl;
	}
	//声明友元类,友元的特性是单向的，在A类里面声明了友元类B，该B类可以使用A类，而A类不能使用B类
	friend class B;
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		this->b= b;
	}
	void printB()
	{
		A objA(100);
		cout << "objA.a" << objA.a << endl;
		cout << "b = " << this->b << endl;
	}
	friend class A;
private:
	int b;
};
int main()
{
	B b(200);
	b.printB();
	return 0;
}
#endif