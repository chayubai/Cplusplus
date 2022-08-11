#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{ 
public:

	Person()
	{
		cout << "调用Person()无参构造函数" << endl;
	}

	Person(int age)
	{
		cout << "调用Person(int age)有参构造函数" << endl;
		m_age = age;
	}

	Person(const Person& p)
	{
		cout << "调用Person(const Person &p)拷贝构造函数" << endl;
		m_age = p.m_age;
	}

	~Person()
	{
		cout << "调用~Person()析构函数" << endl;
		m_age = 0;
	}

	int m_age;
};

//1、用已经创建好的对象来初始化新对象，会调用拷贝构造函数
void test1()
{
	Person p1(18);
	Person p2(p1);//Person p2 = Person(p1);
	cout << "p2的年龄：" << p2.m_age << endl;
}

//2、值传递的方式，给函数参数传值，会调用拷贝构造函数
void doWork(Person p)//Person p = p1 即Person p = Person(p1);调用拷贝构造函数
{
	//由此可知p1和p是独立的两个对象，互不影响
}
void test2()
{
	Person p1(18);
	doWork(p1);
}

//3、以值的方式，返回局部对象，会调用拷贝构造函数
Person doWork2()//这里不是返回局部对象的引用
{
	Person p;
	return p;//doWork2() = Person temp = p 调用拷贝构造函数
}
void test3()
{
	Person p1 = doWork2();//先执行doWork2()中的Person p;调用无参的构造函数，Person p1 = temp再调用拷贝构造函数
}

/*
	编译器优化后 release版本的代码：查看结果
	void doWork2(Person &p){};

	Person p;
	doWork2(p);

*/
int main()
{
	//test1();

	//test2();

	test3();

	return 0;
}