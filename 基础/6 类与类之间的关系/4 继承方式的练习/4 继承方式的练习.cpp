#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class A 
{
private:
	int a;
protected:
	int b;
public:
	int c;
	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

class B:public A
{
public:
	void print()
	{
		//cout << " a = " << a;	//能否访问??
		cout << " b = " << b;	//能否访问??
		cout << " c = " << c;	//能否访问??

	}
};

class C :protected A
{
public:
	void print()
	{
		//cout << " a = " << a;	//能否访问??
		cout << " b = " << b;	//能否访问??
		cout << " c = " << c;	//能否访问??
	}
};

class D :private A
{
public:
	void print()
	{
		//cout << " a = " << a;	//能否访问??
		cout << " b = " << b;	//能否访问??
		cout << " c = " << c;	//能否访问??
	}
};

int main()
{
	A aa;
	B bb;
	C cc;
	D dd;
	aa.c = 100;
	bb.c = 100;
	//cc.c = 100;
	//dd.c = 100;
	aa.set(1, 2, 3);
	bb.set(1, 2, 3);
	//cc.set(1, 2, 3);
	//dd.set(1, 2, 3);
	//aa.print();
	bb.print();
	cc.print();
	dd.print();

	return 0;
}