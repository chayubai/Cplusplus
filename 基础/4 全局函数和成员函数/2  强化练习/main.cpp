#define _CRT_SECURE_NO_WARNINGS 1

#include "MyArray.h"

int main()
{
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
	array3 = array1;//����Ĭ�ϵ�=����������
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3.getData(i) << " ";
	}
	cout << endl;

	return 0;
}