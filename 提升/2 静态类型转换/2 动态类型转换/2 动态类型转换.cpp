#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//动态转换
//不允许内置数据类型转换，因为存在转换精度丢失等不安全
//允许父子之间指针或引用。主要用于类层次间的上行转换和下行转换
//1、在类层次间进行上行转换时，动态类型转换和静态类型转换的效果是一样的
//2、在进行下行转换时，动态类型转换具有类型检查的功能，比静态类型转换更安全
//3、如果有不安全的转换，是无法动态类型转换的，即可以子类转父类
//4、如果发生多态，总是安全，可以成功

//动态类型转换，关键字dynamic_cast
void test1()
{
	//不允许内置数据类型之间转换
	char a = 'a';
	//double d = dynamic_cast<double>(a);//报错
}

//class Base {};
//class Son :public Base {};

//子类和父类发生多态
class Base { virtual void func() {} };
class Son :public Base { virtual void func() {} };
class Other {};

void test2()
{
	Base* base = NULL;
	Son* son = NULL;

	//语法： dynamic_cast<目标类型>(原对象/变量)
	//将base转为Son* 父转子 向下类型转换，不安全
	//Son* s = dynamic_cast<Son*>(base);//报错：操作数必须包含多态类类型

	//将son转为Base* 子转父 向上类型转换， 安全
	Base* b = dynamic_cast<Base*>(son);

	//将base转为Other*
	//Other* o = dynamic_cast<Other*>(base);//报错：无法转换

}

void test3()
{
	//Base* base = NULL;
	//Son* son = NULL;
	//将base转为Son* 父转子 向下类型转换，不安全
	//Son* s = dynamic_cast<Son*>(base);//操作数必须包含多态类类型

	//如何发生多态？ - 虚函数，子类重写父类虚函数，父类指针/引用指向子类对象
	Base* base = new Son;//父类指针指向子类对象
	//将base转为Son* 如果发生多态，转换总是安全的
	Son* s = dynamic_cast<Son*>(base);//因为new的时候是子类的空间
}

void test4()
{
	Base base;
	Son son;
	Base& bs = base;
	Son& sn = son;

	//将bs转为Son&  父转子 向下类型转换，不安全
	Son& s = dynamic_cast<Son&>(bs);

	//将sn转为Base& 子转父 向上类型转换， 安全
	Base& b = dynamic_cast<Base&>(sn);

	//将bs转为Other&
	//Other& o = dynamic_cast<Other&>(bs);//报错：转换无效

	//static_cast是父子之间的指针或者引用可以转换
}

int main()
{
	test1();
	return 0;
}