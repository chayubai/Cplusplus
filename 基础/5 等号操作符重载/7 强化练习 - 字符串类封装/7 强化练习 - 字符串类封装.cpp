#define _CRT_SECURE_NO_WARNINGS 1

#include "myString.h"

void test1()
{
	myString str("def");
	myString str2 = "abcb";

	//重载 << 运算符
	cout << str << endl;
	cout << str2 << endl;
}

void test2()
{
	myString str("");
	cout << "请输入字符串str：";

	//重载 >> 运算符
	cin >> str;
	cout << "字符串str的值为：" << str << endl;
}

void test3()
{
	myString str = "abcd";
	myString str2 = "aaa";
	str2 = str;//调用赋值运算符函数，执行浅拷贝动作，从而导致析构时，会释放同一块空间两次
	//因此对=进行重载
	cout << "str2 = " << str2 << endl;
}

void test4()
{
	myString str = "abcd";
	cout << "str = " << str << endl;

	//重载 [] 运算符
	str[0] = 'z';

	cout << "str[0] = " << str[0] << endl;

	cout << "str = " << str << endl;
}

void test5()
{
	myString str1 = "abc";
	myString str2 = "def";
	myString str3 = str1 + "def" + "def";
	myString str4 = str1 + str2;
	//重载 + 运算符，实现字符串拼接

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	//重载 == 运算符
	if (str3 == str4)
	{
		cout << "str3 == str4" << endl;
	}
	else
	{
		cout << "str3 != str4" << endl;
	}

	if (str3 == "abcdefdef")
	{
		cout << "str3 == abcdefdef" << endl;
	}
	else
	{
		cout << "str3 != abcdefdef" << endl;
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}