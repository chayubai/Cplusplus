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
	//ǰ��++
	//ȫ��
	//friend Complex& operator++(Complex& c);

	//�ֲ�
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
#endif

	//����++
	//ȫ��
	//friend const Complex operator++(Complex& c��int);
	
	//�ֲ�
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
//ȫ��-����ǰ��++�����
Complex& operator++(Complex& c)
{
	c.a++;
	c.b++;
	return c;
}
#endif

#if 0
//ȫ��-���غ���++�������ͨ��ռλ����int������ǰ��++�ͺ���++�ĺ�����
const Complex operator++(Complex &c��int)
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
	++c1;//operator++(Complex& c)��������ǰ��++����++++++c1;����ֵ��c1
	c1.printComplex();

	//Complex c2(1, 2);
	//c2.printComplex();
	//c2++;//operator++(Complex &c��int)��������������++��������ֵ��c2�����ǲ��ܸı䣬�纯������const
	//c2.printComplex();

	return 0;
}