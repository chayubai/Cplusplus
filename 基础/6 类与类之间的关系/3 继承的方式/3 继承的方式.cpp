#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//本类中protected和private权限控制的成员变量，是相同的
class Parent
{
public:
	int pub;//在类的内部和外部都可以访问
protected:
	int pro;//在类的内部可以访问，在类的外部不可以访问
private:
	int pri;//在类的内部可以访问，在类的外部不可以访问
};

#if 0
//公有继承
//上面的public是访问控制权限、下面的public是继承方式
//子类中protected和private权限控制的成员变量，是不相同的
class Child:public Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub是父类的public成员，在public继承，类的【内部】可以访问

		cout << "pro" << pro << endl;//pub是父类的protected成员，在public继承，类的【内部】可以访问
									 //此时的pro在孙子类能够访问，说明pro不是private成员，而是protected成员
		//cout << "pri" << pri << endl;//pub是父类的private成员，在public继承，类的【内部】不可以访问
	}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pro << endl;//pub是父类的public成员，在public继承，类的【内部】可以访问
	}

};
#endif

//规则1，只要是父类中的private成员，不管是什么继承方式，子类都访问不了
//规则2，如果子类public继承，子类中的访问控制权限保持不变
//规则3，如果子类protected继承，子类中的父类中出来private成员，其余在子类都是protected
//规则4，如果子类private继承，子类的父类除了private成员，其余在子类都是private成员

#if 0
//保护继承
class Child :protected Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub是父类的public成员，在protected继承，类的【内部】可以访问
									 //pub在类的内部可以访问，类的外部访问不了，类的儿子可以访问
									 //说明pub就是protected成员
		cout << "pro" << pro << endl;//pro是父类的protected成员，在protected继承，类的【内部】可以访问
									 //pro跟pub是一样的性质，pro也是protected成员
		cout << "pri" << pri << endl;//pri是父类的private成员，在protected继承，类的【内部】不可以访问
	}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pub << endl;//pub是父类的public成员，在protected继承，类的【内部】可以访问
		cout << "pro" << pro << endl;//pro是父类的public成员，在protected继承，类的【内部】可以访问
	}
};
#endif

#if 0
//私有继承
class Child :private Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub是父类的public成员，在private继承，类的【内部】可以访问
									 //pub在儿子中访问不了，类的外部访问不了，说明pub在Child中是私有成员
		cout << "pro" << pro << endl;//pro是父类的protected成员，在private继承，类的【内部】可以访问
									 //pro跟pub是一样的性质，pro也是private成员
		cout << "pri" << pri << endl;//pri是父类的private成员，在private继承，类的【内部】不可以访问
}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pub << endl;//pub是父类的public成员，在protected继承，类的【内部】可以访问
		cout << "pro" << pro << endl;//pro是父类的public成员，在protected继承，类的【内部】可以访问
	}
};
#endif

//三看原则：
//1看调用的成员变量是在类的内部还是外部
//2看子类继承方式
//3看当前变量在子类中的变量在父类中的访问控制权限

int main()
{
#if 0
	Child c1;
	c1.func();
	//c1.pub;//pub是父类的公有成员，在public继承，类的【外部】可以访问

	//c1.pro;//pro是父类的保护成员，在public继承，类的【外部】不可以访问
	
	//c1.pri;//pri是父类的私有成员，在public继承，类的【外部】不可以访问
#endif

#if 0
	Child c2;
	c2.func();
	c2.pub;//pub是父类的公有成员，在protected继承，类的【外部】不可以访问

	c2.pro;//pro是父类的保护成员，在protected继承，类的【外部】不可以访问

	c2.pri;//pri是父类的私有成员，在protected继承，类的【外部】不可以访问
#endif

#if 0
	Child c3;
	c3.func();
	c3.pub;//pub是父类的公有成员，在private继承，类的【外部】不可以访问

	c3.pro;//pro是父类的保护成员，在private继承，类的【外部】不可以访问

	c3.pri;//pri是父类的私有成员，在private继承，类的【外部】不可以访问
#endif

	return 0;
}