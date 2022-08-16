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
	
	//第二种：通过自定义局部成员函数实现，可以实现连+=操作
	Complex complexAdd(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//第三种：操作符重载写在全局函数，声明为友元函数
	//friend Complex operator+(Complex& c1, Complex& c2);
	
	//第四种：操作符重载写在成员函数 可以实现连加操作
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//friend Complex operator-(Complex& c1, Complex& c2);

	//局部成员函数可以实现连减操作
	Complex operator-(Complex& another)
	{
		Complex c(this->a - another.a, this->b - another.b);
		return c;//Complex temp = c;即temp是匿名对象
	}
private:
	int a;//实数
	int b;//虚数
};
//第一种：通过自定义全局函数实现，可以实现连+=操作
//Complex complexAdd(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

//第三种 - 操作符重载写在全局函数，不可以实现连加操作
//Complex operator+(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//  //重载函数体里的操作符与自定义数据类型的使用的操作符不同
//	//重载函数体里的操作符可以实现内置数据类型的运算
//	return temp;
//}

/*
	//全局函数不能实现连减操作
Complex operator-(Complex& c1, Complex& c2)
{
	Complex c(c1.a - c2.a, c1.b - c2.b);
	return c;//Complex temp = c;即temp是匿名对象
}*/

/*
Complex& operator-(Complex& c1, Complex& c2)
{
	Complex c(c1.a - c2.a, c1.b - c2.b);
	return c;//Complex& temp = c;
}*/

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

	//编译器不会做自定义数据类型的运算操作，需要重载+操作符
	//Complex c5 = c1 + c2;//等价于operator+(c1, c2);操作符函数的设计，操作数的顺序，就是函数参数的顺序
	//c5.printComplex();

	Complex c6 = c1 + c2;//等价于c1.operator+(c2);
	//c6.printComplex();
	Complex c7 = c1 + c2 + c1;
	//c7.printComplex();
	
	//注意Complex c6 = c1 + c2;调用的操作符重载（即全局的和局部的只能出现其一）只能出现其一，否则会报错


	Complex c8 = c1 - c2;
	c8.printComplex();
	Complex c9 = (c1 - c2) - c1;
	//如果返回的是类名，即c1 - c2 = temp，调用拷贝构造
	//当执行temp - c1时，返回temp'

	//如果返回的是引用，即c1 - c2 = c = temp，由于temp是c的别名，c是局部变量
	//执行完c1 - c2后，c被回收，变成随机值
	//当执行c - c1时，
	c9.printComplex();

	return 0;
}

//注意：
//.成员选择符  .*成员对象选择符  ::域解析操作符 ?:条件操作符 不能重载
//如：A a; a.*b 相当于 *(a.b)
//操作符重载不能改变运算符的参数个数
//运算符重载不能有默认参数
//如：operator+(Complex& c1, int = 10){}//c+违背了“操作符重载不能改变运算符的参数个数”