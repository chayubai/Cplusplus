#define _CRT_SECURE_NO_WARNINGS 1
 
//设计一个圆形类（AdvCircle）,和一个点类（Point），计算点在圆内部还是圆外，即求点和圆的关系
#include <iostream>
using namespace std;

//方法一：
#if 0
//点类
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;//点的横坐标
	int m_y;//点的纵坐标
};

//圆类
class Circle
{
public:
	void setXY(int x, int y)
	{
		x0 = x;
		y0 = y;
	}
	void setR(int r)
	{
		m_r = r;
	}
	bool is_in_Cricle(Point& p)
	{
		int dd;
		//两点的距离的平方
		dd = (p.getX() - x0) * (p.getX() - x0) + (p.getY() - y0) * (p.getY() - y0);
		if (dd > m_r * m_r)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	int x0;//圆心的横坐标
	int y0;//圆心的纵坐标
	int m_r;//圆的半径
};

int main()
{
	Circle c;
	c.setXY(2, 2);
	c.setR(4);

	Point p;
	p.setXY(8,8);

	if (c.is_in_Cricle(p) == true)
	{
		cout << "圆内" << endl;
	}
	else
	{
		cout << "圆外" << endl;
	}
	return 0;
}
#endif

//方法二：
//点类
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

//圆类
class Circle
{
public:
	void setR(int r)
	{
		m_r = r;
	}
	int getR()
	{
		return m_r;
	}
	void setCenter(Point c)
	{
		m_center = c;//自定义类之间是可以直接赋值的
	}
	Point getCenter()
	{
		return m_center;
	}
	//局部函数
	void is_in_Cricle(Point p)
	{
		int distance;
		//两点的距离的平方
		distance = (m_center.getX() - p.getX()) * (m_center.getX() - p.getX()) +
			(m_center.getY() - p.getY()) * (m_center.getY() - p.getY());
		int rDistance = m_r * m_r;
		if (distance > rDistance)
		{
			cout << "点在圆外" << endl;
		}
		else if (distance < rDistance)
		{
			cout << "点在圆内" << endl;
		}
		else
		{
			cout << "点在圆上" << endl;
		}
	}
private:
	int m_r;//半径
	Point m_center;//圆心
};
//全局函数
void is_in_Cricle(Circle c, Point p)
{
	int distance;
	//两点的距离的平方
	distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else if(distance < rDistance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆上" << endl;
	}
}

int main()
{
	Point p;//点
	p.setXY(10, 10);

	Point pCenter;//圆心
	pCenter.setXY(0, 10);

	Circle c;//圆
	c.setR(10);
	c.setCenter(pCenter);
	is_in_Cricle(c, p);

	c.is_in_Cricle(p);
	return 0;
}