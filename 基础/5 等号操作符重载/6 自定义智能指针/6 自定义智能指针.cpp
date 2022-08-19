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
	MyAutoPtr(A* ptr)//A* ptr = new A(10);new A(10)的类型是A* 而有参构造形参的类型如果是void* 不匹配
	{
		cout << " A()..." << endl;
		this->ptr = ptr;
	}
	~MyAutoPtr()//MyAutoPtr类的对象结束前，自动调用~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			delete ptr;//此时delete void* ptr不会触发~A()，而是触发~void()
			this->ptr = NULL;
		}
	}
	A* operator->()
	{
		return this->ptr;
	}
	A& operator*()
	{
		return *ptr;//返回对象类型，只是调用拷贝构造，不是原对象本身
	}
private:
	A *ptr;//这个指针的类型是A* 用来智能释放类A创建的对象，而不是void*
};

void test1()
{
#if 0
	A* pa = new A(10);//堆上开辟的空间，一定要手动释放
	pa->func();
	(*pa).func();

	delete pa;//手动释放，会触发~A()析构函数，通过析构释放堆上开辟的空间

	//注意：
	//delete是释放堆区开辟的空间
	//析构是对象结束前自动调用，用来释放对象开辟在堆区上的属性的空间
#endif

	//标准库中有一个智能指针文件，#include <memory>
	
	//int *p = new int;的智能指针ptr使用如下：
	//auto_ptr<int> ptr(new int);
	//智能指针，不需要delete (new int)，会自动释放空间
	
	//A* pa = new A(10);的智能指针ptr使用如下：
	auto_ptr<A> ptr(new A(10));
	ptr->func();
	(*ptr).func();
	//当ptr结束，会自动触发了~A()析构函数，因此不需要delete (new A(10))。类似与Java中的new

	//注意：这个ptr是一个变量，不是指针，但具有指针的性质
	//即通过重载->或者*操作符，可以实现指针的性质
}

void test2()
{
	//实现一个固定类型的智能指针类

	MyAutoPtr my_ptr(new A(10));//调用A类的有参构造，在栈上开辟my_ptr局部变量
	//用类创建对象，自动调用对象的析构~MyAutoPtr()和构造函数
	//通过my_ptr中的ptr托管new A(10)的指针，会自动触发了~MyAutoPtr()析构函数，实现智能释放new A(10)对象的空间
	my_ptr->func();//my_ptr->返回ptr指针，通过ptr->func();

	(*my_ptr).func();//*my_ptr返回*ptr 即new A(10)对象本身，通过(*ptr).func();
	//返回对象类型，只是调用拷贝构造，不是原对象本身，而是临时对象

	//注意：
	//如果A类有开辟在堆区的属性，通过智能指针创建的对象new A(10)后，
	//当智能指针结束前，自动调用智能指针的析构函数，就会触发调用~A()以释放堆该对象的堆区创建的属性的空间
}
int main()
{
	//test1();
	test2();
	return 0;
}