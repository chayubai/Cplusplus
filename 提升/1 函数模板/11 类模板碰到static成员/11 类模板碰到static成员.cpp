#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class Person
{
public:
	static int a;//注意：这里a的类型已经写死了
};

//类外初始化
template<class T> int Person<T>::a = 0;

int main()
{
	Person<int> p1,p2;
	Person<char> p3,p4;

	p1.a = 10;
	p3.a = 100;

	cout << p1.a << " " << p2.a << endl;
	cout << p3.a << " " << p4.a << endl;

	return 0;
}
//类模板 ---> 具体的类  --->   static成员属于具体的类
//调用的时候生成具体的函数和具体的类
//Person<int>类的static int a;和Person<char>类的static int a;互不影响
