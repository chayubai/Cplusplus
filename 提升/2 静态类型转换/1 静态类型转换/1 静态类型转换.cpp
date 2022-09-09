#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//静态转换
//用于内置数据类型的转换
//用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换
//1、向上转换 - 子转父是安全的。
//2、向下转换 - 寻址小的转寻址大的，是不安全的。

//静态类型转换，关键字static_cast
void test1()
{
	//允许内置数据类型之间转换
	char a = 'a';
	double d = static_cast<double>(a);

	cout << d << endl;
}

class Base {};
class Son :public Base{};
class Other{};

void test2()
{
	Base* base = NULL;
	Son* son = NULL;

	//不支持基本数据类型指针直接的转换
	//int* p = NULL;
	//char* sp = static_cast<char*>(p);//报错

	//语法： static_cast<目标类型>(原对象/变量)
	//将base转为Son* 父转子 向下类型转换，不安全，但可以成功
	Son* s = static_cast<Son*>(base);

	//将son转为Base* 子转父 向上类型转换， 安全
	Base* b = static_cast<Base*>(son);

	//将base转为Other*
	//Other* o = static_cast<Other*>(base);//报错：转换无效

	//static_cast是父子之间的指针或者引用可以转换
}

void test3()
{
	Base base;
	Son son;
	Base& bs = base;
	Son& sn = son;

	//将bs转为Son&  父转子 向下类型转换，不安全
	Son& s = static_cast<Son&>(bs);

	//将sn转为Base& 子转父 向上类型转换， 安全
	Base& b = static_cast<Base&>(sn);

	//将bs转为Other&
	//Other& o = static_cast<Other&>(bs);//转换无效

	//static_cast是父子之间的指针或者引用可以转换
}

int main()
{
	test1();
	return 0;
}