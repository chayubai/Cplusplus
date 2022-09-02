#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1、函数模板和普通函数的区别
template<typename T>
T myAdd1(T a, T b)
{
	return a + b;
}
int myAdd2(int a, int b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	myAdd1(a, b);
	myAdd2(a, b);

	char c = 'a';
	//myAdd1(a, c);//报错，类型不一致。如果使用自动类型推导，是不可以发生隐式类型转换的

	myAdd1<int>(a, c);//显式指定类型，注意这里的函数模板不是引用类型，char可以转为int

	myAdd2(a, c);//普通函数可以发生隐式类型转换
}

//2、函数模板和普通函数的调用规则
template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板myPrint(T a,T b)调用" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "函数模板myPrint(T a, T b, T c)调用" << endl;
}

void myPrint(int a,int b)
{
	cout << "普通函数调用" << endl;
}
//以上三个函数互为重载函数
void test2()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);

	//1、如果函数模板和普通函数都可以调用，优先调用普通函数，因为调用普通函数的效率更高

	//当注释掉普通函数，只有普通函数的实现，此时函数模板和普通函数都可以调用，但还是优先调用普通函数，此时会报错

	//2、如果想强制调用函数模板，可以使用空模板参数列表

	//通过调试可知道，是调用普通函数还是模板函数

}

void test3()
{
	int a = 10;
	int b = 20;

	//2、如果想强制调用函数模板，可以使用空模板参数列表
	myPrint<>(a, b);//注释普通函数的实现部分，可以运行成功

	//当取消注释普通函数的实现部分，由于使用空模板参数列表，因此还是强制调用函数模板
}

void test4()
{
	int a = 10;
	int b = 20;
	
	//3、函数模板也可以发生重载
	myPrint(a, b, 10);
}

void test5()
{
	char a = 'a';
	char b = 'b';
	myPrint(a, b);

	//4、如果函数模板能产生更好的匹配，优先使用函数模板
	//由于 myPrint(int a,int b)调用需要隐式转换，调用普通函数的效率低，因此调用函数模板更好
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