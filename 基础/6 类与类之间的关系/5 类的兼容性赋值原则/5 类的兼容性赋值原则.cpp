#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Parent
{
public:
	int a;
	void printP()
	{
		cout << "a = " << this->a << endl;
	}
};
class Child:public Parent
{
public:
	int b;
	void printC()
	{
		cout << "b = " << this->b << endl;
	}
};

void myprint(Parent* pp)
{
	pp->printP();
}

//子类对象可以直接赋值给父类对象
//子类对象可以当作父类对象使用
//子类对象可以直接初始化父类对象
//父类指针可以直接指向子类对象
//父类引用可以直接引用子类对象

int main()
{
#if 0
	//1、子类对象可以直接赋值给父类对象
	Parent p;
	Child c;
	//c = p;//报错，p对象填充不满c对象的空间
	p = c;//c对象所占用的内存空间 >= p对象占用的空间，能够填充p对象所需要的空间

	//2、子类对象可以当作父类对象使用，使用父类中的内容
	c.printP();//c能够当做父类p来使用

	//3、子类对象可以直接初始化父类对象
	Child c1;
	Parent p1 = c1;
#endif
#if 0
	
	//父类引用可以直接引用子类对象
	Parent* pp = NULL;//父类指针
	Child* cp = NULL;//子类指针

	Parent p;//父类对象
	Child c;//子类对象

	//4、父类指针可以直接指向子类对象 - 多态特性发生的必要条件
	//5、父类引用可以直接引用子类对象
	pp = &c;//可以用一个儿子的对象地址给父类指针赋值
	//由于父类指针对父类的内容都能访问，c对象内存布局能够满足父类指针访问的全部需求（可以访问父类所需属性或方法），不会出现访问越界
	
	//cp = &p;//报错
	//由于子类指针对子类的内容都能访问，p对象内存布局不能够满足子类指针访问的全部需求
	//如果这样赋值，cp可以访问子类包括父类中的所有内容，会导致访问越界
#endif

	//第四点的好处：一个父类指针可以接收子类和本身对象的地址
	Parent p;//父类对象
	Child c;//子类对象
	myprint(&p);
	myprint(&c);
	return 0;
}