#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//注意：类如果什么控制访问权限都不写，默认是private
class A
{
public: 
	A()
	{
		cout << "A()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "A string");
	}
	virtual void print()
	{
		cout << "A :" << this->p << endl;
	}
	virtual ~A()
	{
		cout << "~A()..." << endl;
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};

class B :public A
{
public:
	B()//此刻先会触发A的无参构造，再调用B的无参构造
	{
		cout << "B()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "B string");
	}
	virtual void print()
	{
		cout << "B :" << this->p << endl;
	}
	virtual ~B()//重写父类函数，函数名不同
	{
		cout << "~B()..." << endl;
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};

#if 0
//(1)
void func(A* ap)
{
	ap->print();//此处发生多态
}
#endif

//(2)方法一：析构函数，发生多态
void func(A* ap)
{
	ap->print();//此处发生多态
	delete ap;
}

void test1()//触发A(),print(),~A()
{
	A a;
	func(&a);
}
void test2()
{
	A* ap = new A;
	func(ap);

	//如果是(1)只会触发A(),print()
	//如果是(2)会触发A(),print(),~A()
}
void test3()//触发A(),B(),print(),~B(),~A()
{
	B b;
	func(&b);
}
void test4()
{
	B* bp = new B;
	func(bp);

	//如果是(1)只会触发A(),B(),print()
	//如果是(2)只会触发A(),B(),print(),~A()，只析构了~A()。
	//因为参数为A* ap，delete ap;只触发该A类对象的析构。即~A()

	//如何触发析构B？由于触发析构B，默认一定会触发析构A，即让delete ap;发生多态
	//让父类的虚构函数变为虚析构函数，再重写父类的析构函数
	//注意：析构函数发生多态，重写父类的析构函数，函数名称不同
}

#if 0//方法二：析构函数，发生多态
void func(A* ap)
{
	ap->print();//此处发生多态
}
void deleteFunc(A* ap)
{
	delete ap;//此处发生多态
}
void test5()
{
	B* bp = new B;
	func(bp);
	deleteFun(bp);
}
#endif

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}