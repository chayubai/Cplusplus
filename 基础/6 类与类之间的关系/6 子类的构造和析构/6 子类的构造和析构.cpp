#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Parent
{
public:
	Parent()
	{
		cout << "Parent()..." << endl;
		a = 0;
	}
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
		
	}
	~Parent()
	{
		cout << "~Parent()..." << endl;
	}
	int a;
};

class Child:public Parent
{
public:

	//如果不声明父类的构造，在调用子类的时候，默认一定会调用父类的构造方法
	//父类先构造，子类后构造
	Child(int a,int b)//:Parent(10)
	{
		cout << "Child(int a,int b)..." << endl;
		this->b = b;

	}
	void printC()
	{
		cout << "b = " << b << endl;
	}
	~Child()
	{
		cout << "~Child()..." << endl;
	}
	int b;
};
int main()
{
	Child c(10, 20);
	c.printC();
	return 0;
}