#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void printComplex()
	{
		cout << "(" << this->a << "," << this->b << "i" << ")" << endl;
	}
	

	//前置++ 
	//全局 - 可以实现前置++操作
	friend Complex& operator++(Complex& c);
#if 0
	//局部 - 可以实现前置++操作
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
#endif
	
#if 0
	//后置++
	//全局 - 不可以实现后置++操作
	friend const Complex operator++(Complex& c，int);
#endif	
	//局部 - 可以实现后置++操作
	const Complex operator++(int)
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;//返回const Complex tmp = temp;此时tmp不能再修改
	}

	//friend const Complex operator--(Complex& c，int);
private:
	int a;
	int b;
};

//全局-重载前置++运算符，先++,后赋值 - 可以实现前置++操作
Complex& operator++(Complex& c)
{
	c.a++;
	c.b++;
	return c;
}

#if 0
//全局-重载后置++运算符，通过占位参数int，区分前置++和后置++的函数名（因为函数调用参数不同）
//先赋值，后++ - 不可以实现后置++操作
const Complex operator++(Complex &c，int)
{
	Complex temp(c.a, c.b);//这里有问题
	c.a++;
	c.b++;
	return temp;//返回const Complex tmp = temp;此时tmp不能再修改
}
#endif

#if 0 全局函数 - 不能实现后置--操作
const Complex operator--(Complex& c，int)//如果返回类型为const Complex&?-返回局部变量的引用？
{
	Complex temp(c.a, c.b);//这里有问题
	c.a--;
	c.b--;
	return temp;//返回const Complex tmp = temp;此时tmp不能再修改
}
#endif

int main()
{
	Complex c1(1, 2);
	c1.printComplex();
	++c1;//operator++(Complex& c)可以连续前置++，即++++++c1;返回值是c1
	c1.printComplex();
	++++++c1;
	c1.printComplex();

	Complex c2(1, 2);
	c2.printComplex();
	//c2++;//operator++(Complex &c，int)不可以连续后置++，即返回值是c2，但是不能改变，如函数名用const
	//c2.printComplex();

	Complex c3 = c2++;
	c3.printComplex();
	c2.printComplex();

	return 0;
}
//技巧：实现操作符重载，相当于模拟实现操作符的功能
//可以通过内置数据类型的操作符运算，模拟实现自定义数据类型的操作符重载功能
void test()
{
	int a = 10;
	++++++a;//即(++(++(++a)))每次++后返回a
	//a++++++;报错，最终返回一个数值

	------a;//即(--(--(--a)))每次--后返回a
	//a------; 报错，最终返回一个数值
}

//注意：
//全局函数和成员函数都可以实现前置++/--操作
//而只有成员函数可以实现后置++/--操作