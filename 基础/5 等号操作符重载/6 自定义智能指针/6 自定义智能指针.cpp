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
			delete ptr;//deleteʵ���������
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

	delete pa;//�ᴥ����������
#endif
#if 0
	//auto_ptr<int> ptr(new int);
	//����ָ�룬����Ҫdelete�����Զ��ͷſռ�
	auto_ptr<A> ptr(new A(10));
	ptr->func();
	(*ptr).func();
	//���Զ���������������
#endif
}

void test2()
{
	MyAutoPtr my_ptr(new A(10));
	//���Զ���������������
	my_ptr->func();//my_ptr.ptr->func();

	(*my_ptr).func();//*ptr.func();
}
int main()
{
	//test1();
	test2();
	return 0;
}