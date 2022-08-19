#define _CRT_SECURE_NO_WARNINGS 1

#include "myString.h"

void test1()
{ 
	myString str("def");
	myString str2 = "abcb";//有参构造myString str2 = str;拷贝构造

	//重载 << 运算符
	cout << str << endl;
	cout << str2 << endl;
}

void test2()
{
	myString str("");//原数组堆区有内容
	cout << "请输入字符串str：";

	//重载 >> 运算符 - 等待用户输入，实际上是输入到缓冲区里，否则无法实现等待输入的过程
	//1、先清空原数组的内容
	//2、再将用户输入的内容放入缓冲区中
	//3、将内容放入用户维护的数组中
	cin >> str;
	cout << "字符串str的值为：" << str << endl;

	myString str3 = "###";
	cout << "请输入新的字符串str3：";
	cin >> str3;

	myString str4 = str3;

	cout << "字符串str4的值为：" << str << endl;
}

void test3()
{
	myString str = "abcd";
	myString str2 = "aaa";//原数组堆区有内容
	str2 = str;//调用默认赋值运算符函数，执行浅拷贝动作，从而导致析构时，会释放同一块空间两次
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
	myString str4 = str1 + str2;//返回新的字符串
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

	myString sa("12");
	myString sb("12");
	//cout << sa + sb << endl;//报错，为什么？
}

int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}