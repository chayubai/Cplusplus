#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(int flag)
	{
		this->flag = flag;
	}
	Complex& operator+=(Complex& complex)
	{
		this->flag = this->flag + complex.flag;
		return *this;
	}
	bool operator&&(Complex& complex)
	{
		return this->flag && complex.flag;
	}
public:
	int flag;
};
int main()
{
	Complex complex1(0);//flag = 0
	Complex complex2(1);//flag = 1

	//失去了短路特性
	//complex1.oprator&&(complex1.operator+=(complex2))
	//先运算complex1 += complex2导致complex1为1，此时complex1 && complex1即1&&1为真

	//因此不要重载&&和||操作符
	if (complex1 && (complex1 += complex2))
	{
		cout << "真！" << endl;
	}
	else
	{
		cout << "假！" << endl;
	}

	return 0;
}