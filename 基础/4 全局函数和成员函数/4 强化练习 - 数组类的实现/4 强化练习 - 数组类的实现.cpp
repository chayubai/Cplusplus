#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArray���ͷ�ļ��ͺ�������.h"

void test1()
{
#if 0
	//ջ����������
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
#endif

	//������������
	MyArray* arr = new MyArray;

	for (int i = 0; i < 10; i++)
	{
		arr->pushBack(i);
	}
	for (int i = 0; i < arr->getSize(); i++)
	{
		cout << arr->getData(i) << " ";
	}
	cout << endl;

	delete arr;
	arr = NULL;
}

void test2()
{
#if 0
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
#endif

	MyArray *arr = new MyArray(30);
	for (int i = 0; i < 10; i++)
	{
		arr->pushBack(i);
	}
	for (int i = 0; i < arr->getSize(); i++)
	{
		cout << arr->getData(i) << " ";
	}
	cout << endl;

	//ע�⣺MyArray *arr2 = arr;//���������һ��ָ�룬��arrִ�еĵ�ַ��ͬ��������ÿ�������
	//���Կ������죬����MyArray * arr2 = new MyArray(*arr);
	MyArray arr2 = *arr;//*arr�ҵ����󣬹��캯�����ر���

	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << " ";
	}
	cout << endl;

	delete arr;
	arr = NULL;
}

void test3()
{
	MyArray arr;
	//MyArray* arr = new MyArray;

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
	//MyArray* arr = new MyArray;
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

	cout << arr[9] << endl;//����arr.operator[](index)

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