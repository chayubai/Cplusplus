#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
#include "game2.h"

//1、命名空间用途：可以解决名称冲突问题
void test1()
{
	//具体命名空间下的函数调用
	KingGlory::Attack();
	LOL::Attack();
}

//2、命名空间下可以放：变量、函数（声明）、结构体、类...
namespace A
{
	//命名空间的“}”后不能写";"
	int m_A;
	void func();
	struct Person {};
	class Animal {};
}

//3、命名空间必须要声明在全局作用域下
void test2()
{
	//namespace B {}不可以命名到局部变量作用域下
}

//4、命名空间可以嵌套命名空间
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}
void test3()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "C空间下的m_A = " << B::C::m_A << endl;
}

//5、命名空间是开放的，可以随时给命名空间添加新的成员
namespace B//此命名空间会和上面的命名空间B进行合并
{
	int m_B = 100;
}
void test4()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "B空间下的m_B = " << B::m_B << endl;
}

//6、命名空间是可以匿名的
namespace 
{
	//当写的命名空间是匿名的，相当于写了static int m_C = 1000;static int m_D = 2000;
	//静态变量只能在当前文件内使用
	int m_C = 1000;
	int m_D = 2000;
}
void test5()
{
	//由于是全局作用域下定义的命名空间，对于重名的变量，可以直接访问
	cout << "m_C = " << m_C << endl;
	//::代表作用域，如果前面什么都不写，表示全局作用域
	cout << "m_D = " << ::m_D << endl;
}

//7、命名空间可以取别名
namespace veryLongName
{
	int m_E = 10000;
}
void test6()
{
	cout << veryLongName::m_E << endl;
	namespace vLN = veryLongName;
	cout << vLN::m_E << endl;
}
int main()
{
	//test1();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}