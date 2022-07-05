#pragma once
#include <iostream>
using namespace std;

class MyArray
{
public:
	//�޲ι��캯��
	MyArray();

	//�вι��캯�����û�ָ�����ȳ�ʼ��
	MyArray(int len);

	//�û������ӿ�
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
	int* space;
};

