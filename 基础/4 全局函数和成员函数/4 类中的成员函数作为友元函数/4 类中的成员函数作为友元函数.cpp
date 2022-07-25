#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>

class Building;//声明Building类

class GoodGay
{
public:
	GoodGay();
	void visit();//友元函数可以访问building的私有成员
	void visit2();//非友元函数不可以访问building的私有成员
private:
	Building* m_building;//声明Building类，否则这里用不了
};

class Building//类的定义在后面，如果前面需要使用该类，需要提前声明类
{
	//让GoodGay类中的visit()成员函数作为友元函数，声明时，需要加作用域GoodGay::
	friend void GoodGay::visit();

public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//以下都是类外函数的实现
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
void GoodGay::visit2()
{
	cout << "好基友正在访问" << this->m_building->m_SittingRoom << endl;
	//cout << "好基友正在访问" << this->m_building->m_BedRoom << endl;
}

void test()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test();
	return 0;
}