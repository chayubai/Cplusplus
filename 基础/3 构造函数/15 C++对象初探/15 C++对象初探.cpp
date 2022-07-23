#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	int m_a;//只有非静态成员变量属于类对象

	void func1(){}//成员函数，并不属于类的对象

	static int m_b;//静态成员变量，也不属于类对象

	static void func2() {}//静态成员函数，也不属于类对象

	double m_c;
};

int Person::m_b = 0;

//只有非静态成员变量属于类对象
void test1()
{
	Person p;
	//空类的大小是1字节，
	//原因：每个对象都应该在内存上有独一无二的地址，因此给对象分配一个字节的空间

	cout << "sizeof = " << sizeof(p) << endl;

	//成员变量和成员函数是分开存储的

	//类的大小，也和struct大小计算相同，编译器默认对齐数为8
}
int main()
{
	test1();
	return 0;
}