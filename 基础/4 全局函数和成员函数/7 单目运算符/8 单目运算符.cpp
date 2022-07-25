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
	

	//ǰ��++ 
	//ȫ�� - ����ʵ��ǰ��++����
	friend Complex& operator++(Complex& c);
#if 0
	//�ֲ� - ����ʵ��ǰ��++����
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
#endif
	
#if 0
	//����++
	//ȫ�� - ������ʵ�ֺ���++����
	friend const Complex operator++(Complex& c��int);
#endif	
	//�ֲ� - ����ʵ�ֺ���++����
	const Complex operator++(int)
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;//����const Complex tmp = temp;��ʱtmp�������޸�
	}

	//friend const Complex operator--(Complex& c��int);
private:
	int a;
	int b;
};

//ȫ��-����ǰ��++���������++,��ֵ - ����ʵ��ǰ��++����
Complex& operator++(Complex& c)
{
	c.a++;
	c.b++;
	return c;
}

#if 0
//ȫ��-���غ���++�������ͨ��ռλ����int������ǰ��++�ͺ���++�ĺ���������Ϊ�������ò�����ͬ��
//�ȸ�ֵ����++ - ������ʵ�ֺ���++����
const Complex operator++(Complex &c��int)
{
	Complex temp(c.a, c.b);//����������
	c.a++;
	c.b++;
	return temp;//����const Complex tmp = temp;��ʱtmp�������޸�
}
#endif

#if 0 ȫ�ֺ��� - ����ʵ�ֺ���--����
const Complex operator--(Complex& c��int)//�����������Ϊconst Complex&?-���ؾֲ����������ã�
{
	Complex temp(c.a, c.b);//����������
	c.a--;
	c.b--;
	return temp;//����const Complex tmp = temp;��ʱtmp�������޸�
}
#endif

int main()
{
	Complex c1(1, 2);
	c1.printComplex();
	++c1;//operator++(Complex& c)��������ǰ��++����++++++c1;����ֵ��c1
	c1.printComplex();
	++++++c1;
	c1.printComplex();

	Complex c2(1, 2);
	c2.printComplex();
	//c2++;//operator++(Complex &c��int)��������������++��������ֵ��c2�����ǲ��ܸı䣬�纯������const
	//c2.printComplex();

	Complex c3 = c2++;
	c3.printComplex();
	c2.printComplex();

	return 0;
}
//���ɣ�ʵ�ֲ��������أ��൱��ģ��ʵ�ֲ������Ĺ���
//����ͨ�������������͵Ĳ��������㣬ģ��ʵ���Զ����������͵Ĳ��������ع���
void test()
{
	int a = 10;
	++++++a;//��(++(++(++a)))ÿ��++�󷵻�a
	//a++++++;�������շ���һ����ֵ

	------a;//��(--(--(--a)))ÿ��--�󷵻�a
	//a------; �������շ���һ����ֵ
}

//ע�⣺
//ȫ�ֺ����ͳ�Ա����������ʵ��ǰ��++/--����
//��ֻ�г�Ա��������ʵ�ֺ���++/--����