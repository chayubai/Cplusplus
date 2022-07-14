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

	}
	int a;
};
class Child :public Parent
{
public:

	Child(int p_a, int c_a):Parent(p_a)
	{
		this->a = c_a;

	}
	void printC()
	{
		//如果子类和父类都有相同的public的成员变量名，则可以通过类名访问
		//如果父类为私有的，只能通过get方法访问
		cout << "Parent's a = " << Parent::a << endl;
		cout << "Child's a = " << this->a << endl;
	}
	int a;
};
int main()
{
	Child c(10, 200);
	c.printC();
	return 0;
}