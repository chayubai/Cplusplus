#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const double PI = 3.14;
//1、面向过程:
//圆的周长
double getCircleGirth(double r)
{
	return 2 * PI * r;
}
//圆的面积
double getCircleArea(double r)
{
	return PI * r * r;
}
void test1()
{
	double r = 10;
	double g = 0;
	double a = 0;
	g = getCircleGirth(r);
	a = getCircleArea(r);
	cout << "圆的半径是：" << r << endl;
	cout << "圆的周长是：" << g << endl << "圆的面积是：" << a << endl;
}
//2、面向对象：
class Circle
{
public:
	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	//圆的周长
	double getGirth()
	{
		return 2 * PI * m_r;
	}
	//圆的面积
	double getArea()
	{
		return PI * m_r * m_r;
	}
private:
	double m_r;
};

void test2()
{
	Circle c;
	c.setR(10);
	cout << "圆的半径是：" << c.getR() << endl;
	cout << "圆的周长是：" << c.getGirth() << endl << "圆的面积是：" << c.getArea() << endl;
}

//3、成员变量最好不要用表达式初始化
class Circle2
{
public:
	void setR(double r)
	{
		m_r = r;//此时如果当改变了m_r的值，
		//由于m_girth、m_area的结果在赋值之前就已经计算出来的，将不会改变m_girth、m_area的值
	}
	double getR()
	{
		return m_r;
	}
	//圆的周长
	double getGirth()
	{
		return m_girth;
	}
	//圆的面积
	double getArea()
	{
		return m_area;
	}
private:
	double m_r;//m_r一开始为随机值
	double m_girth = m_r * 3.14 * 2;//已经通过随机值得到m_girth的结果也是随机值
	double m_area = m_r * m_r * 3.14;//已经通过随机值得到m_area的结果也是随机值
};
void test3()
{
	Circle c2;
	c2.setR(10);
	cout << "圆的半径是：" << c2.getR() << endl;//10
	cout << "圆的周长是：" << c2.getGirth() << endl << "圆的面积是：" << c2.getArea() << endl;//随机值 随机值
}

//4、上面第3种方法的修改
#if 0
class Circle2
{
public:
	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	//圆的周长
	double getGirth()
	{
		m_girth = m_r * 3.14 * 2;
		return m_girth;
	}
	//圆的面积
	double getArea()
	{
		m_area = m_r * m_r * 3.14;
		return m_area;
	}
private:
	double m_r;
	double m_girth;
	double m_area;
};
#endif

int main()
{
	test1();

	cout << "--------------------------------" << endl;

	test2();

	cout << "--------------------------------" << endl;
	
	test3();

	return 0;
}