#define _CRT_SECURE_NO_WARNINGS 1

//1、简述C++的命名空间的作用。

//2、定义两个命名空间A和B分别在A中和B中定义变量value，在main函数中将两个空间的value打印出来。

//3、C语言的三目运算符？：，可以当左值么？C++的是否可以？

//4、C++中，下面哪条语句是错误的？为什么？
//(1 < 2 ? a : b) = 100;
//(1 < 2 ? 10 : 20) = 100;

//5、const int a;在C++编译器中是否需要初始化，为什么？
//const int a = 10;
//int *p = (int*)&a;
//*p = 20;
//在C++编译器中能够修改a的值。*p实际上是修改谁的值？

//6、简述引用的特点？

//7、如下写法是否正确
//int &a;

//8、
//void swap1(int &a,int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void swap2(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void swap3(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//swap1,swap2,swap3三个函数哪些是正确的。为什么？

//9、函数返回值如果是引用类型，为什么可以将函数当左值？什么情况函数返回值不能当左值？

//10、以下代码
//int a = 20;
//const int& re_a = a;
//re_a = 30;
//是否正确？为什么？

//11、以下写法是否正确，int &a = 40；如果不正确，如何修改？

#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int& rNum = a;
	int& ra = rNum;
	cout << "ref = " << ra << endl;
	return 0;
}
