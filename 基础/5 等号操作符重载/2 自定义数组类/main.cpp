#define _CRT_SECURE_NO_WARNINGS 1
 
#include "MyArray.h"
#include <iostream>
using namespace std;

int main()
{
#if 0
	MyArray array1(10);//����10��Ԫ�ص�����
	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		array1.setData(i, i + 10);
	}
	cout << "------------" << endl;
	cout << "array1:";
	//��ӡ
	for (int i = 0; i < 10; i++)
	{
		cout << array1.getData(i) << " ";
	}
	cout << endl;

	MyArray array2 = array1;//array2�Ŀ������캯��
	cout << "array2:";

	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2.getData(i) << " ";
	}
	cout << endl;

	MyArray array3;
	array3 = array1;
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3.getData(i) << " ";
	}
	cout << endl;
#endif

#if 0
	MyArray array1(10);//����10��Ԫ�ص�����
	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}
	cout << "------------" << endl;
	cout << "array1:";
	//��ӡ
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array2 = array1;//array2�Ŀ������캯��
	cout << "array2:";

	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2[i] << " ";
	}
	cout << endl;

	MyArray array3;
	array3 = array1;
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3[i] << " ";
	}
	cout << endl;
#endif

#if 0
	MyArray array1(10);//����10��Ԫ�ص�����
	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}

	cout << "array1:";
	//��ӡ
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	cout << "------------" << endl;

	MyArray array3(20);//ԭ����������
	array3 = array1;
	cout << "array3:";
	cout << array3 << endl;
#endif

#if 0
	MyArray array3(5);
	cin >> array3;
	cout << "array3:";
	cout << array3 << endl;
#endif

#if 0
	MyArray array1(10);//����10��Ԫ�ص�����
	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//���ص���space[i],���ڿ��Ե���ֵ����������Ϊ����
	}

	cout << "array1:";
	//��ӡ
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array3(10);
	cin >> array3;
	cout << "array3:" << array3 << endl;

	if (array3 == array1)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
#endif

	MyArray array1(10);//����10��Ԫ�ص�����
	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}

	cout << "array1:";
	//��ӡ
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array3(10);
	cin >> array3;
	cout << "array3:" << array3 << endl;

	if (array3 != array1)
	{
		cout << "�����" << endl;
	}
	else
	{
		cout << "���" << endl;
	}
	return 0;
}