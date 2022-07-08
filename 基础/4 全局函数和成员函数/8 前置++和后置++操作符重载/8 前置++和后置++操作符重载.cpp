#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class MyInter
{
	friend ostream& operator<<(ostream& cout, MyInter& myInt);

public:
	MyInter()
	{
		this->m_num = 0;
	}

	//成员函数实现:前置++重载
	//1、返回类型为void
	/*void operator++()
	{
		this->m_num++;
	}*/

	//2、返回类型为MyInter&
	MyInter& operator++()
	{
		this->m_num++;
		return *this;//返回本身
	}

	//3、返回类型为MyInter
	/*MyInter operator++()
	{
		this->m_num++;
		return *this;
	}*/

	//成员函数实现:后置++重载
	//4、返回类型为MyInter，
	//如果返回类型是MyInter&，则返回局部变量的引用会导致非法访问内存
	//且内置类型(b++)++是不允许的
	MyInter operator++(int)//通过占位参数int，区分前置++和后置++的函数名
	{
		//先记录初始值，用于返回
		MyInter temp = *this;
		//再++
		this->m_num++;
		return temp;//返回为之前记录的值,调用拷贝构造函数
	}

private:
	int m_num;
};

ostream& operator<<(ostream& cout, MyInter& myInt)
{
	cout << myInt.m_num;
	return cout;
}

void test1()
{
	MyInter myInt;
	++myInt;
	cout << myInt << endl;
}

void test2()
{
	MyInter myInt;

	//cout << ++myInt << endl;//由于operator++()返回void，因此void再输出就会报错

	/*int a = 0;
	cout << ++(++a) << endl;
	cout << a << endl;*/

	//由内置类型，可知++a操作返回的是a

	//因此，自定义的数据类型，想要实现连续++操作（链式编程），返回自定义类型引用

	cout << ++(++myInt) << endl;
	cout << myInt << endl;
}

void test3()
{
	MyInter myInt;
	//如果返回自定义类型，则结果？

	cout << ++(++myInt) << endl;// 2
	cout << myInt << endl;// 1

	//因为myInt第一次++后，不会再++，但是++(++myInt)最终的结果会返回最后一个临时变量temp的值

	//正常来说：重载前置++操作符需要返回引用
	//但是为什么返回对象的类型，会报错？
}

void test4()
{
	MyInter myInt;
	myInt++;
	cout << myInt++ << endl;
	cout << myInt << endl;

	//正常来说：重载后置++操作符需要返回类的对象。但是为什么会报错？
	//而返回对象的类型，虽然不能myInt++++连续++，但是不会报错，为什么？
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

//注意：前置++/--，比后置++/--，效率高，因为前置++/--返回引用，没有创建对象
//后置++/--，返回对象的类型，会调用拷贝构造函数，创建临时对象