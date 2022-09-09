#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//异常接口声明作用：在函数中，限定抛出异常的类型

//这个测试需要在QT或者Linux下才能测试成功，windows下不严格

//异常接口声明：声明严格抛哪些类型的异常。throw(空) 代表 不允许抛出异常
void func()throw(int,double)//只允许抛出int,double类型的异常，抛出其他类型的异常就会报错
{
	//throw "abc";//linux下报错，windows可以运行，不严格
}
void func2() throw()
{
	//不能抛出任何类型的异常
}
void func3()
{
	//可以抛出任何类型的异常
}
int main()
{
	try
	{
		func();
	}
	catch (int)
	{
		cout << "int 类型异常捕获" << endl;
	}
	catch (...)//捕获其他异常
	{
		cout << "其他 类型异常捕获" << endl;
	}
	return 0;
}