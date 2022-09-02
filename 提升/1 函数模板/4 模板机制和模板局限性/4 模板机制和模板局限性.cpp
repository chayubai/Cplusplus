#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板调用" << endl;
}

/*

1、编译器并不是把函数模板处理成能够处理任何类型的函数（如自定义类型），如：两个数组之间的赋值
template<class T>
void f(T a, T b)
{
	a = b;
}

2、函数模板通过具体类型产生不同的函数 -- 通过函数模板产生的函数 称为模板函数
	int a = 10;
	int b = 20;
	myPrint(a, b)
void myPrint(int a, int b)
{
	cout << "函数模板调用" << endl;
}

	double a = 10;
	double b = 20;
	myPrint(a, b)
void myPrint(double a, double b)
{
	cout << "函数模板调用" << endl;
}

3、编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译
//第一次编译，防止模板代码有误。第二次编译，防止生成的模板函数代码有误

*/

//模板局限性
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

//实现两个变量对比的函数
template<class T>
bool myCompare(T &a, T &b)
{
	if (a == b)//==操作符函数重载，实现非内置数据类型的变量比较
	{
		return true;
	}
	return false;
}

//2、利用上面已有的函数模板，使用(第三代)具体化实现对自定义数据类型，提供特殊的函数模板
//如果具体化能够优先匹配，那么就选择具体化
//语法：template<> 返回值 函数名(具体形参1, 具体形参2...)
//实际上可以用普通函数实现
//这样做的目的是为函数模版提供一个特例接口，使其更加通用。
template<> bool myCompare(Person& a, Person& b)//template<> int myCompare(Person& a, Person& b)报错，必须在原函数模版基础上提供具体化
{
	if (a.name == b.name && a.age == b.age)
	{
		return true;
	}
	return false;
}

void test1()
{
	int a = 10;
	int b = 10;
	//内置数据类型 的变量比较
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}
void test2()
{
	/*
	//非内置数据类型 的变量比较
	Person p1("Tom", 19);
	Person p2("Tom", 19);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}*/

	//以上代码使用模板就会报错
	//解决方案：
	//1、对==号进行重载，使得能够比较两个Person类型的数据

	//2、利用具体化实现对自定义数据类型，提供特殊的模板
}
void test3()
{
	//2、利用具体化实现对自定义数据类型，提供特殊的模板
	Person p1("Tom", 19);
	Person p2("Tom", 19);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}