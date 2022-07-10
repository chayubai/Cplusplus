#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		cout << "调用有参构造函数" << endl;
		this->m_age = age;
	}
	void showAge()
	{
		cout << "年龄为：" << m_age << endl;
	}
	~Person()
	{
		cout << "调用析构函数" << endl;
	}
	int m_age;
};

class SmartPoint
{
public:
	SmartPoint(Person*person)
	{
		this->m_person = person;
	}

	//成员函数实现：重载->运算符
	Person* operator->()
	{
		return this->m_person;
	}

	//成员函数实现：重载*运算符
	Person& operator*()
	{
		return *this->m_person;//返回本身，因此返回值使用引用类型
	}
	//设计操作符重载时，用内置数据类型的操作，得出返回类型和返回值

	~SmartPoint()
	{
		if (this->m_person != NULL)
		{
			delete this->m_person;
			this->m_person = NULL;
		}
	}
private:
	Person* m_person;//用来管理外面的new出来的指针
};

void test1()
{
	Person* p = new Person(18);
	p->showAge();//p->，返回指针
	(*p).showAge();//*p，返回对象
	delete p;//如果不delete，不会触发析构函数调用

	//当代码太多，会容易忘记delete
	//利用自定义一个智能指针类，通过它的析构函数，管理new出来的person的释放操作
}

void test2()
{
	//当代码太多，会容易忘记delete
	//利用自定义一个 " 智能 指针 "类，通过它的析构函数，管理new出来的person的释放操作
	//而sp是栈上开辟的空间，当sp执行结束，会自动调用它的析构函数，从而自动释放new出来的空间
	SmartPoint sp(new Person(18));

	//由于sp不是指针，不允许这么操作，因此可以通过重载->和*操作符实现
	sp->showAge();//本质：sp->->showAge()，编译器简化为sp->showAge()
	(*sp).showAge();
	//从而实现了sp既智能，又是指针，堆上创建Person类对象时，无需担心没有释放空间的问题
}
int main()
{
	//test1();
	test2();
	return 0;
}