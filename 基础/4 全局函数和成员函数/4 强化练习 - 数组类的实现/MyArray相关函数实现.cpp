#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArray���ͷ�ļ��ͺ�������.h"
 
//�޲ι��캯�����û�û��ָ�����������ʼ��Ϊ100
MyArray::MyArray()
{
	cout << "Ĭ�Ϲ��캯������" << endl;//������׽�����Ƿ����
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAdress = new int[this->m_Capacity];
}

//�вι��캯�����û�ָ��������ʼ��
MyArray::MyArray(int capacity)//explicit��ֹMyArray arr = 100�Ĵ�����ʽ
{
	cout << "�вι��캯������" << endl;//������׽�����Ƿ����
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAdress = new int[this->m_Capacity];
}

//�������캯��
MyArray::MyArray(const MyArray& arr)
{
	cout << "�������캯������" << endl;//������׽�����Ƿ����

	//ͬ��֮����˽��,*this��arr��ͬ��
	
	//������Ĭ���ṩ�Ŀ������캯����ʵ��
	/*this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->pAdress = arr.pAdress;//ǳ����
	*/

	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	//���
	this->pAdress = new int[arr.m_Capacity];
	//������Ԫ�ظ���һ��
	for (int i = 0; i < m_Size; i++)
	{
		this->pAdress[i] = arr.pAdress[i];
	}
}

//�û������ӿ�
//β�巨
void MyArray::pushBack(int val)
{
	this->pAdress[this->m_Size] = val;
	this->m_Size++;
	//ע�⣺β��ʱ������Խ������
}
//����λ�����Ԫ��
void MyArray::setData(int pos, int val)
{
	this->pAdress[pos] = val;
}

//��ȡָ��λ������
int MyArray::getData(int pos)
{
	return this->pAdress[pos];
}

//��ȡ��������
int MyArray::getCapcity()
{
	return this->m_Capacity;
}

//��ȡ�����С
int MyArray::getSize()
{
	return this->m_Size;
}

//�����������ͷŶ���������ռ�
MyArray::~MyArray()
{
	if (this->pAdress != NULL)
	{
		cout << "�����캯������" << endl;//������׽�����Ƿ����
		delete[] this->pAdress;//����������new ��������[���ݴ�С]���ͷ���Ҫ��[]
		this->pAdress = NULL;
	}
}

//����[]�����
/*int MyArray::operator[](int index)
{
	return this->pAdress[index];
}*/

int& MyArray::operator[](int index)
{
	return this->pAdress[index];
}