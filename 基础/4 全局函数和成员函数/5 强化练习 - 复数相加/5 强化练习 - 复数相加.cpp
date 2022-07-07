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

	//��һ�֣�ͨ���Զ���ȫ�ֺ���ʵ�֣�����Ϊ��Ԫ����
	//friend Complex complexAdd(Complex& c1, Complex& c2);
	
	//�ڶ��֣�ͨ���Զ���ֲ���Ա����ʵ��
	Complex complexAdd(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//�����֣�����������д��ȫ�ֺ���������Ϊ��Ԫ����
	//friend Complex operator+(Complex& c1, Complex& c2);
	
	//�����֣�����������д�ڳ�Ա����
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
private:
	int a;//ʵ��
	int b;//����
};
//��һ�֣�ͨ���Զ���ȫ�ֺ���ʵ��
//Complex complexAdd(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

//������ - ����������д��ȫ�ֺ���
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

	//Complex c5 = c1 + c2;//�ȼ���operator+(c1, c2);��������������ƣ���������˳�򣬾��Ǻ���������˳��
	//c5.printComplex();

	//Complex c6 = c1 + c2;//�ȼ���c1.operator+(c2);
	//c6.printComplex();

	//ע��Complex c6 = c1 + c2;���õĲ��������أ���ȫ�ֵĺ;ֲ���ֻ�ܳ�����һ��ֻ�ܳ�����һ������ᱨ��

	return 0;
}