#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//����ģ��
template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ�����" << endl;
}
//ģ�庯��
void myPrint(int a, int b)
{
	cout << "����ģ�����" << endl;
}

void myPrint(double a, double b)
{
	cout << "����ģ�����" << endl;
}

//����ģ��     --->      ģ�庯��     --->     ������
//���磺������ģ��   --->    �������������    --->    ���ܴ�������

//ģ�庯������ʹ�����(�����õ�ʱ��)��������
void test()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);//����void myPrint(int a, int b);������
	double a = 10;
	double b = 20;
	myPrint(a, b);//����void myPrint(double a, double b);������
	myPrint(a, a);//�������ɵ�void myPrint(int a, int b);
}

//1�����ԣ�Linux��,index.cpp�б�д����
#include <iostream>
using namespace std;

template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ�����" << endl;
}
int main()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);
	double a = 10;
	double b = 20;
	myPrint(a, b);
	return 0;
}
//2��g++ -S index.cpp -o index.s//����Ԥ����

//3���鿴vim index.s�µĴ���

//4��main::
//main�����еĵ��ã���������������
//call  _Z5MyAddIiET_S0_S0_
//call  _Z5MyAddIdET_S0_S0_
//�鿴����������

//5�������м��룺myPrint(a, a);���±���
//����main::����һ�κ�������
//call  _Z5MyAddIiET_S0_S0_
//call  _Z5MyAddIdET_S0_S0_
//call  _Z5MyAddIiET_S0_S0_
//�鿴����ֻ��������������˵��ֻ��������������