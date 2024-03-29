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
	friend ostream& operator<<(ostream& os, Complex& c);
	//局部 - 左移操作符不建议写在放在成员方法中
	ostream& operator<<(ostream& os)
	{
		os << "(" << this->a << "," << this->b << "i" << ")";
		return os;
	}

	//全局
	friend istream& operator>>(istream& is, Complex& c);
	//局部 - 右移操作符不建议写在放在成员方法中
private:
	int a;
	int b;
};

//全局 - 左移操作符 - cout类型是ostream
ostream& operator<<(ostream &os, Complex &c)
{
	os << "(" << c.a << "," << c.b << "i" << ")";
	//注意：外面的<<和重载函数里面的<<不是同一个操作符
	//函数里面的<<是可以实现内置数据类型的运算
	return os;
}

//全局 - 右移操作符 - cin类型是istream
istream& operator>>(istream &is, Complex &c)
{
	cout << "a: ";
	is >> c.a;
	cout << "b: ";
	is >> c.b;
	return is;
}

int main()
{
	Complex c1(1, 2);

	//全局
	//cout << c1 << endl;//operator<<(cout,c1);//<<可以连续使用
	//局部
	//c1 << cout;//c1.operator<<(cout)

	//全局
	//cin >> c1;//operator>>(cin,c1);//>>可以连续使用
	//cout << c1;
	return 0;
}

//注意：
//重载<< 或 >>操作符时，全局函数和成员函数调用的方式不同，但都可以实现操作符重载