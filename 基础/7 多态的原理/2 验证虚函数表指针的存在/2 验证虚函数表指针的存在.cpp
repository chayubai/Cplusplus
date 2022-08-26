#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{ 
public:
	virtual void func()
	{
		cout << "Person::func()..." << endl;
	}
	virtual void func(int a)
	{
		cout << "Person::func()..." << endl;
	}
private:
	int a;
};

class Person2
{
public:
	void func()
	{
		cout << "Person2::func()..." << endl;
	}
private:
	int a;
};

int main()
{
	Person p1;
	Person2 p2;

	cout << "size of Person ..." << sizeof(Person) << endl;//多出来的4个字节就是虚函数表指针的空间大小
	cout << "size of Person2 ..." << sizeof(Person2) << endl;

	//1、两个类都未加virtual关键字时，都是4字节

	//2、当给其中一个类加上virtual关键字时，加关键字的类，大小为8字节。未加关键字的类，大小为4字节

	//3、当给加关键字的类，进行函数重载，大小仍为8字节

	//p1.vptr;注意：是无法访问虚函数表指针的
	return 0;
}