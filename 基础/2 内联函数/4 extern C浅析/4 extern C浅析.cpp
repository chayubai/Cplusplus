#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "test.h"
//C++中调用C语言文件
void test()
{
	show();//在C++源文件中，调用C文件的函数。
	//在C++中有函数重载，会修饰函数名，即修饰为show()为_Z4showv
	//但是show是C文件，无法链接失败

	//解决方法：告诉编译器用C语言的方式去链接，在头文件加入条件编译代码
}
int main()
{
	test();
	return 0;
}