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
//	int getA()
//	{
//		return this->a;
//	}
//private:
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
		//如果父类为私有的，只能通过get方法访问
		//cout << "Parent's a = " << this->getA() << endl;
		
		//如果子类和父类都有相同的public的成员变量名，则可以通过类名访问
		cout << "Parent's a = " << Parent::a << endl;
		cout << "Child's a = " << this->a << endl;//优先访问本类同名属性，父类同名成员被隐藏了

		//注意：
		//当父类a为私有的，加作用域也无法访问，因为子类公有继承父类的私有属性后，
		//该属性不可见，不可访问
	}
	int a;
};
int main()
{
	Child c(10, 200);
	c.printC();
	return 0;
}
//注意：
//如果子类和父类拥有同名的成员属性/函数，子类会把父类所有的同名属性/同名版本的函数隐藏掉
//想调用父类隐藏掉的函数，必须加作用域

//静态同名成员，与非静态同名成员结论一致。