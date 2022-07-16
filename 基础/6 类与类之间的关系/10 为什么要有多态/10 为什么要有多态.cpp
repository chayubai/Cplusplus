#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
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
void fightPeople(Yuebuqun* hero)//类的兼容性赋值原则
{
	cout << "调用打人的方法" << endl;
	hero->fight();
}
int main()
{
	//Yuebuqun xiaoyy("葵花宝典");
	//xiaoyy.fight();

	Yuebuqun* xiaoyy = new Yuebuqun("葵花宝典");
	//xiaoyy->fight();

	Linpingzhi *xiaopp = new Linpingzhi("辟邪剑谱");
	//xiaopp->fight();

	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	//编译器默认做了一个安全的处理，编译器认为不管传递时子类对象还是父类对象
	//如果统一执行父类的方法，那么是一定可以被执行的。
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
	virtual void fight()//标识修饰一个成员方法是一个虚函数
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
	//如果父类中有一个虚函数，子类重写这个虚函数
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
	//如果父类中有一个虚函数，子类重写这个虚函数
	void fight()
	{
		cout << "令狐冲使出了" << kongfu << "打人" << endl;
	}
};
//在全局提供一个打斗的方法
void fightPeople(Yuebuqun* hero)//类的兼容性赋值原则
{
	cout << "调用打人的方法" << endl;
	hero->fight();
	//子类方法名和父类方法名相同
	//如果希望传递进来的是子类。调用子类的fight
	//如果希望传递进来的是父类。调用父类的fight
	//这种行为称为多态
}
//多态发生的三个必要条件
//1、继承
//2、虚函数重写
//3、父类指针或引用指向子类对象

int main()
{
	//Yuebuqun xiaoyy("葵花宝典");
	//xiaoyy.fight();

	Yuebuqun* xiaoyy = new Yuebuqun("葵花宝典");
	//xiaoyy->fight();

	Linpingzhi* xiaopp = new Linpingzhi("辟邪剑谱");
	//xiaopp->fight();

	Linghuchong* xiaoll = new Linghuchong("独孤九剑");
	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	fightPeople(xiaoll);
	delete xiaoyy;
	delete xiaopp;
	delete xiaoll;


	return 0;
}