#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	static int a;
};
int A::a = 100;//��̬��Ա�����ĳ�ʼ��
class B:public A
{
public:

};
int main()
{
	A a1;
	A a2;
	cout << a1.a << endl;
	cout << a2.a << endl;

	A::a = 200;
	cout << a1.a << endl;
	cout << a2.a << endl;
	cout << "---------------" << endl;

	B b1;
	B b2;
	A::a = 300;
	cout << b1.a << endl;
	cout << b2.a << endl;
	cout << a1.a << endl;
	cout << a2.a << endl;

	//����ľ�̬��Ա�������������干��
	return 0;
}