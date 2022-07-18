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
		cout << "Paren::func(int )" << endl;
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
	void func(int a,int b)
	{
		cout << "Child::func(int ,int)" << endl;
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
	return 0;
}