#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{
public:
	//编译器会默认提供一个类的无参构造函数，和默认的类的析构函数
	//如果，自己提供了一个有参的构造函数，则不会调用无参的构造函数
	//注意：析构函数不能发生重载
#if 0
	Test()
	{
		//Do Nothing
	}
	~Test()
	{
		//Do Nothing
	}
#endif
	//自己定义的有参的构造函数
	Test()
	{
		//Do Nothing
	}
	Test(int x,int y)
	{
		//...
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	//此时如果有有参的构造函数，无参的构造函数会被覆盖，默认调用无参的构造函数会报错
	//因此，提供有参的构造函数，最好自己定义一个无参的构造函数，即构造函数的重载
	Test t;//默认调用无参的构造方法

	return 0;
}