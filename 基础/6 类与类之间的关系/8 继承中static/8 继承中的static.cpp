#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{ 
public:
	static int a;
};
int A::a = 100;//静态成员变量的初始化
class B:public A
{
public:

};
int main()
{
	//静态成员变量的用法
	A a1;
	A a2;
	cout << a1.a << endl;
	cout << a2.a << endl;

	A::a = 200;
	cout << a1.a << endl;
	cout << a2.a << endl;
	cout << "---------------" << endl;

	//父类的静态成员变量，被子类公有继承后，整个家族（所有的对象）共享
	B b1;
	B b2;
	A::a = 300;
	cout << b1.a << endl;
	cout << b2.a << endl;
	cout << a1.a << endl;
	cout << a2.a << endl;

	return 0;
}

//结论：继承中的静态成员，整个家族共享同一份数据