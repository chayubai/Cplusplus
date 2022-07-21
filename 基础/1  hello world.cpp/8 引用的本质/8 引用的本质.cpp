#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//引用的本质在C++内部实现是一个指针常量
void A(int &ra)
{
	ra = 100;//ref是引用，编译器会转换为*ref = 100
}
int main()
{
	int a = 10;
	int& rNum = a;//自动转化为int* const rNum = &a；这也能说明引用为什么必须初始化
	rNum = 20;//内部发现rNum是引用，自动转换为*rNum = 20;
	A(a);//当a传入函数，发现是引用，转换为int* const ra = &a;故引用传递，实质是还是地址传递
	return 0;
}
#endif

struct typeA
{
	int& a;
};
struct typeB
{
	int* a;
};
void motify1(int* const a)//int *const a = &a
{
	*a = 300;
}
void motify2(int& a)//当我们将引用作为函数参数传递的时候，编译器会替我们将实参取地址给引用
{					//int &a = &a
	a = 300;//对一个引用操作赋值的时候，编译器替我们隐藏*操作
}

//如果我们在去研究引用的时候，你可以将引用当作一个常指针去研究
//当你在使用引用编程的时候，你就把引用理解为变量的别名就可以了。

int main()
{
	cout << "sizeof(struct typeA)" << sizeof(struct typeA) << endl;
	cout << "sizeof(struct typeB)" << sizeof(struct typeB) << endl;
	//引用所占用的大小，跟指针是相等的。
	int a = 10;
	int& re = a;
	//const修饰的变量需要必须初始化，引用也必须初始化
	int* const p = &a;
	//综上两点，引用可能是一个常指针。

	motify1(&a);
	motify2(a);
	return 0;
}
//int arr[10]; arr在常量区，arr指向栈区10个整型的空间
//int& r = a;  r在常量区，r指向栈区a变量的空间