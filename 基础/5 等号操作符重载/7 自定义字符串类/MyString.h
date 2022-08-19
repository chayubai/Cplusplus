#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

class MyString
{ 
public:
	//注意：
	//strlen("123");不算\0  -- 3
	//sizeof("123");算数据类型的大小 -- 四个字节
	MyString();

	//MyString(int len);//创建一个长度是Len的string对象

	MyString(const char* str);

	MyString(const MyString& another);

	~MyString();

	//重载操作符[]
	char& operator[](int index);
	//重载操作符=
	MyString& operator=(const MyString &another);

	//重载操作符>>
	friend istream& operator>>(istream& is, MyString& s);
	//重载操作符<<
	friend ostream& operator<<(ostream& os, MyString& s);

	//重载操作符+
	MyString operator+(MyString& another);
private:
	int len;
	char* str;//用字符数组维护一个字符串
};

