#define _CRT_SECURE_NO_WARNINGS 1
//1、简述函数默认参数的声明规则

//2、int func(int a,int b)和void func(int a, int b, int c)是重载函数么？为什么？

//3、以下函数重载写法是否正确？为什么？
//int func(int a, int b)和int func(int a,int b,int c = 0);

//4、简述面向对象和面向过程的区别？

//5、定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法
//定义一个圆类，其属性包括圆心和半径
//创建两个圆形对象。提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果

#include <iostream>
#include <cmath>//或者include <math.h>
using namespace std;

//点类
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	//计算两点距离
	double pointDistance(Point& another)
	{
		//同类之间无私处
		int d_x = m_x - another.m_x;
		int d_y = m_y - another.m_y;

		double dis = sqrt(d_x * d_x + d_y * d_y);
		return dis;
	}
private:
	int m_x;
	int m_y;
};

//圆类
class Circle
{
public:
	void setXY(int x, int y)
	{
		p0.setXY(x, y);
	}
	void setR(int r)
	{
		m_r = r;
	}
	//判断圆是否相交
	bool isIntersection(Circle &another)
	{
		//两半径之和
		int rr = m_r + another.m_r;
		//两圆心之间的距离
		double dis = p0.pointDistance(another.p0);

		if (dis <= rr )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int m_r;
	Point p0;
};

int main()
{
	Circle c1,c2;
	int x, y, r;
	cout << "请输入第一个圆的半径r" << endl;
	cin >> r;
	c1.setR(r);
	cout << "请输入第一个圆的x坐标" << endl;
	cin >> x;
	cout << "请输入第一个圆的y坐标" << endl;
	cin >> y;
	c1.setXY(x, y);

	cout << "请输入第二个圆的半径r" << endl;
	cin >> r;
	c2.setR(r);
	cout << "请输入第二个圆的x坐标" << endl;
	cin >> x;
	cout << "请输入第二个圆的y坐标" << endl;
	cin >> y;
	c2.setXY(x, y);

	if (c1.isIntersection(c2) == true)
	{
		cout << "相交" << endl;
	}
	else
	{
		cout << "不相交" << endl;
	}

	return 0;
}

//6、设计并测试一个名为Rect的矩形类，其属性为矩形的左下角与右下角两个点的坐标。根据坐标能计算出矩形的面积

//7、定义一个Tree类，有成员ages（树龄），成员函数grow(int years)对ages加上years。age()显示tree对象的ages值。