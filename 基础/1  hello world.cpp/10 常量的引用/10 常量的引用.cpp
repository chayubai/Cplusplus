#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void test1()
{
	//string &str = "hello";//������ֱ�ӶԳ�����������
	//int &ref = 10;//������ֱ�ӶԳ����������ã������˲��Ϸ����ڴ�
	const int& ref = 10;//����const֮���൱��д�ɣ�int temp = 10;const int &ref = temp;

	//const int *ref = &temp
	
	//int* p = &ref;//������Ҫǿת��ע��۲챨�����:const int *ת��Ϊint*
	int* p = (int*)&ref;//const int *ref = &temp��ͨ��ָ������޸�
	*p = 10000;
	cout << ref << endl;
}

//�������õ�ʹ�ó���,const���κ����е��βΣ���ֹ�����
void show1(int &a)
{
	a = 10000;//���������ᵼ��ֱ���޸������a�Ľ��
	cout << "a = " << a << endl;
}
void show2(const int& a)
{
	//a = 10000;//������const�����β�ʱ����ʱֱ���޸�����һ�лᱨ����ֹ�������
	cout << "a = " << a << endl;
}
void test2()
{
	int a = 100;
	show1(a);//ֻ������ʾ����
	cout << "�ⲿ��a = " << a << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}