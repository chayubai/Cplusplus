#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>

using namespace std;

class myString
{
	friend ostream& operator<<(ostream& cout, myString& str);
	friend istream& operator>>(istream& cin, myString& str);
public:
	//�вι���
	myString(const char* str);

	//��������
	myString(const myString& str);

	//���� = �����
	myString& operator=(const char* str);//str2 = "abcd"
	myString& operator=(const myString& str);//str2 = str

	//���� [] �����
	char& operator[](int index);

	//���� + �����
	myString operator+(const char* str);
	myString operator+(const myString& str);

	//���� == �����
	bool operator==(const char* str);
	bool operator==(const myString& str);

	//����
	~myString();
private:
	char* pString;//ά���ڶ������ٵ��ַ�����

	int m_Size;//�ַ����ĳ��ȣ���ͳ��'\0'��
};

