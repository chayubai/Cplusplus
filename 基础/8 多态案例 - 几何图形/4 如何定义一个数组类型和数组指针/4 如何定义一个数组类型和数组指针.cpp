#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//��ζ���һ������ָ��

//����һ
//����һ����������
typedef int(ARRAY_INT_10_TYPE)[10];

//������
//ֱ�Ӷ���һ������ָ��
typedef int(*ARRAY_INT_10_TYPE_POINTER)[10];

int main(void)
{
	int array[10];//��������Ϊint[10]
	ARRAY_INT_10_TYPE array2 = { 0 };

	ARRAY_INT_10_TYPE* array_p = NULL; //ָ���������͵�ָ��
	ARRAY_INT_10_TYPE_POINTER array_p2 = NULL;

	int* p = array;//*array�����һ��Ԫ��  int �� array����������֣���Ԫ�صĵ�ַ
			//��һ�����int����ĵ�һ��Ԫ�ء�array+1����Ϊһ��int��С
	array_p = &array;//*array_p��һ��������飨int[10]��������ĵ�һ��Ԫ�ء�
			 //*(&array) = array	array_p+1����Ϊһ��int[10]��С	
	
	for (int i = 0; i < 10; i++) {
		(*array_p)[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		//cout << array[i] = 10 << endl;//������ӡ�ᱨ��
		cout << array[i] << endl;
		cout << array2[i] << endl;
	}

	//������
	int* p1[10] = { 0 };//p��ָ������ - ���ָ�������
	int(*p2)[10] = &array;//p������ָ�� - ��������ָ��
	for (int i = 0; i < 10; i++) {
		//cout << (*p2)[i] = i + 10 << endl;//������ӡ�ᱨ��
		cout << (*p2)[i] << endl;//(*p2)[i]  = array[i]
	}
	return 0;
}