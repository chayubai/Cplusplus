#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	//输入文件：键盘。输出文件：显示器

	//cout是全局中的输出流对象，默认和显示器绑定好了，默认输出到显示器
	//cin是全局中的输入流对象，默认和键盘绑定好了，默认输入从键盘读取数据

	//cerr标准错误，默认输出数据到显示器，没有缓冲区
	//clog标准日志，默认输出数据到显示器，有缓冲区

	//缓冲区，就是一块内存
	//cin >> a;程序会从缓冲区中读取数据，如果缓冲区为空，就会阻塞，等待键盘输入

	//cout << "hello world";
	//在Linux下是不会显示的，只有加了endl后，刷新缓冲区，换行后才会显示
	return 0;
}