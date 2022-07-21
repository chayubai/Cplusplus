#define _CRT_SECURE_NO_WARNINGS 1

//设计立方体类（Cube），求出立方体的面积和体积
//求两个立方体，是否相等（全局函数和成员函数）

#include <iostream>
using namespace std;

//立方体类
class Cube
{
public:
	void setABC(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	int calculateS()
	{
		return (m_a * m_b) * 2 + (m_a * m_c) * 2 + (m_b * m_c) * 2;
	}
	int calculateV()
	{
		return m_a * m_b * m_c;
	}
	int getA()
	{
		return m_a;
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_c;
	}
	//成员函数
	bool judgeCube(Cube& another)
	{
		//if (m_a == another.getA() && m_b == another.getB() && m_c == another.getC())
		//同类之间无私处
		/*if (m_a == another.m_a && m_b == another.m_b && m_c == another.m_c)
		{
			return true;
		}
		else
		{
			return false;
		}*/
		return m_a == another.m_a && m_b == another.m_b && m_c == another.m_c;
	}
private:
	int m_a;//可读，可写
	int m_b;//可读，可写
	int m_c;//可读，可写
};

//全局函数
bool judgeCube(Cube& c1, Cube& c2)//const成员函数不能调用非const成员函数。因为非const成员函数可能会改变成员变量的值。
{//judgeCube(const Cube& c1, const Cube& c2)//这是不对的
	/*if (c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC())
	{
		return true;
	}
	return false;*/
	bool ret = c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC();
	return ret;
}

void test1()
{
	Cube c1;
	c1.setABC(10, 20, 30);
	cout << "c1的体积是" << c1.calculateV() << endl;
	cout << "c1的面积是" << c1.calculateS() << endl;
}

void test2()
{
	Cube c1;
	c1.setABC(10, 20, 30);

	Cube c2;
	c2.setABC(10, 20, 30);

	//全局函数判断是否相等
	if (judgeCube(c1, c2) == true)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

void test3()
{
	Cube c1;
	c1.setABC(10, 20, 30);

	Cube c2;
	c2.setABC(10, 20, 30);

	//局部函数判断是否相等
	cout << "--------------------" << endl;

	if (c1.judgeCube(c2) == true)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}
void test4()
{
	/*void func(const Cube & cub)//为什么不能加const，因为无法保证成员函数里是否修改了成员变量
	{
		cub.getA();//getA()可能会修改m_a的值
	}*/
	//将int getA()const时，不会报错

}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}
