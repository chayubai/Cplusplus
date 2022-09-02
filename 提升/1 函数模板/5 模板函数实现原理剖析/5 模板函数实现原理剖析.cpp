#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//函数模板
template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板调用" << endl;
}
//模板函数
void myPrint(int a, int b)
{
	cout << "函数模板调用" << endl;
}

void myPrint(double a, double b)
{
	cout << "函数模板调用" << endl;
}

//函数模板     --->      模板函数     --->     被调用
//例如：做手链模子   --->    生产具体的手链    --->    才能戴在手上

//模板函数根据使用情况(被调用的时候)，被生成
void test()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);//生成void myPrint(int a, int b);并调用
	double a = 10;
	double b = 20;
	myPrint(a, b);//生成void myPrint(double a, double b);并调用
	myPrint(a, a);//调用生成的void myPrint(int a, int b);
}

//1、测试：Linux下,index.cpp中编写代码
#include <iostream>
using namespace std;

template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板调用" << endl;
}
int main()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);
	double a = 10;
	double b = 20;
	myPrint(a, b);
	return 0;
}
//2、g++ -S index.cpp -o index.s//跳过预编译

//3、查看vim index.s下的代码

//4、main::
//main函数中的调用，生成了两个函数
//call  _Z5MyAddIiET_S0_S0_
//call  _Z5MyAddIdET_S0_S0_
//查看这两个函数

//5、代码中加入：myPrint(a, a);重新编译
//发现main::多了一次函数调用
//call  _Z5MyAddIiET_S0_S0_
//call  _Z5MyAddIdET_S0_S0_
//call  _Z5MyAddIiET_S0_S0_
//查看还是只有这两个函数，说明只生产了两个函数