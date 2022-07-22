#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//C语言没有默认参数和占位参数的概念
#if 0
//默认参数:形参被初始化了
int myfunc1(int a = 10,int b = 5)
{
	return a + b; 
}
void test1()
{
	cout << myfunc1() << endl;//如果不传参，默认使用默认参数，如果传参，使用传入参数
	cout << myfunc1(20) << endl;
	cout << myfunc1(20, 30) << endl;
}

//注意事项：如果有一个位置有默认参数，那么从这个位置起，从左到右必须有默认值
//int func(int a, int b = 10, int c)
//{
//	retrun a + b + c;
//}
//func(20,10);报错

//函数的声明和实现，只能有一个提供默认参数，不可以同时加默认参数
int myfunc2(int a, int b, int c);
int myfunc2(int a, int b = 5,int c = 10)
{
	return a + b + c;
}
void test2()
{
	cout << myfunc2(20) << endl;
}

//求立方体体积
//注意：默认参数必须是从右向左添加默认值
int get_volume(int len,int width,int height = 10)
{
	cout << "len = " << len << endl;
	cout << "width = " << width << endl;
	cout << "height = " << width << endl;

	return len * width * height;
}

void test3()
{
	int len = 10;
	int w = 20;
	int h = 20;
	//参数，默认传值从左向右传入
	//传1个参数，传入左边第一个参数，传2个参数，传入左边第一个和第二个参数
	cout << "体积是 " << get_volume(len, w) << endl;
	cout << "体积是 " << get_volume(w, h) << endl;
}

//占位参数:只写一个类型进行占位，调用的时候必须传入占位值
//占位参数的作用：++/--运算符的重载，用于区别前置还是后置
//占位参数可以有默认参数
void func2(int x, int)//函数数据类型为void (int, int)
{
	cout << "x = " << x << endl;
}
void func2(int x, int=0)
{
	cout << "x = " << x << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();

	func2(199, 10);
	func2(200);
	return 0;
}
#endif 

#include <string>
string chatTo(const string& toName, const string& content)
{
	string msg = "你悄悄对【" + toName + "】说：" + content;
	return msg;
}
string chatFrom(const string& fromName = "系统", const string& content ="默认系统信息")
{
	string msg = "【" + fromName + "】悄悄对你说：" + content;
	return msg;
}
int main()
{
	string toName, content, chatMsg, fromName;
	cout << "请输入要对谁发送信息：";

	getline(cin, toName);
	fromName = toName;

	cout << "请输入要发送的聊天信息：";
	getline(cin, content);

	chatMsg = chatTo(toName, content);
	cout << chatMsg << endl;

	cout << "请输入来自对方的聊天信息：";
	getline(cin, content);
	//chatMsg = chatFrom();
	chatMsg = chatFrom(fromName,content);

	cout << chatMsg << endl;

	return 0;
}