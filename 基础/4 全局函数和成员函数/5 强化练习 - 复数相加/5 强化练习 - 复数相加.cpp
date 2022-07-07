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

	//第一种：通过自定义全局函数实现，声明为友元函数
	//friend Complex complexAdd(Complex& c1, Complex& c2);
	
	//第二种：通过自定义局部成员函数实现
	Complex complexAdd(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//第三种：操作符重载写在全局函数，声明为友元函数
	//friend Complex operator+(Complex& c1, Complex& c2);
	
	//第四种：操作符重载写在成员函数
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
private:
	int a;//实数
	int b;//虚数
};
//第一种：通过自定义全局函数实现
//Complex complexAdd(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

//第三种 - 操作符重载写在全局函数
//Complex operator+(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

int main()
{
	Complex c1(1, 2);
	Complex c2(2, 4);
	c1.printComplex();
	c2.printComplex();

	//Complex c3 = complexAdd(c1, c2);
	//c3.printComplex();

	//Complex c4 = c1.complexAdd(c2);
	//c4.printComplex();

	//Complex c5 = c1 + c2;//等价于operator+(c1, c2);操作符函数的设计，操作数的顺序，就是函数参数的顺序
	//c5.printComplex();

	//Complex c6 = c1 + c2;//等价于c1.operator+(c2);
	//c6.printComplex();

	//注意Complex c6 = c1 + c2;调用的操作符重载（即全局的和局部的只能出现其一）只能出现其一，否则会报错

	return 0;
}