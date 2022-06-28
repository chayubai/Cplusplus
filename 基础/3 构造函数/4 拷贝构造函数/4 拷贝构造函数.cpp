#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{
public:

	//自己定义的有参的构造函数
	Test()
	{
		m_x = 0;
		m_y = 0;
	}
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
	//当通过同一个类的对象初始化自己，可以编译通过，说明编译器提供了一个默认的拷贝函数
	//当没有自己定义的拷贝函数，会自动调用默认的拷贝函数。
	//否则如果自己定义了拷贝函数，会调用自己的拷贝函数

	//自己提供的拷贝构造函数
	Test(const Test& another)
	{
		cout << "Test(const Test& another)... " << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}

	//编译器提供的拷贝构造函数
	//当通过同一个类的对象初始化自己，默认会提供一个拷贝构造函数，参数为引用类型
	/*Test(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}*/

#if 0
	//=赋值操作符函数
	//当通过同一个类的对象赋值自己，可以编译，说明编译器提供了一个默认的赋值操作符函数
	//当没有自己定义的赋值操作符函数，会自动调用默认的赋值操作符函数。
	//否则如果自己定义了赋值操作符函数，会调用自己的赋值操作符函数
	void operator=(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}
#endif
private:
	int m_x;
	int m_y;
};
int main()
{
	Test t1(100,200);

	//通过同一个类的对象初始化自己
	//初始化t2的时候，调用t2的构造函数
	Test t2(t1);
	t2.printT();

	Test t3 = t1;//依然是调用t3的拷贝构造函数，等价Test t2(t1);
	//调试发现会进入Test(const Test& another)

	//构造函数是对象初始化的时候调用
	Test t4;//t4已经通过调用无参的构造函数初始化了
	t4 = t1;//调用的不是t4的拷贝构造函数，而是t4的赋值操作符函数
	//调试发现会进入void operator=(const Test& another)
	return 0;
}