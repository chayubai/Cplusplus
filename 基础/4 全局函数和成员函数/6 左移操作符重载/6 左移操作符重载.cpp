#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;

//实现自定义数据类型的输出和输入
class Person
{
public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//1、利用成员函数实现：重载<<号
	void operator<<(Person& p)
	{

	}
	//当对象调用左移操作符时，p.operator<<(cout),即p<<cout
	//因此一般左移操作符，利用成员函数实现<<重载

	//假设，int m_A;和int m_B; 是私有成员
	//当利用全局函数实现<<操作符重载时，又希望访问类的私有成员，可以友元函数
	//friend ostream& operator<<(ostream& cout, Person& p);//可以放在类中的任意位置
	int m_A;
	int m_B;
};

//2、利用全局函数实现：重载<<号
//void operator<<(ostream &cout,Person &p)
//{
//	cout << "m_A = " << p.m_A << ",m_B = " << p.m_B;
//}
//void test1()
//{
//	Person p1(10, 20);
//
//	//由于cout << int数据类型，编译器提供了内置数据类型的操作符运算
//	cout << p1.m_A << endl;
//
//	//由于cout << Person数据类型，编译器不会提供自定义数据类型的操作符运算
//	//需要用户自己重载操作符
//	cout << p1;//本质：operator<<(cout,p1)
//}

//返回类型不是重载的条件
ostream& operator<<(ostream& out, Person& p)//operator<<(cout,p1)
{
	cout << "m_A = " << p.m_A << ",m_B = " << p.m_B;
	return cout;
	//out是cout的别名，函数中原名和别名可以混用
}
void test2()
{
	Person p1(10, 20);
	//如果返回值void，则void << endl;不能实现连续<<操作
	cout << p1 << "hello" << endl;//链式编程，返回类型为引用，且返回值为cout
}

int main()
{
	//test1();
	test2();
	return 0;
}
//不要滥用操作符重载，除非有需求
//不能对内置数据类型进行重载
//对于自定义数据类型，不可以直接用cout << 输出
//需要重载左移操作符
//如果利用成员函数重载，无法实现让cout在左侧，因此不用成员函数重载
//重载<<操作符，需要知道cout的数据类型ostream&