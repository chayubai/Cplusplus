#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
#include <string>
class Building;//声明Building类,防止下面提前使用报错

class GoodGay
{
public:
	GoodGay();
	void visit();
private:
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
		cout << "objB.b" << objB.b << endl;//访问类B的私有成员，对类A在类B中声明友元类
		cout << "a = " << this->a << endl;
	}

	//注意：
	// (1)友元关系不能被继承。
	// (2)声明友元类,友元的特性是单向的，在A类里面声明了友元类B，该B类可以使用A类的私有成员，而A类不能使用B类的私有成员
	// (3)友元关系不具有传递性。若类B是类A的友元类C是B的友元,类C不一定是类A的友元,同样要看类中是否有相应的声明。
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
		cout << "objA.a" << objA.a << endl;//访问类A的私有成员，对类B在类A中声明友元类
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
