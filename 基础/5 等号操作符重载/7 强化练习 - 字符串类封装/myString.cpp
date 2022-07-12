#include "myString.h"

//有参构造
myString::myString(const char* str)
{
	//cout << "myString有参构造函数调用" << endl;//测试函数是否正常
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
}

//拷贝构造
myString::myString(const myString& str)
{
	//深拷贝
	//cout << "拷贝构造函数调用" << endl;//测试函数是否正常
	this->pString = new char[strlen(str.pString)+1];//这里必须写+1
	strcpy(this->pString, str.pString);
	this->m_Size = str.m_Size;
}

//析构
myString::~myString()
{
	if (this->pString != NULL)
	{
		//cout << "析构函数调用" << endl;//测试函数是否正常
		delete[] this->pString;
		this->pString = NULL;
	}
}

//重载左移<<操作符
ostream& operator<<(ostream& cout, myString& str)
{
	cout << str.pString;//这里输出的是内部维护的字符串str.pString而不是str
	return cout;
}

//重载右移>>操作符
istream& operator>>(istream& cin, myString& str)
{
	//判断原来堆区是否有内容，有则清空
	if (str.pString)
	{
		delete[] str.pString;
		str.pString = NULL;
	}

	//开辟临时数组buf，记录用户输入str的内容
	char buf[1024];
	//输入str的内容到buf中
	cin >> buf;

	//将数据放入str.pString中来维护
	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString, buf);
	str.m_Size = strlen(buf);

	//注意：为什么不能直接cin >> str.pString;

	return cin;
}

//重载 = 运算符
myString& myString::operator=(const char* str)
{
	//判断原来堆区是否有内容，有则清空
	if (this->pString!=NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	//深拷贝
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
	return *this;
}
myString& myString::operator=(const myString& str)
{
	//判断原来堆区是否有内容，有则清空
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	//深拷贝
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = strlen(str.pString);
	return *this;
}

//重载 [] 运算符
char& myString::operator[](int index)
{
	return this->pString[index];
}

//重载 + 运算符：返回的时值，可以实现连+
myString myString::operator+(const char* str)
{
	//本身abc，传入def
	//开辟空间
	int newSize = this->m_Size + strlen(str) + 1;
	char* temp = new char[newSize];
	//清空
	memset(temp, 0, newSize);
	strcat(temp, this->pString);
	strcat(temp, str);

	myString newString = temp;

	delete[] temp;

	return newString;
}
myString myString::operator+(const myString& str)
{
	int newSize = this->m_Size + strlen(str.pString) + 1;
	char* temp = new char[newSize];
	//清空
	memset(temp, 0, newSize);
	strcat(temp, this->pString);
	strcat(temp, str.pString);

	myString newString = temp;

	delete[] temp;

	return newString;
}

//重载 == 运算符
bool myString::operator==(const char* str)
{
	if (strcmp(this->pString, str)==0)//strcmp相等返回0
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool myString::operator==(const myString& str)
{
	if (strcmp(this->pString, str.pString)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}