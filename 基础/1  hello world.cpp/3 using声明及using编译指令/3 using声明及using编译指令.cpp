#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace KingGlory
{
	int sunwukongId = 1;
}
namespace LOL
{
	int sunwukongId = 10;
}
void test1()
{
	//局部变量优先
	//int sunwukongId = 2;
	
	//1、using声明，说明以后看到sunwukongId是用KingGlory下的
	using KingGlory::sunwukongId;//可以理解为打开这个空间，并使用sunwukongId
	//直接告诉编译器使用KingGlory空间下的sunwukongId
	cout << sunwukongId << endl;
	//当using声明与局部变量优先同时出现就会出错，此时报错“多次声明”
}

void test2()
{
	//局部变量优先
	int sunwukongId = 3;
	//2、using编译指令
	using namespace KingGlory;//理解为打开这个空间，暂时没有使用
	//只告诉编译器打开KingGlory空间，如果后续使用的变量在这空间里面就不会报错
	
	//当using编译指令与局部变量优先同时出现，局部变量优先使用
	cout << sunwukongId << endl;
}

void test3()
{
	using namespace KingGlory;//理解为打开这个空间，暂时没有使用

	using namespace LOL;//理解为打开这个空间，暂时没有使用
	//cout << sunwukongId << endl;//二义性

	//当using编译指令有多个，没有局部变量优先时，如果有重名变量需要加作用域区分
	cout << KingGlory::sunwukongId << endl;
	cout << LOL::sunwukongId << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}