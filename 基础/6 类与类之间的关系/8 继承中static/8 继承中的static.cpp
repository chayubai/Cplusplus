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
	//��̬��Ա�������÷�
	A a1;
	A a2;
	cout << a1.a << endl;
	cout << a2.a << endl;

	A::a = 200;
	cout << a1.a << endl;
	cout << a2.a << endl;
	cout << "---------------" << endl;

	//����ľ�̬��Ա�����������๫�м̳к��������壨���еĶ��󣩹���
	B b1;
	B b2;
	A::a = 300;
	cout << b1.a << endl;
	cout << b2.a << endl;
	cout << a1.a << endl;
	cout << a2.a << endl;

	return 0;
}

//���ۣ��̳��еľ�̬��Ա���������干��ͬһ������