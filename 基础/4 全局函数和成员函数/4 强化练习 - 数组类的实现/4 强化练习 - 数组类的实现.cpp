#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArray���ͷ�ļ��ͺ�������.h"

void test1()
{
	MyArray arr;//�����޲ι���
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;
}

void test2()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	MyArray arr2(arr);//���Կ�������
	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << " ";
	}
	cout << endl;
}

void test3()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	arr.setData(0, 1000);
	cout << "arr�±�Ϊ0��λ�õ����ݣ�" << arr.getData(0) << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	cout << "��������Ϊ��"<<arr.getCapcity() << endl;
	cout << "�����СΪ��" << arr.getSize() << endl;

	//��Σ�����[]��ʽȥ���������е�Ԫ�أ��ɶ���д��
	//arr[0] = 100;
	//cout << arr[0] << endl;
}

void test4()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;
	//��Σ�����[]��ʽȥ���������е�Ԫ�أ��ɶ���д��
	//arr[0] = 100;
	//cout << arr[0] << endl;

	cout << arr[9] << endl;

	arr[9] = 100;//���ڷ���������int������arr[9]�ķ���ֵ����ֵ����������Ϊ��ֵ

	//�����Ҫ�������ã�������Ϊ��ֵ
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}