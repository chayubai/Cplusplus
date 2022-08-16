#pragma once
#include <iostream>
using namespace std;
 
class MyArray
{
public:
	//�޲ι��캯��
	MyArray();

	//�вι��캯�����û�ָ�����ȿ��������С
	MyArray(int len);

	//�������캯�� - ���
	MyArray(const MyArray& another);	

	//����λ�����Ԫ��
	void setData(int index, int data);

	//��ȡָ��λ������
	int getData(int index);

	//��ȡ����
	int getLen();

	void operator=(const MyArray& another);

	//�����������ͷ�����ռ�
	~MyArray();
private:
	int len;
	int* space;//����ά�����Ͽ��ٵĿռ�
};

