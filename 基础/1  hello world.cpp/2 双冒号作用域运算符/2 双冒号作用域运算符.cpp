#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int k = 1000;
int main()
{
	int k = 10;//局部变量优先
	cout << "局部k = " << k << endl;

	//::代表作用域，如果前面什么都不写，表示全局作用域
	//全局变量的作用域
	cout << "全局k = " << ::k << endl;
	//使用std作用域下的cout
	std::cout << "全局k = " << ::k << endl;
	return 0;
}