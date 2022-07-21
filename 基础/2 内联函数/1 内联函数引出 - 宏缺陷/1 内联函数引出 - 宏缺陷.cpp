#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//宏缺陷1：必须要加括号保证运算完整
//#define ADD(x,y) x+y
#define ADD(x,y) ((x)+(y))
void test1()
{
	int a = 10;
	int b = 20;
	int ret = ADD(a, b) * 20;
	cout << ret << endl;
}

//宏缺陷2：即使加了括号，有些运算依然与预期不符
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

//宏缺陷3、没有作用域

void test2()
{
	int a = 10;
	int b = 20;
	int ret = MAX(++a, b);//预期ret = 11，结果为12
	//(((++a) > (b)) ? (++a) : (b))
	//((11) > (20) ? (12) : 20)

	cout << "ret = " << ret << endl;
}
//普通函数不会出现与预期不符的问题
void Max(int a, int b)
{
	int ret = a < b ? a : b;

	cout << "ret = " << ret << endl;
}
void test3()
{
	int a = 10;
	int b = 20;
	Max(++a,b);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}