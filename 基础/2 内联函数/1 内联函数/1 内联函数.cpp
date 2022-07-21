#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//频繁调用普通函数，防止频繁的压栈和出栈，开销
//void printAB(int a, int b)
//{
//	cout << "a = " << a << ",b = " << b << endl;
//}

//内联函数：防止频繁的压栈和出栈，开销
//1、可以解决宏的缺陷，本身是一个函数，具有普通函数的特点
//2、减少函数调用的开销，以空间换时间，带来宏的优势，在适当时候做展开
inline void printAB(int a, int b)
{
	cout << "a = " << a << ",b = " << b << endl;
}
//3、函数的声明和实现必须同时加上关键字inline才算内联函数，
//如果函数声明了inline，而函数实现没有写inline，则会按普通函数处理

//4、类内部的成员函数，在函数前都隐式的加了关键字inline
int main()
{
	int a = 10;
	int b = 20;

	for (int i = 0; i < 1000; i++)
	{
		a++;
		b++;
		printAB(a, b);//由于频繁的压栈和出栈，将使用的函数代码替换函数调用，减少开销
		
		//调用printAB(a, b);相当于以下代码展开，类似与宏函数-宏替换
		//{
		//	cout << "a = " << a << ",b = " << b << endl;
		//}
	}
	return 0;
}

//注意：以下情况编译器可能不会将内联函数进行内联编译
//1、不能存在任何形式的循环语句
//2、不能存在过多的条件判断语句
//3、函数体不能过于庞大
//4、不能对函数进行取址操作