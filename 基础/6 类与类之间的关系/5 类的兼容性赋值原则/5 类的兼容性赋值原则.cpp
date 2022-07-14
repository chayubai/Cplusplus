#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Parent
{
public:
	int a;
	void printP()
	{

	}
};
class Child:public Parent
{
public:
	int b;
	void printC()
	{

	}
};

void myprint(Parent* pp)
{
	pp->printP();
}
//子类对象可以当作父类对象使用
//子类对象可以直接赋值给父类对象
//子类对象可以直接初始化父类对象
//父类指针可以直接指向子类对象
//父类引用可以直接引用子类对象

int main()
{
#if 0
	Parent p;
	Child c;
	//c = p;
	p = c;//c对象所占用的内存空间 >= p对象占用的空间，能够填充p对象所需要的空间

	c.printP();//c能够当做父类p来使用
#endif
#if 0
	Parent* pp = NULL;//父类指针
	Child* cp = NULL;//子类指针

	Parent p;//父类对象
	Child c;//子类对象

	pp = &c;//pp->b，c内存布局能够满足父类指针的全部需求，可以用一个儿子的对象地址给父类指针赋值
	//cp = &p;//cp->b;
#endif
	Parent p;//父类对象
	Child c;//子类对象
	myprint(&p);
	myprint(&c);
	return 0;
}