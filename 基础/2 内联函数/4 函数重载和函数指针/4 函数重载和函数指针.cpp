#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
void func(int a, int b)
{
	cout << "func1" << endl;
}
//1、重定义一种函数类型
typedef void (MY_FUNC)(int, int);

//2、重定义一种指向函数的函数指针
typedef void (*MY_FUNC_P)(int, int);

void func(int a, int b, int c)
{
	cout << "func2" << endl;
}
int main()
{
	MY_FUNC* pf1 = NULL;
	pf1 = func;
	pf1(10,20);//或者(*pf)(10,20);

	MY_FUNC_P pf2 = NULL;
	pf2 = func;
	pf2(10, 20);
	//3、
	void (*pf3)(int, int) = NULL;
	pf3 = func;
	pf3(10, 20);
	cout << "------------" << endl;

	//函数重载
	func(10, 20);
	func(10, 20, 30);

	pf3 = func;//pf3指向的是void func(int, int)
	pf3(10, 30);//调用的是void func(int, int)
	//pf3(10, 20, 30);//报错
	
	//实际上，在给函数指针赋值的时候，是会发生函数重载匹配的
	//在调用函数指针的时候，所调用的函数就已经固定了。
	int (*pf4)(int, int, int, int) = NULL;
	//pf4 = func();

	return 0;
}
