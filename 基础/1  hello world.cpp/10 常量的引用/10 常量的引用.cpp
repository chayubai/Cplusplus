#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void test1()
{
	//string &str = "hello";//不可以直接对常量进行引用
	//int &ref = 10;//不可以直接对常量进行引用，引用了不合法的内存
	const int& ref = 10;//加了const之后，相当于写成，int temp = 10;const int &ref = temp;

	//const int *ref = &temp
	
	//int* p = &ref;//报错，需要强转，注意观察报错情况:const int *转换为int*
	int* p = (int*)&ref;//const int *ref = &temp，通过指针可以修改
	*p = 10000;
	cout << ref << endl;
}

//常量引用的使用场景,const修饰函数中的形参，防止误操作
void show1(int &a)
{
	a = 10000;//由于这样会导致直接修改了外边a的结果
	cout << "a = " << a << endl;
}
void show2(const int& a)
{
	//a = 10000;//当加上const修饰形参时，此时直接修改它这一行会报错，防止了误操作
	cout << "a = " << a << endl;
}
void test2()
{
	int a = 100;
	show1(a);//只用于显示功能
	cout << "外部的a = " << a << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}