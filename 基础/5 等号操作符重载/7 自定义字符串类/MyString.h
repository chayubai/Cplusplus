#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

class MyString
{ 
public:
	//ע�⣺
	//strlen("123");����\0  -- 3
	//sizeof("123");���������͵Ĵ�С -- �ĸ��ֽ�
	MyString();

	//MyString(int len);//����һ��������Len��string����

	MyString(const char* str);

	MyString(const MyString& another);

	~MyString();

	//���ز�����[]
	char& operator[](int index);
	//���ز�����=
	MyString& operator=(const MyString &another);

	//���ز�����>>
	friend istream& operator>>(istream& is, MyString& s);
	//���ز�����<<
	friend ostream& operator<<(ostream& os, MyString& s);

	//���ز�����+
	MyString operator+(MyString& another);
private:
	int len;
	char* str;//���ַ�����ά��һ���ַ���
};

