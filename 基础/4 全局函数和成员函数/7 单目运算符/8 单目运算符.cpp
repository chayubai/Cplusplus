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
#if 0
	//前置++
	//全局
	//friend Complex& operator++(Complex& c);

	//局部
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
#endif

	//后置++
	//全局
	//friend const Complex operator++(Complex& c，int);
	
	//局部
	const Complex operator++(int)
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;
	}
private:
	int a;
	int b;
};

#if 0
//全局-重载前置++运算符
Complex& operator++(Complex& c)
{
	c.a++;
	c.b++;
	return c;
}
#endif

#if 0
//全局-重载后置++运算符，通过占位参数int，区分前置++和后置++的函数名
const Complex operator++(Complex &c，int)
{
	Complex temp(c.a, c.b);
	c.a++;
	c.b++;
	return temp;
}
#endif

int main()
{
	Complex c1(1, 2);
	c1.printComplex();
	++c1;//operator++(Complex& c)可以连续前置++，即++++++c1;返回值是c1
	c1.printComplex();

	//Complex c2(1, 2);
	//c2.printComplex();
	//c2++;//operator++(Complex &c，int)不可以连续后置++，即返回值是c2，但是不能改变，如函数名用const
	//c2.printComplex();

	return 0;
}