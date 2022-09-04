#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->name << "，年龄：" << this->age << endl;
	}
	T1 name;
	T2 age;
};

//1、通过类模板创建出来的对象，作为函数参数。指定传入类型，即实参是什么，形参就用什么
void doWork1(Person<string, int> &p)
{
	p.showPerson();
}
void test1()
{
	Person<string, int> p("孙悟空", 999);//通过类模板创建出来的对象
	doWork1(p);
}

//2、通过类模板创建出来的对象，作为函数参数。参数<string, int>模板化template<class T1,class T2>
template<class T1,class T2>//此为声明类模板，告诉编译器有T1和T2模板，否则没有这一行会报错
void doWork2(Person<T1, T2>& p)//函数模板
{
	cout << "T1数据类型：" << typeid(T1).name() << endl;//string
	cout << "T2数据类型：" << typeid(T2).name() << endl;//int

	p.showPerson();
}
void test2()
{
	Person<string, int> p("猪八戒", 998);//通过类模板创建出来的对象
	doWork2(p);//通过模板函数传入参数
}

//3、通过类模板创建出来的对象，作为函数参数。整体Person<string, int>模板化template<class T>
template<class T>//此为声明类模板，告诉编译器有T模板，否则没有这一行会报错
void doWork3(T& p)//函数模板
{
	cout << "T数据类型：" << typeid(T).name() << endl;//class Person<string,int>

	p.showPerson();
}
void test3()
{
	Person<string, int> p("唐僧", 10000);//通过类模板创建出来的对象
	doWork3(p);//通过模板函数传入参数
}
//注意：第一种使用最多
//查看T的数据类型：typeid(T).name()
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}