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
	//ȫ��
	//friend Complex& operator+=(Complex& c1, Complex& c2);

	//�ֲ�
	Complex& operator+=(Complex& another)//����ֵ��Complex&���´����ӵ�ʱ���ı���Ƕ�����
	{									 //����ֵ��Complex���´����ӵ�ʱ���ı������������
		this->a += another.a;
		this->b += another.b;
		return *this;//����*this
	}
private:
	int a;//ʵ��
	int b;//����
};
//ȫ��
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

//ע�⣺
//ȫ�ֺ����ͳ�Ա���� ���������ض���ʵ����+=/-=��������������
//��ֻ�г�Ա���� ���������ز���ʵ����+/-��������������