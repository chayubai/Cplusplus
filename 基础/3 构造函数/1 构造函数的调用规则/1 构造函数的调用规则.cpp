#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1、编译器会给一个类至少添加3个函数：默认构造函数（空实现）、析构函数（空实现）、拷贝构造函数（简单值拷贝操作）
//2、如果我们自己提供了有参构造函数，编译器就不会提供默认构造函数，但依然会提供拷贝构造函数
//3、如果我们自己提供了拷贝构造函数，编译器就不会提供其他的构造函数
//即：
//自己定义了有参构造函数，编译器不会提供无参构造函数，但会提供默认拷贝构造函数，进行简单的值拷贝
//自己定义了拷贝构造函数，编译器不会提供无参构造函数，也不会提供有参构造函数
class Person
{
public:
	/*Person()//最好再提供无参构造函数，否则创建对象忘记初始化就会出错
	{
		cout << "默认构造函数调用" << endl;
	}*/
	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数调用" << endl;
	}
	/*Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数调用" << endl;
	}*/
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
	int m_Age;
};

void test1()
{
	Person p1(10);
	p1.m_Age = 18;
	Person p2(p1);
	//当注释掉拷贝构造函数，编译器会提供默认的拷贝构造函数
}

void test2()
{
	//Person p1;//报错

	//当注释掉默认构造函数，编译器不会提供默认的构造函数，调用无参构造函数就会报错
	//因此提供了有参构造函数，最好再提供无参构造函数
}
int main()
{
	test1();
	return 0;
}