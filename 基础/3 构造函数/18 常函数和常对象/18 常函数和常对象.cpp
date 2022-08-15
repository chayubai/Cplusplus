#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public: 

	Person(int age)
	{
		this->m_age = age;
	}
	
	//常函数：修饰成员函数中的this指针，让指针指向的值不可以修改
	void showPerson() const // const Person* const this
	{
		//m_age = 100;//报错：表达式必须是可修改的左值，即指针指向的值，this->m_age不可以修改

		//this指针的本质：Person* const this
		//this->NULL;//this是指针常量，指针的指向不可以修改，而指针指向的值可以修改
		cout << "Person age = " << this->m_age << endl;

		m_A = 100;//，如果希望m_A可修改，而不会报错
	}

	//对于showPerson()的功能，只允许读，不允许写，如何实现
	//用const修饰指针常量，即const Person* const this
	//防止通过this->成员变量 = 值，访问成员变量

	//如何在Person* const this前面加const修饰呢？
	//通过在函数名的后面加const

	void func()
	{
		m_age = 10;
		cout << "func()调用" << endl;
	}
	int m_age;

	mutable int m_A;//常函数中或者常对象中，有些特殊属性依然想修改，加入关键字mutable
};

int main()
{
	//常对象
	const Person p(10);

	//p.m_age = 10;//报错,不允许修改普通成员属性
	//const修饰的变量虽然不能直接修改，但可以间接修改，
	//mutable关键字就是利用了间接修改，从而可以修改mutable修饰的属性

	p.m_A = 10;//不会报错，可以修改mutable修饰的属性

	p.showPerson();//可以访问常函数

	//p.func();//常对象只能调用常函数，不允许调用普通成员函数
	//（如果可以调用的话，就可以间接通过普通函数里面修改普通成员属性，因此是不可以的）
}