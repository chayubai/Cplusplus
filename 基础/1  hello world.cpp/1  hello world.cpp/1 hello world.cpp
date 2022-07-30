#define _CRT_SECURE_NO_WARNINGS 1

#if 0  //#if 0 ... #endif 属于条件编译，0 即为参数。是注释符

//C的基本框架
//C文件在cpp中可以兼容
#include <stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}
#endif 

//VS   --  Windows下的编译器集成环境 Ctrl + F7编译 Ctrl+F5运行
//C    --  Linux下的编译器为gcc
//C++  --  Linux下的编译器为g++

#if 0
//C++的基本框架
#include <iostream>
//iostream 是C++的输入输出流的标准库input & output stream，相当于stdio.h

//C++风格中的头文件，不带后缀
#include <cstdio>
#include <stdio.h>
//C中的头文件，都可以转换为C++头文件，取消后缀，在C头文件名上＋c前缀

using namespace std; //这一句很重要，使用命名空间std，可理解为打开一个std房间，房间里可能有一些东西需要在下面用到
//由于一个头文件包含了很多的类，而类中有很多的相同名称的变量
//为了区分不同类下的相同变量名，将变量所属空间进行声明，就代表使用该空间的变量
//由于方便后续代码中要使用命名空间std下的变量，于是告诉编译器使用命名空间std
int main()
{
	//cout 标准输出流对象，就是黑屏幕，即 c out
	cout << "hello world" << endl;//等同于cout << "hello world\n"
	//cout 和endl是在命名空间std中 <<左移操作符，在C++里面实现了功能的改造 - 操作符重载
	printf("hello world\n");
	//cout << "..." 可暂时理解为将字符串流向屏幕这个对象中
	//<< 本身为左移操作符，在C++下具有新的含义，用于在cout后拼接输出的内容
	//类似的如：*可以是乘法操作符，也可以是解引用操作符
	//endl  - end line 刷新缓冲区并且换行，兼容所有平台（windows的回车使用\r\n，Linux下是\n）
	
	system("pause");//请按任意键继续
	return 0;
}
#endif

#if 0
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	//控制cout的显式精度
	//1、fixed强制以小数的方式显式

	//2、setprecision(2)控制显式的精度，保留小数点后两位
	cout << fixed << setprecision(2);

	cout << 123456789.123456789 << endl;
	//3、setw设置显式宽度，单位：字节，默认右对齐，左对齐可以用cout << left;
	//setfill(),填充
	cout << setprecision(2) << setw(12) << 3.140 << endl;

	return 0;
}
#endif
//注意：C++中有char16_t/char32_t类型，即16/32位的char类型,unsigned char无符号字符类型,string字符串类型

#if 0
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//单精度和双精度浮点数的精度问题
	float numFloat = 10 / 3.0;
	double numDouble = 10 / 3.0;
	cout << fixed;
	cout << "numFloat = " << numFloat << endl;
	cout << "numDouble = " << numDouble << endl;

	cout << "numFloat = " << numFloat * 10000 << endl;//失去精度
	cout << "numDouble = " << numDouble * 10000 << endl;

	return 0;
}
#endif

#include <iostream>
using namespace std;
int main()
{
#if 0
	int num;
	char ch1;
	cin >> num;// c in 标准输入 代表键盘 
	cin >> ch1;
	//>> 右移操作符，在C++里面实现了功能的改造 - 操作符重载
	cout << num << endl; 
	cout << ch1 << endl;
#endif

	int num;
	char ch1,ch2,ch3;
	cin >> num;
	cin >> ch1 >> ch2 >> ch3;

	cout << num << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;

	return 0;
}

//面向对象方法：
//1 类的抽象 成员变量和成员函数
//2 实例化   类的对象
//3 面向过程加工的是一个个的函数
//	面向对象加工的是一个个的类

//思考1：类的调用 执行过程的分析  -> 不是一步一步的执行
//思考2：类是一个数据类型 定义一个类，是一个抽象的概念，不会给你分配内存
//用数据类型定义变量，即实例化对象的时候才会分配内存
//思考3：C++是如何处理和区分多个对象调用同一个类的成员函数

#if 0
#include <iostream>
using namespace std;
class circle
{
public:
	double r;//随机值
	double pi = 3.1415926;
	double area = pi * r * r;//这句话area = pi * r * r在创建对象的时候已经执行了，此时area为随机值
};
int main()
{
	circle c1;//类中的成员变量已经执行了
	cout << "请输入半径r：";
	cin >> c1.r;//将键盘中输入的值，赋值给c1的成员变量r

	cout << c1.area << endl;//当执行这句话时，只是从变量所在的内存中拿值，并没有执行pi * r * r
	//因此需要引入成员函数
	return 0;
}
#endif