#define _CRT_SECURE_NO_WARNINGS 1
//1、重载：同一作用域的同名函数
//a.同一个作用域
//b.参数个数，参数顺序，参数类型不同
//c.和函数返回值，没有关系
//d.const也可以作为重载条件   //do(const Teacher& t){}  do(Teacher& t){}

//2、重定义（隐藏）
//a.有继承
//b.子类（派生类）重新定义父类（基类）的同名成员（非virtual函数）
//c.隐藏父类所有重载版本的函数，如果需要调用父类这些函数，需要加作用域

//3、重写（覆盖、多态）
//a.有继承
//b.子类（派生类）重写父类（基类）的virtual函数
//c.函数返回值，函数名字，函数参数，必须和基类的虚函数一致

class A
{
public:
	//同一作用域下，func1函数重载
	void func1() {}
	void func1(int a) {}
	void func1(int a,int b) {}
	void func2() {}
	virtual void func3() {}

};
class B :public A
{
public:
	//重定义基类的func2,隐藏了基类的func2方法
	void func2() {}
	//重写基类的func3函数，也可以覆盖基类func3
	virtual void func3() {}
};