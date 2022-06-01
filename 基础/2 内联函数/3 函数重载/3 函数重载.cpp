#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//C语言中，函数相同是指函数名相同，则函数相同，会报重定义错误
//C++语言中，函数相同是指函数的返回值，函数形参列表（参数个数，参数类型，参数顺序），则函数相同，会报重定义错误
//函数重载是指函数名相同，参数列表不同
//注意：函数返回值并不是构成函数重载的条件。即只要函数形参列表（参数个数，参数类型，参数顺序）相同，就会报重定义错误

//函数重载的条件：
//1、在同一个作用域下
//2、函数名称相同
//3、参数个数，参数类型、参数顺序不同
class Person
{
	int myfunc()//成员函数，而不是全局函数
	{

	}
};
int myfunc(int a)
{
	cout << "myfunc(int a)" << endl;
	return 0;
}
int myfunc(int a, int b)
{
	cout << "myfunc(int a, int b)" << endl;
	return 0;
}
//返回值不可以作为函数重载的条件
//void myfunc(int a)
//{
//	cout << "myfunc(int a)" << endl;
//}
//因为当调用myfunc(1)函数时，不用来接收函数的结果是可以的，但会导致二义性

//如果函数重载的话，不要写默认参数，防止调用歧义
int func(int a)
{
	cout << "func1" << endl;
	return 0;
}
int func(int a,int b = 30)
{
	cout << "func2" << endl;
	return 0;
}

//如果函数重载的话，不要初始化占位参数，防止调用歧义
int func(int a, int b, int = 0)
{
	cout << "func3" << endl;
	return 0;
}
void test1()
{
	//这种方式会有歧义，
	//不知道是调用func(int a)、func(int a,int b = 30)
	//func(10);
}
void test2()
{
	///这种方式会有歧义
	//不知道是调用func(int a,int b = 30)、func(int a, int b, int=0)
	//func(10, 20);
}

//注意事项：函数重载中，const的引用可以作为重载条件，注意二义性
void Func(int a)
{
	cout << "Func(int a)" << endl;
}
void Func(int &a)//int &a = 10
{
	cout << "Func(int &a)" << endl;
}
void Func(const int &a)//int temp = 10;int &a = temp
{
	cout << "Func(const int &a)" << endl;
}
void test3()
{
	int a = 10;
	//Func(a);//产生二义性，调用Func(int a)、Func(int &a)
	//Func(10);//产生二义性，调用Func(int a)、Func(const int &a)
}

int printA(double a)
{
	cout << "a = " << a << endl;
	return 0;
}
int printA(int a)
{
	cout << "a = " << a <<  endl;
	return 0;
}
int printA(char ch)
{
	cout << "ch = " << ch << endl;
	return 0;
}
void test4()
{
	printA(3.14f);
	printA(19.00);
	printA(19);
	//注意：
	//1、如果能够匹配的函数，则调用完全匹配的函数
	//2、如果没有完全匹配的函数，则调用隐式转换的函数
	//3、都匹配不到，调用失败。
	printA('a');
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();

	return 0;
}

//注意：string &rfood = food,void eating(string food)和void eating(string &rfood)
//当传入food时，会产生二义性，编译器将对象引用和对象视为同一个函数