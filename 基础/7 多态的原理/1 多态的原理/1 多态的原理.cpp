#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
 
class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void func(int a)
	{
		cout << "Paren::func(int )..." << endl;
	}
	void func(int a, int b, int c)
	{
		cout << "Paren::func(int , int, int)..." << endl;
	}
private:
	int a;
};

class Child:public Parent
{
public:
	Child(int a, int b):Parent(a)
	{
		this->b = b;
	}
	/*virtual void func(int a, int b)//这样不会发生多态，不是虚函数重写
	{
		cout << "Child::func(int ,int)..." << endl;
	}*/
	void func(int a)
	{
		cout << "Child::func(int)..." << endl;
	}
	void func(int a, int b)
	{
		cout << "Child::func(int , int)..." << endl;
	}
	void func(int a, int b,int c)
	{
		cout << "Child::func(int , int, int)..." << endl;
	}
private:
	int b;
};
void myFunc(Parent* pp)
{
	pp->func(10);
}
int main()
{
	Parent* pp = new Parent(10);
	Parent* cp = new Child(100, 200);
	myFunc(pp);
	myFunc(cp);

	delete pp;
	delete cp;

	Parent p(10);
	Parent* pa = &p;
	Child c(100, 200);
	Parent* pb = &c;
	myFunc(pa);
	myFunc(pb);

	delete pa;
	delete pb;

	return 0;
}

//每个类如果有成员函数是虚函数，那么该类就会多出一个虚函数表指针（注意：本身访问不了该指针，该指针始终指向虚函数表），不管该类是否发生继承，都会有虚函数表指针
//该指针指向的虚函数表记录的该类所有虚函数的入口地址
//当子类重写父类虚函数后，也会有一个虚函数指针，虚函数表记录了该重写后的函数的入口地址和本身该类中的虚函数的入口地址

//当发生多态时：指针如果调用函数时，就会先去对应的虚函数表检索是否有满足的函数，如果没有，就会去父类中检索其他的普通函数
//Parent* pp = &p;pp->func(10);查找父类的虚函数表是否有满足的函数，如果没有，则找父类的普通方法，否则报错
//Parent* pp = &c;pp->func(10);查找子类的虚函数表是否有满足的函数，如果没有，先查找父类的虚函数，再找父类的普通方法，否则报错
// 
//

void test()
{
	Parent* pp = new Child(10,20);
	pp->func(10);//pp调用的是Child类的虚函数表中的func(int a)
	pp->func(10, 20, 30);//由于func(int a, int b, int c)不在Child类的虚函数表中，pp去父类中找，调用父类的func(int a, int b, int c)

	delete pp;
}

void test()
{
	//假设父类的func(int a)没有虚函数，子类的func(int a)是虚函数
	Parent* pp = new Child(10, 20);//类的兼容性原则
	pp->func(10);//这里会调用谁的func？ 父类的func

	delete pp;
	//当没有发生多态，即多态发生的三个条件有其一不满足，则：
	//1、如果父类的func是不虚函数，直接调用成员函数
	//2、只有当父类的func是虚函数，才会先去查虚函数表
}