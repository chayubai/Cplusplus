#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//对于内置的数据类型，编译器知道如何进行运算
//但对于自定义的数据类型，编译器不知道如何运算
//利用运算符重载，可以让符号有新的含义。
//对于内置数据类型，不提供运算符重载操作。

//操作符重载：由于内置数据类型，是可以用直接通过运算符操作
//对于自定义的数据类型，则使用操作符进行运算操作时，会出现报错，因此需要对操作符的功能进行重载
//使得用户自定义的数据类型，也可以像内置数据类型一样，自由通过操作符进行运算操作
class Person
{
public:
	Person(int a, int b) :m_A(a), m_B(b)
	{}

	//注意：this只能用于非静态的成员函数内
	//自定义函数实现两个对象相加，如果想要作为全局函数，可以通过友元函数实现
	Person personAddPerson(Person& p)
	{
		Person temp(0, 0);
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	
	//1、利用成员函数实现：重载+号
	Person operator+(Person& p)
	{
		Person temp(0, 0);
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	int m_A;
	int m_B;
};

//2、利用全局函数实现：重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//运算符重载，可以发生函数重载
Person operator+(Person& p1, int num)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test1()
{
	Person p1(10, 20);
	Person p2(10, 10);
	
	//自定义函数实现两个对象相加
	Person p3 = p1.personAddPerson(p2);
	cout << "p3:" << p3.m_A << "," << p3.m_B << endl;
}

void test2()
{
	Person p1(10, 20);
	Person p2(10, 10);

	//由于Person+Person，编译器不会提供自定义数据类型的操作符运算
	//需要用户自己重载操作符

	//1、局部成员函数重载操作符
	Person p4 = p1.operator+(p2);//局部成员函数本质调用
	//简化成
	//Person p4 = p1 + p2;//如果使用这种方式的运算，对于全局函数和成员函数提供一个操作符重载即可，否则会出现二义性报错

	//2、全局函数重载操作符
	Person p5 = operator+(p1, p2);//全局函数本质调用
	//简化成
	//Person p5 = p1 + p2;//如果使用这种方式的运算，对于全局函数和成员函数提供一个操作符重载即可，否则会出现二义性报错

	cout << "p1:" << p1.m_A << "," << p1.m_B << endl;
	cout << "p2:" << p2.m_A << "," << p2.m_B << endl;
	cout << "p4:" << p4.m_A << "," << p4.m_B << endl;
	cout << "p5:" << p5.m_A << "," << p5.m_B << endl;
}

void test3()
{
	Person p1(10, 20);
	//运算符重载，可以发生函数重载
	Person p6 = p1 + 10;
	cout << "p6:" << p6.m_A << "," << p6.m_B << endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}



