#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//类模板基本语法：template<class T1,class T2,...>下面紧跟着类的定义，即：只对第一个类有效
//T,T2数据类型名
template<class NAMETYPE,class AGETYPE = int>//函数模板也可以有template<class T1,class T2,...>
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->name << "，年龄：" << this->age << endl;
	}
	NAMETYPE name;
	AGETYPE age;
};

void test1()
{
	//类模板和函数模板的区别：
	
	//1、类模板不可以使用自动类型推导，只能用显式指定类型
	//Person p1("孙悟空", 100);//使用自动类型推导会报错
	//由于可能推导的不一致，如："孙悟空"是char*类型，而给的可能是string类型

	Person<string, int> p1("孙悟空", 100);//显式指定类型。也要包含#include <string>头文件
	p1.showPerson();
}

void test2()
{
	//类模板和函数模板的区别：

	//2、类模板中可以有默认参数template<class NAMETYPE,class AGETYPE = int>，使用的时候模板参数列表可以不传类型
	Person<string> p2("孙悟空", 100);
	p2.showPerson();
}
int main()
{
	//test1();
	test2();
	return 0;
}