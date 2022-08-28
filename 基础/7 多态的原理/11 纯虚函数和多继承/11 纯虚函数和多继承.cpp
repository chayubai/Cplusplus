#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//接口1
class Interface1
{
public:
	virtual void func1(int a, int b) = 0;
};
//接口2
class Interface2
{
public:
	virtual void func2(int a) = 0;
	virtual void func3(int a,int b) = 0;
};

class Child :public Interface1, public Interface2
{
public:
	virtual void func1(int a, int b)
	{
		cout << "func1(int ,int )..." << endl;
	}
	virtual void func2(int a)
	{
		cout << "func2(int)..." << endl;
	}
	virtual void func3(int a, int b)
	{
		cout << "func3(int, int )..." << endl;
	}
};

int main()
{
	Interface1* if1 = new Child;
	if1->func1(10, 20);

	Interface2* if2 = new Child;
	if2->func2(10);
	if2->func3(10, 20);

	//注意：自己的抽象类指针，只能调用自己的接口
}