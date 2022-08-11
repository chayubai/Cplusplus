#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
#include <string.h>
using namespace std;
class Test
{
public:

	//构造函数
	Test(int x ,int y)
	{
		m_x = x;
		m_y = y;
		name = (char*)malloc(100);
		strcpy(name, "zhangsan");
		//由于当对象出了生命周期，此时m_x、m_y、name被系统回收了
		//此时被malloc开辟的100字节的空间，存在内存泄露
		//为了解决这个问题，在析构函数中实现对malloc开辟的100字节的空间的回收
		//即，m_x、m_y、name被系统回收前，先销毁被malloc开辟的100字节的空间
	}

	//析构函数和构造函数都是没有返回值的
	//析构函数没有形参
	~Test()
	{
		cout << "~Test()..." << endl;
		if (name != NULL)
		{
			free(name);
			cout << "free succ..." << endl;
		}
	}
private:
	int m_x;
	int m_y;
	char* name;
};

void test()
{
	Test t(10,20);
	//t在test函数中，有生命周期
	//在对象快要结束生命周期之前，会自动调用析构函数
	//通过调试可以观察到，当调试到“}”时，会进入~Test()函数
}

int main()
{
	test();
	return 0;
}