#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//C++有函数重载，会对函数名称进行修饰，导致调用C语义的函数链接失败

#include "test.h"
//C++中调用C语言文件
void test()
{
	show();//在C++源文件中，调用C文件的函数。
	//在C++中有函数重载，会修饰函数名，即修饰为show()为_Z4showv
	//但是show是C文件，无法链接失败

	//解决方法：
	//方法1：
	//告诉编译器用C语言的方式去链接，在头文件加入条件编译代码
	//方法2：不推荐
	//extern "C" void show();告诉编译器，show函数用C语言的方式做链接
	//当需要的函数太多，这种方式不方便
}
int main()
{
	test();
	return 0;
}