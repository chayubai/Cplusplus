#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//const 修饰引用，一般和const修饰指针的用途是一样的。都是作为函数参数
//保证该参数是只读的，在函数内部改变不了外部的值
void Print(const int& re)
{
	cout << "re = " << re << endl;
}
int main()
{
	const int a = 10;
	//int &re = a;//报错
	//1、如果想对一个常量进行引用，必须是一个const引用
	const int& re1 = a;

	int b = 20;
	//2、相反如果一个普通变量，用一个const引用接收是可以的。
	const int& re2 = b;
	cout << "b = " << b << endl;
	cout << "re2 = " << b << endl;
	b = 300;//re2 = 300;//这种是错误的
	cout << "b = " << b << endl;
	cout << "re2 = " << b << endl;

	return 0;
}
#endif

#if 0
void Show(const int& num)//解决方法：在参数中使用const
{
	//只希望这个函数的显示数据的功能，而不禁止修改它的值
	cout << num << endl;

	//解决方法：在参数中使用const
	//num1 = 200;//此时修改num的值就会发生报错
} 
int main()
{
	int num = 10;
	Show(num);

	return 0;
}
#endif

#include <string>
string chatTo(const string &toName, const string &content)
{
	string msg = "你悄悄对【" + toName + "】说：" + content;
	return msg;
}
int main()
{
	cout << "请输入要对谁发送信息：";
	string toName, content;
	getline(cin, toName);
	cout << "请输入要发送的信息：";
	getline(cin, content);
	string chatMsg = chatTo(toName, content);
	cout << chatMsg << endl;
	return 0;
}