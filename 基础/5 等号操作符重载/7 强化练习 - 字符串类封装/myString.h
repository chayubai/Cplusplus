#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>

using namespace std;

class myString
{
	friend ostream& operator<<(ostream& cout, myString& str);
	friend istream& operator>>(istream& cin, myString& str);
public:
	//有参构造
	myString(const char* str);

	//拷贝构造
	myString(const myString& str);

	//重载 = 运算符
	myString& operator=(const char* str);//str2 = "abcd"
	myString& operator=(const myString& str);//str2 = str

	//重载 [] 运算符
	char& operator[](int index);

	//重载 + 运算符
	myString operator+(const char* str);
	myString operator+(const myString& str);

	//重载 == 运算符
	bool operator==(const char* str);
	bool operator==(const myString& str);

	//析构
	~myString();
private:
	char* pString;//维护在堆区开辟的字符数组

	int m_Size;//字符串的长度（不统计'\0'）
};

