#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//如果有几个上似而不完全相同的对象,
//有时人们要求在向它们发出同一个消息时，它们的反应各不相同,分别执行不同的操作。
//这种情况就是多态现象。

//例如,甲乙丙3个班都是高二年级,他们有基本相同的属性和行为,
//在同时听到上课铃声的时候,他们会分别走向3个不同的教室,而不会走向同一个教室。
#if 0
class Yuebuqun//岳不群
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}
	void fight()
	{
		cout << "岳不群使出了" << kongfu << "打人" << endl;
	}
	string kongfu;
};
class Linpingzhi:public Yuebuqun//林平之
{
public:
	Linpingzhi(string kongfu):Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	void fight()
	{
		cout << "林平之使出了" << kongfu << "打人" << endl;
	}
};

//在全局提供一个打斗的方法
void fightPeople(Yuebuqun* hero)//类的兼容性赋值原则：父类指针指向子类对象
{
	cout << "调用打人的方法" << endl;
	hero->fight();//当子类和父类的方法名相同，默认调用本类的方法。
	//因为都是Yuebuqun类，都是调用Yuebuqun类的fight
}
int main()
{
	//栈上开辟
	//Yuebuqun xiaoyy("葵花宝典");
	//xiaoyy.fight();

	//堆上开辟
	Yuebuqun* xiaoyy = new Yuebuqun("葵花宝典");
	//xiaoyy->fight();

	Linpingzhi *xiaopp = new Linpingzhi("辟邪剑谱");
	//xiaopp->fight();

	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	//编译器默认做了一个安全的处理，编译器认为不管传递时子类对象还是父类对象
	//如果都统一执行父类的方法，那么是一定可以被执行的。都是调用父类中的方法
	delete xiaoyy;
	delete xiaopp;

	return 0;
}
#endif

class Yuebuqun//岳不群
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}
	virtual void fight()//virtual标识修饰一个成员方法是一个虚函数
	{
		cout << "岳不群使出了" << kongfu << "打人" << endl;
	}
	string kongfu;
};
class Linpingzhi :public Yuebuqun//林平之
{
public:
	Linpingzhi(string kongfu) :Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	//如果父类中有一个虚函数，子类重写这个虚函数，子类同名函数可以不加，也可以加
	void fight()
	{
		cout << "林平之使出了" << kongfu << "打人" << endl;
	}
};
class Linghuchong :public Yuebuqun//令狐冲
{
public:
	Linghuchong(string kongfu) :Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	//如果父类中有一个虚函数，子类重写这个虚函数，子类同名函数可以不加，也可以加
	void fight()
	{
		cout << "令狐冲使出了" << kongfu << "打人" << endl;
	}
};
void fightPeople(Yuebuqun* hero)//类的兼容性赋值原则
{
	cout << "调用打人的方法" << endl;
	hero->fight();//让fight实现多态
	//子类方法名和父类方法名相同
	//如果希望传递进来的是子类。调用子类的fight
	//如果希望传递进来的是父类。调用父类的fight
	//这种行为称为多态
}
//多态发生的三个必要条件
//1、继承
//2、虚函数重写，重写父类同名函数的功能
//3、父类指针或引用指向子类对象

int main()
{
	Yuebuqun* xiaoyy = new Yuebuqun("葵花宝典");

	Linpingzhi* xiaopp = new Linpingzhi("辟邪剑谱");

	Linghuchong* xiaoll = new Linghuchong("独孤九剑");
	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	fightPeople(xiaoll);
	delete xiaoyy;
	delete xiaopp;
	delete xiaoll;

	//virtual关键字在继承中是虚继承，在成员方法中是虚函数
	return 0;
}