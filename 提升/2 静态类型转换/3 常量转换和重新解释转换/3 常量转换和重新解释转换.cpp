#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//常量转换，指针，引用，对象指针
//该运算符用来修改类型的const属性
//1、常量指针转换非常量指针，并且仍然指向原来的对象
//2、常量引用转换非常量引用，并且仍然指向原来的对象
//3、不可以直接对非指针和非引用的变量使用常量操作符const_cast去直接移除它的const

//常量转换，关键字const_cast
void test1()
{
	//常量指针转换成非常量指针
	const int* p = NULL;
	int* np = const_cast<int*>(p);
}

void test2()
{
	//非常量指针转换成常量指针
	int* pp = NULL;
	const int* npp = const_cast<const int*>(pp);
}

void test3()
{
	const int a = 10;
	//int b = const_cast<int>(a);//报错，不能对非指针或引用进行转换
}

void test4()
{
	//常量引用转换成非常量引用
	int a = 10;
	const int& b = a;
	//b = 20;//不能修改
	int& c = const_cast<int&>(b);

	//非常量引用转换成常量引用
	int num = 10;
	int& reNum = num;
	const int& reNum2 = const_cast<const int&>(reNum);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
}

//重新解释转换，关键字reinterpret_cast
//重新解释转换是一种最不安全的转换，不建议使用
//强制类型转换，任何类型值（指针）都可以转换为其他类型

class Base{};
class Other {};
void test5()
{
	int a = 10;
	int* p = reinterpret_cast<int*>(a);

	//将base转换为Other*，Base和Other两个类之间的结构可能不同却可以转换，因此不安全
	Base* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}
typedef void(FP1)(int, int);
typedef void(FP2)(int, char*);
void test6()
{
	//任意函数指针之间转换
	FP1* func1 = NULL;
	FP2* func2 = reinterpret_cast<FP2*>(func1);

}
int main()
{
	test1();
	return 0;
}