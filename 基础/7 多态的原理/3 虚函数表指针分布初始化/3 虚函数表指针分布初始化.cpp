#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Parent
{
public: 
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;

		print();//是调用父类的print？还是子类的print? - 父类的print
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}
private:
	int a;
};
class Child:public Parent
{
public:
	Child(int a,int b):Parent(a)
		//在调用父类的构造器的时候，会将vptr当作父类来处理
		//此时会临时指向父类的虚函数表
	{
		//当父类对象构造完后，vptr指针就从指向父类的虚函数表 变成 指向子类的虚函数表
		cout << "Child(int a, int b)..." << endl;
		this->b = b;
		print();//是调用父类的print？还是子类的print? - 子类的print
	}
	virtual void print()
	{
		cout << "Child::print()...b = " << b << endl;
	}
private:
	int b;
};

void test()
{
	Parent* pp = new Child(10, 20);//构造子类对象new Child(10, 20)，首先会构造父类，即调用父类的(无参/有参)构造函数
	
	//delete pp;
	
	//分析子类对象的内存分布图：
	//当构造父类对象时，（vptr指针和a变量是按父类的构造器进行解析）按父类对象的vptr指针解析

	//当构造完子类对象后，（vptr指针和a变量初始化完成后）按子类对象的vptr指针解析

	//故：子类对象的vptr指针的初始化是分布初始化的

	//注意：构造器中（构造函数中）不要写业务或者虚函数的使用，它的功能只有一个对属性进行初始化
}

int main()
{
	test();

	return 0;
}