#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class Person1
{
public:
	void showPerson1()
	{
		cout << "showPerson1调用"<< endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "showPerson2调用" << endl;
	}
};

//类模板中的成员函数，并不是一开始创建的，而是在运行阶段确定出T的数据类型才去创建的
template<class T>
class myClass
{
public:

	void func1()
	{
		obj.showPerson1();//Person1类型的对象
	}
	void func2()
	{
		obj.showPerson2();//Person2类型的对象
	}

	T obj;//由于T的类型无法确定，myClass类下的成员函数无法在编译阶段创建
};

void test()
{
	myClass<Person1> p1;//创建一个myClass类的对象，显式指定T的类型为Person1
	//p1的类型是myClass，func1和func2是p1对象的成员
	p1.func1();//运行时，func1才被创建
	//p1.func2();//当调用func2时，被创建。报错，由于func2中Person1类中没有showPerson2成员函数，无法调用

	//即：类模板中的成员函数fun1和func2是在运行时被创建，能不能创建成功，取决于对象的类是否有该成员函数
	//注意：普通类中的成员函数是编译阶段一开始就被创建。模板类中的成员函数是调用是才被创建
}
int main()
{
	test();
	return 0;
}