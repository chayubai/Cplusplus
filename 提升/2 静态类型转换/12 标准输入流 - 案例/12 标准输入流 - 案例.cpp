#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//案例1、判断用户输入的内容  是字符串  还是数字
void test1()
{
	cout << "请输入一个字符串或者数字：";
	char c = cin.peek();//cin.peek()看缓冲区的第一个字符，由于缓冲区没有数据，会等待输入。

	if (c >= '0' && c <= '9')
	{
		int num;
		cin >> num;//此时由于缓冲区有内容，可以直接将内容放到num中，不需要等待输入
		cout << "你输入的是数字为：" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "你输入的是字符串为：" << buf << endl;
	}
}
void test12()
{
	cout << "请输入一个字符串或者数字：";
	char c = cin.get();//相当于char c;cin.get(c);

	if (c >= '0' && c <= '9')
	{
		cin.putback(c);
		int num;
		cin >> num;//此时由于缓冲区有内容，可以直接将内容放到num中，不需要等待输入
		cout << "你输入的是数字为：" << num << endl;
	}
	else
	{
		cin.putback(c);
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "你输入的是字符串为：" << buf << endl;
	}
}

//案例2、用户输入0~10之间的数字，如果输入有误，重新输入
void test2()
{
	cout << "请输入0~10之间的数字：";
	
	int num;

	while (true)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确，输入的值为：" << num << endl;
			break;
		}
		cout << "输入有误，请重新输入：";

		//当输入一个字符时，程序死循环了

		//cout << cin.fail() << endl;//标志位，0表示缓冲区正常，1表示缓冲区异常

		//由于要求输入int类型的数据，如果输入的数据是int类型，则标志位为0，输入为其他类型，则标志位为1

		//因为当你输入字符的时候，缓冲区的内容就一直存在，就会无限的去取。

		//重置标志位
		cin.clear();
		cin.sync();//清空缓冲区 
		cin.ignore();//如果这儿发现还是清空不了，可以ignore
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}