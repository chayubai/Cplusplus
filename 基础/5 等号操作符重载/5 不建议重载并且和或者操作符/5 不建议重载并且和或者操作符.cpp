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

	//ʧȥ�˶�·����
	//complex1.oprator&&(complex1.operator+=(complex2))
	//������complex1 += complex2����complex1Ϊ1����ʱcomplex1 && complex1��1&&1Ϊ��

	//��˲�Ҫ����&&��||������
	if (complex1 && (complex1 += complex2))
	{
		cout << "�棡" << endl;
	}
	else
	{
		cout << "�٣�" << endl;
	}

	return 0;
}