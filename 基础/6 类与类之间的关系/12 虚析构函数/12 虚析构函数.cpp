#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//注意：类如果什么控制访问权限都不写，默认是private
#if 0
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
	virtual ~B()
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
void test2()//触发A(),print(),~A()
{
	A* ap = new A;
	func(ap);
}
void test3()//触发A(),B(),print(),~B(),~A()
{
	B b;
	func(&b);
}
void test4()//触发A(),B(),print(),~A()，只析构了~A()。由于参数为A* ap，delete ap;只触发~A()
{//如何触发析构B？触发析构B，默认一定会触发析构A，即delete ap;发生多态
	B* bp = new B;
	func(bp);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
#endif
#if 0
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
	virtual ~B()//这里重写虚析构函数，函数名不同
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
void func(A* ap)
{
	ap->print();//此处发生多态
	delete ap;//此处也要发生多态
}

void test4()//触发A(),B(),print(),~A()，只析构了~A()。由于参数为A* ap，delete ap;只触发~A()
{//如何触发析构B？触发析构B，默认一定会触发析构A，即delete ap;发生多态
	B* bp = new B;
	func(bp);
}
int main()
{
	test4();
	return 0;
}
#endif

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
	virtual ~B()//这里重写虚析构函数，函数名不同
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
void func(A* ap)
{
	ap->print();//此处发生多态
}
void deleteFun(A* ap)
{
	delete ap;//此处也要发生多态
}
void test4()//触发A(),B(),print(),~A()，只析构了~A()。由于参数为A* ap，delete ap;只触发~A()
{//如何触发析构B？触发析构B，默认一定会触发析构A，即delete ap;发生多态
	B* bp = new B;
	func(bp);
	deleteFun(bp);
}
int main()
{
	test4();
	return 0;
}