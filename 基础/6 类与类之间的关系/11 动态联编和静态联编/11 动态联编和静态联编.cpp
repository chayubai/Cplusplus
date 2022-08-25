#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{ 
	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;

	if (a > 10)//迟绑定
	{
		cout << "a = " << a << endl;
	}
	else
	{
		cout << "b = " << b << endl;
	}

	//静态联编，例如：程序从上至下依次执行，不管程序如何，cout << "a = " << a << endl;一定会执行
	//动态联编，例如：判断语句，会根据不同的情况选择执行哪一条语句。又如：多态的实现
	return 0;
}