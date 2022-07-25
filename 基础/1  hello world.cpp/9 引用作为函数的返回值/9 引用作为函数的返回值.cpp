#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
int getA()
{
	int a = 10;
	return a;//int tmp = a;
}
char* getC(int n)
{
	char* p = NULL;
	p = (char*)malloc(n);

	return p;//char* tmp = p;
}
int& getA1()
{
	int a = 10;
	return a;//int &tmp = a;
}
int& getA2()
{
	static int a = 10;//或者在堆区上创建变量
	return a;//int &tmp = a;
}
int main()
{
	int main_a = 0;
	main_a = getA1();//main_a = tmp;//赋值操作，数值拷贝
	cout << "main_a = " << main_a << endl;
#if 0
	//引用作为返回类型，不要返回局部变量的引用，
	int& main_a_re = getA1();//int& main_a_re = tmp;getA1()相当于返回a
	cout << "main_a_re = " << main_a_re << endl;
	cout << "main_a_re = " << main_a_re << endl;
#endif

	int& main_a_re = getA2();
	cout << "main_a_re = " << main_a_re << endl;
	cout << "main_a_re = " << main_a_re << endl;

	//引用如果当函数返回类型的话，函数可以当左值
	getA2() = 1000;//函数返回的是变量的引用

	return 0;
}
#endif

#if 0
//1、函数不要返回局部变量的引用
int& sum()
{
	int num = 10;
	int& rNum = num;
	//注意：rNum是sum()函数中定义的局部变量，生命周期只在函数内有效
	return rNum;

	//函数中的局部变量会被内存回收，供别人使用
	//即不是把内存保存的数据清空，而是内存中你的程序申请的内存不在属于你
}
void test()
{
	int a = 1;
}
int main()
{
	int& result = sum();//result接受了一个局部变量的返回值，此时的rNum是别人的引用
	test();//可理解为rNum是test()中a的空间回收后的的引用
	cout << "result = " << result << endl;
	
	return 0;
}
#endif

int& sum(int &rnum)
{
	rnum++;
	return rnum;
}
void test()
{
	int a = 1;
}
int main()
{
	int num = 10;
	int& result = sum(num);//int& result = rnum,rnum = sum(num) 
	sum(num) = 55;//如果想要让函数不能作左值，在函数返回类型前面加const
	cout << "result = " << result << endl;

	return 0;
}