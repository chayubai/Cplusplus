#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
 
//友元：可以是全局函数、某个类的成员函数、整个类。但是会破坏类的封装特性
//让一个全局函数，成员函数，整个类，可以称为一个类的好朋友，从而可以直接访问私有属性
//而不需要使用get、set方法

class Building
{
	//利用friend关键字让全局函数，goodGay作为本类好朋友，可以访问私有成员
	friend void goodGay(Building* building);
public:
	
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};

//好基友全局函数，可以访问Building的私有属性
void goodGay(Building *building)
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

int main()
{
	Building building;//栈上开辟或者堆上开辟Building * building = new Building;
	goodGay(&building);
	return 0;
}

#if 0
#include <cmath>

class Point;//声明Point类，由于后面有提前用到该类

class PointManager//声明PointManager类和PointDistance方法，由于后面要提前用到该类
{
public:
	double PointDistance(Point& p1, Point& p2);//声明Point类，否则这里用不了
};

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	//第二种
	//友元函数声明，类外部的全局函数可以访问类的（私有）成员
	//friend double PointDistance(Point& p1, Point& p2);//friend声明外部全局函数为类的友元函数

	//第三种，声明指定类的成员方法为友元函数。加作用域
	friend double PointManager::PointDistance(Point& p1, Point& p2);//声明PointManager类和PointDistance方法，否则这里用不了
private:
	int x;
	int y;
};

#if 0
//第一种
//全局变量，利用get方法访问私有成员
double PointDistance(Point& p1, Point& p2)//如果经常使用该函数，导致getX()、getY()频繁的压栈和出栈开销
{
	double dis;
	int dd_x = p1.getX() - p2.getX();
	int dd_y = p1.getY() - p2.getY();
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}
#endif

#if 0
//第二种
//全局变量作为友元函数
double PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}
#endif

//第三种
//PointManager类的成员函数作为友元函数 - 在类外实现，不能放在类内实现，否则需要用到x和y
double PointManager::PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}

int main()
{
	Point p1(1, 2);
	Point p2(2, 2);
	//第一种、第二种
	//cout << "PointDistance(p1,p2)：" << PointDistance(p1, p2) << endl;

	PointManager pm;
	cout << "PointDistance(p1,p2)：" << pm.PointDistance(p1, p2) << endl;
	return 0;
}
#endif

//注意：友元函数可以类内实现，相当于全局函数