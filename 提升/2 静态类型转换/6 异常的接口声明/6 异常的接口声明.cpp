#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�쳣�ӿ��������ã��ں����У��޶��׳��쳣������

//���������Ҫ��QT����Linux�²��ܲ��Գɹ���windows�²��ϸ�

//�쳣�ӿ������������ϸ�����Щ���͵��쳣��throw(��) ���� �������׳��쳣
void func()throw(int,double)//ֻ�����׳�int,double���͵��쳣���׳��������͵��쳣�ͻᱨ��
{
	//throw "abc";//linux�±���windows�������У����ϸ�
}
void func2() throw()
{
	//�����׳��κ����͵��쳣
}
void func3()
{
	//�����׳��κ����͵��쳣
}
int main()
{
	try
	{
		func();
	}
	catch (int)
	{
		cout << "int �����쳣����" << endl;
	}
	catch (...)//���������쳣
	{
		cout << "���� �����쳣����" << endl;
	}
	return 0;
}