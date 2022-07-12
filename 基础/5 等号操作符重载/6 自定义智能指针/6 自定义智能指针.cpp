#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
	A(int a)
	{
		cout << " A()..." << endl;
		this->a = a;
	}
	~A()
	{
		cout << " ~A()..." << endl;
	}
	void func()
	{
		cout << "a = " << this->a << endl;
	}
private:
	int a;
};

class MyAutoPtr
{
public:
	MyAutoPtr(A* ptr)
	{
		cout << " A()..." << endl;
		this->ptr = ptr;//ptr = new A(10);
	}
	~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			delete ptr;//delete实现深拷贝动作
			this->ptr = NULL;
		}
	}
	A* operator->()
	{
		return this->ptr;
	}
	A& operator*()
	{
		return *ptr;
	}
private:
	A *ptr;
};
void test1()
{
#if 0
	A* pa = new A(10);
	pa->func();
	(*pa).func();

	delete pa;//会触发析构函数
#endif
#if 0
	//auto_ptr<int> ptr(new int);
	//智能指针，不需要delete，会自动释放空间
	auto_ptr<A> ptr(new A(10));
	ptr->func();
	(*ptr).func();
	//会自动触发了析构函数
#endif
}

void test2()
{
	MyAutoPtr my_ptr(new A(10));
	//会自动触发了析构函数
	my_ptr->func();//my_ptr.ptr->func();

	(*my_ptr).func();//*ptr.func();
}
int main()
{
	//test1();
	test2();
	return 0;
}