#define _CRT_SECURE_NO_WARNINGS 1

/*
* //1、
#include <stdio.h>
//C语言全局变量定义，可以重复定义
int g_val;//不初始化，默认为0
int g_val = 20;
int main()
{
	printf("%d\n", g_val);
	return 0;
}
*/

/*
* //2、//返回值,返回类型没有检测。形参类型没有检测，函数调用参数个数没有检测。
#include <stdio.h>
func()
{
	return 10;
}
int gunc(int a)
{
	return 20;
}
int main()
{
	//C语言的函数实现，可以有返回值，而没有返回类型，默认int返回类型
	func();
	//C语言的函数实现，当无参数时，而传入参数时或传入不匹配的数量的参数时，程序可以通过编译
	gunc(10, 20, 30);
	return 0;
}
*/
/*
* //2、
#include <stdio.h>
//返回值,返回类型没有检测。形参类型没有检测，函数调用参数个数没有检测。
getRectS(w, h)
{
	//return w * h;
}
void test1()
{
	printf("%d\n", getRectS(10, 10, 10));
}
int main()
{
	test1();
	return 0;
}
*/

/*
* //3、//类型转换不严格
#include <stdio.h>
int main()
{
	//可以不类型转换
	char *p = malloc(64);

	return 0;
}
*/

/*
* //4、
#if 0
#include <stdio.h>
struct student
{
	int id;
	char name[20];
	//void func();C语言下，结构体不可以有函数（声明）
};
int main()
{
	//C语言结构体变量的定义，要加上关键字struct
	//student s;
	struct student s;
	return 0;
}
*/

/*
* //5、
#include <stdio.h>
int main()
{
	//C语言的真1、假0。非0为真，0为假。
	printf("%d\n", 1 < 2);
	return 0;
}
*/

/*
* //6、
#include <stdio.h>
int main()
{
	//C语言的三目运算符
	int a = 10;
	int b = 20;
	//可以为=左边的表达式叫做左值 可以为=右边的表达式叫做右值
	int c = a < b ? a : b;
	printf("%d\n", c);
	//C语言的三目运算符，返回的是变量的数值，如果想要当左值，必须访问地址
	//a > b ? a : b = 50;//C语言下，返回的是值，20 = 50是错误的
	//(a < b ? a : b) = 50;//C语言下，返回的是值，10 = 50是错误的
	*(a < b ? &a : &b) = 50;
	printf("a = %d\n", a);
	return 0;
}
*/

//const的作用：
//const修饰的变量，不允许变量值修改
//#include <stdio.h>
//int main()
//{
//	const int num = 10;
//	int* p = &num;
//	*p = 20;
//	printf("%d\n", num);
//
//	return 0;
//}
//此时仍能修改，说明*p = 20非法访问了

//如何既让p获取到num的地址，又不让*p修改num的值？
//#include <stdio.h>
//int main()
//{
//	const int num = 10;
//	const int* p = &num;
//	*p = 20;//此时编译报错
//  int n = 100;
/// p = &n;//编译通过
//	printf("%d\n", num);
//
//	return 0;
//}
//总结：
//1、const int* p = &num;const放在指针变量的*左边时，修饰的是*p，即不能通过*p改变num的值
//2、p = &n，p可以改变
//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int* const p = &num;
//	*p = 20;////编译可以通过
//	int n = 100;
//	p = &n;//此时编译报错
//	printf("%d\n", num);
//
//	return 0;
//}
//总结：
//1、int* const p = &num;const放在指针变量的*右边时，修饰的是指针变量p，即不能修改p中地址
//2、*p = 20;*p可以改变
//3、const int* const p = &num;即修饰*p，又修饰p
//最左边表示指针变量是const的，p左边表示指针变量解引用的值是const
//结论：
//const修饰指针变量的时候：
//1. const如果放在 * 的左边，修饰的是指针指向的内容，保证指针指向的内容不能通过指针来改
//变。但是指针变量本身的内容可变。
//2. const如果放在 * 的右边，修饰的是指针变量本身，保证了指针变量的内容不能修改，但是指
//针指向的内容，可以通过指针改变。

/*
* //7、
#include <stdio.h>
const int m_A = 100;//全局变量的cosnt变量，受到常量区保护，运行修改报错
void test1()
{
	//m_A = 200;//直接修改失败
	//int *p = &m_A;
	//*p = 200;//间接修改，运行失败
}
void test2()
{
	const int m_B = 100;//局部变量的const变量，分配到栈上，编译成功
	//m_B = 200;//直接修改失败
	int *p = &m_A;
	*p = 200;//间接修改成功
	printf("%d\n",m_B);

	//int a[m_B];//在C语言下，const是伪常量，不可以初始化数组
}
int main()
{
	//第一个和第二个意思一样，代表一个常整型数，其变量的值不可以修改
	const int a = 10;//const int 修饰的是int
	int const b = 20;//const b 修饰的是b

	const int* c;//const修饰int ，*c的内容不能修改
	//第三个 c是一个指向常整型数的指针（所指向的内存数据不能被修改，但是本身可以修改）
	int* const d;//const修饰d，d是存地址的，所以指向的地址不能修改
	//第四个 d是一个常指针（指针变量不能被修改，但是它所指向的内存空间可以被修改）
	const int* const e;
	//第五个 e是一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）

	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	//C语言，const修饰的变量a的值可以通过指针改变
	const int a = 10;
	//C语言，const修饰的变量a，是假常量
	int array[a] = { 0 };

	int* p = &a;
	*p = 50;
	printf("a = %d\n", a);
	return 0;
}
*/

/*
* //8、
#include <stdio.h>
int main()
{
	int a = 10;
	int i = 0;
	//C语言变量定义，写在顶部，如果随用随定义，一些旧的编译器会报错
	printf("%d\n", a);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}
*/

/*
* //9、
#include <stdio.h>
enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN	//每十个做一个分隔
};
int main()
{
	//C语言枚举类型变量，可以赋值为整型值
	enum season s = 0;
	if (s == 3)
	{
		//...
	}
	return 0;
}
*/

