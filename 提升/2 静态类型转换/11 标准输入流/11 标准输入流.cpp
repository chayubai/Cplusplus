#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//基类 ； ios - input output stream
//子类：istream、ostream
//孙子类（同时继承两个父类）：iostream

//标准输入流对象cin，属于输入流类，输入流类中包含了一些成员函数
//如：get(),getline(),ignore(),peek(),putback()

//注意：键盘中输入的数据会先放在缓冲区里面。

//1、cin.get(空);
void test1()
{
	
	char c = cin.get();
	//cin.get(),先从缓冲区拿数据，一次只能读取一个字符
	//当缓冲区没有内容时，会等待输入，假设输入as，再回车

	cout << "c = " << c << endl;//a

	c = cin.get();
	cout << "c = " << c << endl;//s

	c = cin.get();
	cout << "c = " << c << endl;//换行符

	c = cin.get();//当缓冲区没有内容时，会继续等待输入
	cout << "c = " << c << endl;
}
//get(参数1)		读取一个字符
void test12()
{
	char ch;
	while ((ch = cin.get()) != EOF)
	{
		cout << ch << endl;
	}
	//Ctrl+ Z结束循环

	char ch2;
	cin.get(ch2);
}
//2、get(参数1，参数2)		读取字符串
void test2()
{
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	//cin.get(buf, 1024),先从缓冲区拿数据,由于缓冲区没有数据，会等待输入。
	//再将输入的数据，从缓冲区中将字符串放入buf中

	cout << buf << endl;

	char c = cin.get();//如果缓冲区没有换行符，会等待输入
	if (c == '\n')
	{
		cout << "换行符遗留在缓冲区" << endl;
	}
	else
	{
		cout << "换行符不在缓冲区" << endl;
	}
	//注意：利用cin.get()获取字符串的时候，换行符会遗留在缓冲区中
}

//3、cin.getline()	读取一行
void test3()
{
	char buf[1024] = { 0 };
	cin.getline(buf, 1024);

	cout << buf << endl;//换行符没有被buf拿走，否则会输出两个换行

	char c = cin.get();//如果缓冲区没有换行符，会等待输入
	if (c == '\n')
	{
		cout << "换行符遗留在缓冲区" << endl;
	}
	else
	{
		cout << "换行符不在缓冲区" << endl;
	}
	//注意：利用cin.getline()获取字符串的时候，换行符既不在buf中，也不在缓冲区中，而是直接扔掉
}

//4、cin.ignore()忽略，从缓冲区取走字符
//ignore(空)        不带参数，默认忽略前一个字符
//ignore(int value) 忽略前value个字符
void test4()
{
	cin.ignore();
	char c = cin.get();
	//cin.ignore(X)忽略缓冲区的前X个字符，由于缓冲区没有数据，会等待输入，再让get()从忽略的后一个字符开始取
	cout << "c = " << c << endl;

	//cin.ignore(10,'\n');//如果提前找到\n，但没有10个字符，会将\n之前的字符忽略掉
}

//5、cin.peek()偷窥，不取走字符
void test5()
{
	char c = cin.peek();//cin.peek()看缓冲区的第一个字符，由于缓冲区没有数据，会等待输入，再让get()开始取
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;
}

//6、cin.putback()放回
void test6()
{
	char c = cin.get();
	cin.putback('m');//将get()获取的一个字符，再将字符'm'放回原位置

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	//test6();
	return 0;
}