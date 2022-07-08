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
	friend ostream& operator<<(ostream& os, Complex& c);
	//�ֲ� - ���Ʋ�����������д�ڷ��ڳ�Ա������
	//ostream& operator<<(ostream& os)
	//{
	//	os << "(" << this->a << "," << this->b << "i" << ")";
	//	return os;
	//}

	//ȫ��
	friend istream& operator>>(istream& is, Complex& c);
	//�ֲ� - ���Ʋ�����������д�ڷ��ڳ�Ա������
private:
	int a;
	int b;
};

//ȫ�� - ���Ʋ����� - cout������ostream
ostream& operator<<(ostream &os, Complex &c)
{
	os << "(" << c.a << "," << c.b << "i" << ")";
	return os;
}

//ȫ�� - ���Ʋ����� - cin������istream
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

	//ȫ��
	//cout << c1 << endl;//operator<<(cout,c1);//<<��������ʹ��
	//�ֲ�
	//c1 << cout;//c1.operator<<(cout)

	//ȫ��
	cin >> c1;//operator>>(cin,c1);
	cout << c1;
	return 0;
}