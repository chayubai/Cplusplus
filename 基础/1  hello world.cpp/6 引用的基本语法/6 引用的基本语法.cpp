#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;

void test1()
{
	int a = 10;
	//1、引用的基本语法： 类型 &别名 = 原名
	int& re = a;//int& 使用引用数据类型，re是a的别名
	re = 50;//将a的空间的值改为了50
	cout << "a = " << a << endl;
	cout << "b = " << re << endl;
}

void test2()
{
	//2、
	int a = 10;
	//int& re2;//引用必须初始化，类似const int a;a必须初始化

	int& ra = a;
	//引用一旦初始化后，就不可以引向其他变量

	int b = 200;
	//&ra = b;//会报错，这里编译器相当于取地址ra 即取地址a，将b赋值一个地址

	ra = b;//此行不是给b取别名为ra，而是将b赋值为ra，即ra = a = b

	cout << "a = " << a << endl;//200
	cout << "b = " << ra << endl;//200
	cout << "c = " << b << endl;//200
}

void test3()
{
	//3、对数组建立引用
	int arr[10];
	int(&rArr)[10] = arr;//（1）直接建立引用
	for (int i = 0; i < 10; i++)
	{
		rArr[i] = 100 + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << rArr[i] << " ";
	}
	//（2）先定义出数组类型，再通过类型定义引用
	typedef int(ARRAY_TYPE)[10];
	//类型 &别名 = 原名
	ARRAY_TYPE& rArr2 = arr;//别名可以取多个
	for (int i = 0; i < 10; i++)
	{
		cout << rArr2[i] << " ";
	}
}

void test4()
{
	int a = 10;
	int& rNum = a;//a的别名为rNum
	int& ra = rNum;//rNum的别名为ra
	cout << "ref = " << ra << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	int* p = &a;
	*p = 30;//a

	p = &b;
	*p = 60;//b

	/*
	1、引用没有定义，是一种关系型声明。声明它和原有某一变量的关系。
	故而类型域原类型保持一致，且不分配内存。域被引用的变量有相同的地址。
	2、声明的时候必须初始化，一经声明，不可变更。
	3、可对引用，再次引用。多次引用的结果，是某一变量具有多个别名
	4、&符号前面有数据类型时，是引用。其它皆为取地址。
	*/
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main()
{
	//不能直接引用常量
	//double& d = 12.3;

	//指向常量的引用
	const double& d = 12.3;

	return 0;
}