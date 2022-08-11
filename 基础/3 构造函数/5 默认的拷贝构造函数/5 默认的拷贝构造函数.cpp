#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;
class A
{
public:
	//显式的无参构造函数
	A()
	{
		m_a = 0;
		m_b = 0;
	}
	//显式的有参构造函数
	A(int x, int y)
	{
		m_a = x;
		m_a = y;
	}

#if 0
	//显式的拷贝构造函数
	A(const A& another)
	{
		cout << "Test(const Test& another)... " << endl;
		m_a = another.m_a;
		m_b = another.m_b;
	}
#endif

private:
	int m_a;
	int m_b;
};
//类中，会有默认的无参构造函数：
//1、当没有任何显式的构造函数（显式的无参构造、显式的有参构造、显式的拷贝构造）的时候，默认无参构造函数就会出现。
//类中，会有默认的拷贝构造函数：
//2、当没有显式的拷贝构造函数，默认的拷贝构造函数就会出现。
//类中，会有默认的析构函数：
//3、当没有显式的析构函数，默认的析构函数就会出现。
int main()
{
	A a1;

	//通过同一个类的对象初始化自己
	A a2(a1);

	return 0;
}