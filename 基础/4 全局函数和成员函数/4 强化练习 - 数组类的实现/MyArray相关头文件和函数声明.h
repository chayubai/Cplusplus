#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;

class MyArray
{
public:
	//�޲ι��캯�����û�û��ָ�����������ʼ��Ϊ100
	MyArray();

	//�вι��캯�����û�ָ��������ʼ��
	explicit MyArray(int capacity);//explicit��ֹMyArray arr = 100�Ĵ�����ʽ

	//�������캯��
	MyArray(const MyArray& arr);

	//�û������ӿ�
	//����λ�����Ԫ��
	void setData(int pos, int val);

	//��ȡָ��λ������
	int getData(int pos);

	//β�巨
	void pushBack(int val);

	//��ȡ��������
	int getCapcity();

	//��ȡ�����С
	int getSize();

	//�����������ͷŶ���������ռ�
	~MyArray();

	//����[]�����
	//int operator[](int index);
	int& operator[](int index);

private:
	int m_Capacity;//����һ�������ɶ��ٸ�Ԫ�أ�����������

	int m_Size;//��ǰ�ж��ٸ�Ԫ�أ��������С

	int* pAdress;//ָ��洢���ݵĿռ䣬����ά�������Ͽ��ٵ�����ռ��ָ��
};