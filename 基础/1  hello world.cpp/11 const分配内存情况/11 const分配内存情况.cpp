#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//extern编译器也会给const变量分配内存
//1、对const变量取地址，变量放在符号表中，会分配临时内存
void test1()
{
	const int a = 10;
	int* p = (int*)&a;//会分配临时内存
}

//2、使用普通变量，初始化const变量
void test2()
{
	int a = 10;
	const int b = a;//会分配内存
	int* p = (int*)&a;
	*p = 100;//修改成功
	cout << "b = " << b << endl;
}

#include <string>
//3、对于自定义数据类型，加const也会分配内存
struct Person
{
	string m_Name;//包含头文件#include <string>
	int m_Age;
};
void test3()
{
	const Person p;
	//p.m_Age = 10;直接修改失败
	
	//间接通过指针修改，成功
	Person* pp = (Person*)&p;
	(*pp).m_Name = "Tom";
	pp->m_Age = 10;
	cout << "姓名：" << p.m_Name << ",年龄：" << p.m_Age << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	return 0;
}