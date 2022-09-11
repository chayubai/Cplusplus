#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//标准输出流对象cout，属于输出流类，输出流类中包含了一些成员函数
//如：flush(),put(),write()

//1、cout.flush()  刷新缓冲区，Linux下有效
void test()
{
	cout << "hello world";//Linux下不会在显示器上显示
	cout.flush();//当手动刷新缓冲区后，才会在显示器上显示
}

//2、cout.put()  向缓冲区写字符
void test1()
{
	cout.put('h').put('e') << endl;
	//向缓冲区写入字符he，然后从屏幕中显示
}

//3、cout.write()  从buf中写num个字节到当前输出流中
void test2()
{
	char buf[] = "hello world";
	cout.write(buf, strlen(buf));
	//将一个空间的字符写入缓冲区，然后从屏幕中显示
}

//案例1、格式输出 - 使用流对象的成员函数
void test3()
{
	int number = 99;
	cout.width(20);//宽度 前面18个空格

	cout.fill('*');//填充，默认空格
	cout.setf(ios::left);//输出数据在本域宽范围内向左对齐
	cout.unsetf(ios::dec);//取消设置十进制

	cout.setf(ios::hex);//设置十六进制
	cout.setf(ios::showbase);//显示基数，十六进制基数为0x开头，八进制基数为0开头
	cout.unsetf(ios::hex);//取消设置十六进制
	cout.setf(ios::oct);//设置八进制

	cout << number << endl;
}

#include <iomanip>//控制符格式化输出头文件

//案例2、格式化输出 - 使用控制符
void test4()
{
	int number = 99;
	cout << setw(20);

	cout << setfill('a');

	cout << setiosflags(ios::showbase);
	cout << setiosflags(ios::left)

	<< hex

	<< number << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}