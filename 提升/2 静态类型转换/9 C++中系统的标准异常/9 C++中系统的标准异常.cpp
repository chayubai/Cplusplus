#define _CRT_SECURE_NO_WARNINGS 1

//标准异常类的使用：
#include <iostream>
using namespace std;

#include <stdexcept>//standard exception
class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("年龄必须在0~150之间");//out_of_range()匿名对象，调用out_of_range类的有参构造
		}
		else
		{
			this->m_Age = age;
		}
	}
	int m_Age;
};
void test()
{
	try
	{
		Person p(151);
	}
	//catch (out_of_range& e)//普通捕获
	catch (exception& e)//多态捕获exception类是系统中所有异常的基类。 exception& e = out_of_range();父类引用指向子类对象
	{
		cout << e.what() << endl;
		//what()是out_of_range异常类中的一个成员函数，用于打印异常信息，返回值类型为const char*
		//是继承了基类exception的方法
		//因此：异常捕获，使用基类作为形参类型，可以接收所以子类对象的what方法

	}
}

int main()
{
	test();
	return 0;
}