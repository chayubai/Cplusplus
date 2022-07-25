#define _CRT_SECURE_NO_WARNINGS 1

//1、this指针的本质是什么？如何在函数中用const修饰this指针
//谁调用，就指向谁对象的常指针。在成员函数后面家const。

//2、友元函数是否有传递性和交换性？举例说明。

//3、实现一个复数类的+=、-=、，前置++、后置++、前置--、后置--、<<、>>等操作符重载

//4、简述操作符重载的规则

//5、课程中自定义数组，实现<<操作符，实现取值操作符[]
//array[i] = 10;   //重载[]
//cout << array << endl;  //重载<<
//cin >> array;  //重载>>
//cout << array[i] << endl;

//array1 == array2;  //重载==
//array1 != array2;  //重载!=

#if 0
#include <iostream>
using namespace std;

struct A
{
	int age;
};
int main()
{
	A a1 = { 10 };
	A a2 = { 20 };

	A a3 = a1 + a2;//也需要重载+操作符
	return 0;
}
#endif
