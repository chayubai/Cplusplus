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
	
	//�ڶ��֣�ͨ���Զ���ֲ���Ա����ʵ�֣�����ʵ����+=����
	Complex complexAdd(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//�����֣�����������д��ȫ�ֺ���������Ϊ��Ԫ����
	//friend Complex operator+(Complex& c1, Complex& c2);
	
	//�����֣�����������д�ڳ�Ա���� ����ʵ�����Ӳ���
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//friend Complex operator-(Complex& c1, Complex& c2);

	//�ֲ���Ա��������ʵ����������
	Complex operator-(Complex& another)
	{
		Complex c(this->a - another.a, this->b - another.b);
		return c;//Complex temp = c;��temp����������
	}
private:
	int a;//ʵ��
	int b;//����
};
//��һ�֣�ͨ���Զ���ȫ�ֺ���ʵ�֣�����ʵ����+=����
//Complex complexAdd(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

//������ - ����������д��ȫ�ֺ�����������ʵ�����Ӳ���
//Complex operator+(Complex& c1, Complex& c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//  //���غ�������Ĳ��������Զ����������͵�ʹ�õĲ�������ͬ
//	//���غ�������Ĳ���������ʵ�������������͵�����
//	return temp;
//}

/*
	//ȫ�ֺ�������ʵ����������
Complex operator-(Complex& c1, Complex& c2)
{
	Complex c(c1.a - c2.a, c1.b - c2.b);
	return c;//Complex temp = c;��temp����������
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

	//�������������Զ����������͵������������Ҫ����+������
	//Complex c5 = c1 + c2;//�ȼ���operator+(c1, c2);��������������ƣ���������˳�򣬾��Ǻ���������˳��
	//c5.printComplex();

	Complex c6 = c1 + c2;//�ȼ���c1.operator+(c2);
	//c6.printComplex();
	Complex c7 = c1 + c2 + c1;
	//c7.printComplex();
	
	//ע��Complex c6 = c1 + c2;���õĲ��������أ���ȫ�ֵĺ;ֲ���ֻ�ܳ�����һ��ֻ�ܳ�����һ������ᱨ��


	Complex c8 = c1 - c2;
	c8.printComplex();
	Complex c9 = (c1 - c2) - c1;
	//������ص�����������c1 - c2 = temp�����ÿ�������
	//��ִ��temp - c1ʱ������temp'

	//������ص������ã���c1 - c2 = c = temp������temp��c�ı�����c�Ǿֲ�����
	//ִ����c1 - c2��c�����գ�������ֵ
	//��ִ��c - c1ʱ��
	c9.printComplex();

	return 0;
}

//ע�⣺
//.��Աѡ���  .*��Ա����ѡ���  ::����������� ?:���������� ��������
//�磺A a; a.*b �൱�� *(a.b)
//���������ز��ܸı�������Ĳ�������
//��������ز�����Ĭ�ϲ���
//�磺operator+(Complex& c1, int = 10){}//c+Υ���ˡ����������ز��ܸı�������Ĳ���������