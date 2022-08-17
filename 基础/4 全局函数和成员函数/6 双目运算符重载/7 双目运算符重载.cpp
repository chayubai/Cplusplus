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
	//全局
	//friend Complex& operator+=(Complex& c1, Complex& c2);

	//局部
	Complex& operator+=(Complex& another)//返回值是Complex&，下次连加等时，改变的是对象本身
	{									 //返回值是Complex，下次连加等时，改变的是匿名对象
		this->a += another.a;
		this->b += another.b;
		return *this;//返回*this
	}
private:
	int a;//实数
	int b;//虚数
};
//全局
//Complex& operator+=(Complex& c1, Complex& c2)
//{
//	c1.a += c2.a;
//	c1.b += c2.b;
//	return c1;
//}

int main()
{
	Complex c1(1, 2);
	Complex c2(2, 4);
	c1.printComplex();
	c2.printComplex();

	(c1 += c2) += c2;//c1.operator(c2) = c1  .operator(c2)
	c1.printComplex();

	return 0;
}

//注意：
//全局函数和成员函数 操作符重载都能实现连+=/-=操作，返回引用
//而只有成员函数 操作符重载才能实现连+/-操作，返回类名