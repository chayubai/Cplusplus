#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;

void test1()
{
	int a = 10;
	//1�����õĻ����﷨�� ���� &���� = ԭ��
	int& re = a;//int& ʹ�������������ͣ�re��a�ı���
	re = 50;//��a�Ŀռ��ֵ��Ϊ��50
	cout << "a = " << a << endl;
	cout << "b = " << re << endl;
}

void test2()
{
	//2��
	int a = 10;
	//int& re2;//���ñ����ʼ��������const int a;a�����ʼ��

	int& ra = a;
	//����һ����ʼ���󣬾Ͳ�����������������

	int b = 200;
	//&ra = b;//�ᱨ������������൱��ȡ��ַra ��ȡ��ַa����b��ֵһ����ַ

	ra = b;//���в��Ǹ�bȡ����Ϊra�����ǽ�b��ֵΪra����ra = a = b

	cout << "a = " << a << endl;//200
	cout << "b = " << ra << endl;//200
	cout << "c = " << b << endl;//200
}

void test3()
{
	//3�������齨������
	int arr[10];
	int(&rArr)[10] = arr;//��1��ֱ�ӽ�������
	for (int i = 0; i < 10; i++)
	{
		rArr[i] = 100 + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << rArr[i] << " ";
	}
	//��2���ȶ�����������ͣ���ͨ�����Ͷ�������
	typedef int(ARRAY_TYPE)[10];
	//���� &���� = ԭ��
	ARRAY_TYPE& rArr2 = arr;//��������ȡ���
	for (int i = 0; i < 10; i++)
	{
		cout << rArr2[i] << " ";
	}
}

void test4()
{
	int a = 10;
	int& rNum = a;//a�ı���ΪrNum
	int& ra = rNum;//rNum�ı���Ϊra
	cout << "ref = " << ra << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	int* p = &a;
	*p = 30;//a

	p = &b;
	*p = 60;//b

	/*
	1������û�ж��壬��һ�ֹ�ϵ����������������ԭ��ĳһ�����Ĺ�ϵ��
	�ʶ�������ԭ���ͱ���һ�£��Ҳ������ڴ档�����õı�������ͬ�ĵ�ַ��
	2��������ʱ������ʼ����һ�����������ɱ����
	3���ɶ����ã��ٴ����á�������õĽ������ĳһ�������ж������
	4��&����ǰ������������ʱ�������á�������Ϊȡ��ַ��
	*/
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main()
{
	//����ֱ�����ó���
	//double& d = 12.3;

	//ָ����������
	const double& d = 12.3;

	return 0;
}