#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person;//声明一个类模板

//template<class T1, class T2>class Person;可以合并

//方式一
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p);//这一行是对使用的函数模板进行声明，由于函数模板声明时包含Person
//即使用Person前，需要提前声明Person类，

//方式二
template<class T1, class T2>
void printPerson3(Person<T1, T2>& p)//将声明和实现提前
{
	cout << "类外实现 -- 姓名：" << p.m_Name << "，年龄：" << p.m_Age << endl;
}

//注意：友元函数类外实现不需要作用域
template<class T1, class T2>
class Person
{
	//1、友元函数 类内实现。友元关键字可以放在类的任意位置。友元函数内类实现，可以访问类内的私有成员
	friend void printPerson1(Person<T1, T2>& p)
	{
		cout << "类内实现 -- 姓名：" << p.m_Name << "，年龄：" << p.m_Age << endl;//友元函数访问私有成员变量
	}

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
	//2、友元函数 类外实现 - 方法一：函数模板声明和实现分离
	//friend void printPerson2(Person<T1, T2>& p);//没有紧跟着模板，这个是普通函数都声明。由于没有函数实现，导致调用时，无法解析

	friend void printPerson2<>(Person<T1, T2>& p);//函数模板的声明，空参数列表，此时由于它是一个模板，需要告诉编译器有这个模板存在，
	//即：使用前需要提前声明printPerson2(Person<T1, T2>& p);模板

	//3、友元函数 类外实现 - 方法二：声明和实现一起
	friend void printPerson3<>(Person<T1, T2>& p);//函数模板的声明，空参数列表，此时由于它是一个模板，需要告诉编译器有这个模板存在，
	//即：使用前需要提前声明printPerson3(Person<T1, T2>& p);模板

	//总结：类外实现友元函数的前提：1、类内函数模板声明(参数可加可不加) 2、类外声明函数模板以及声明需要提前使用的类 3、函数实现

private:
	T1 m_Name;
	T2 m_Age;
};

//方法一的类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)//由于这个是函数模板，因此需要对函数模板进行声明，即friend void printPerson2<>(Person<T1, T2>& p);
{
	cout << "类外实现 -- 姓名：" << p.m_Name << "，年龄：" << p.m_Age << endl;
}

void test1()
{
	Person<string, int> p("Tom", 10);
	printPerson1(p);//无法解析的外部命令
}

void test2()
{
	Person<string, int> p("Tom", 10);
	printPerson2(p);
}

void test3()
{
	Person<string, int> p("Tom", 10);
	printPerson3(p);
}

int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}