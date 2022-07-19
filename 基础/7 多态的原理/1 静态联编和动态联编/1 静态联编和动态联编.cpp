#define _CRT_SECURE_NO_WARNINGS 1
//多态分为静态多态和动态多态
//1、静态多态：函数重载，运算符重载
//2、动态多态
//区别：函数地址是早绑定（静态联编）还是晚绑定（动态联编）
//即如果函数调用，在编译阶段就可以确定函数的调用地址，并产生代码就是静态联编（编译时多态），就是说地址是早绑定的。
//如果函数的调用地址不能编译不能在编译期间确定，而需要在运行时才能决定，这就属于晚绑定（动态多态，运行时多态）

#include <iostream>
using namespace std;

class Animal
{
public:
	/*void speak()
	{
		cout << "动物在说话" << endl;
	}*/

	//发生多态，父类需要添加virtual
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

//对于有父子关系的两个类 指针或者引用是可以直接转换的
void doSpeak(Animal & animal)//Animal & animal = cat;父类的引用接收子类的对象
{
	animal.speak();//如果地址早就绑定好了，地址早绑定，属于静态联编

	//如果想要调用小猫说话，这个时候函数的地址就不能早就绑定好，而是在运行阶段再去绑定函数地址

	//属于地址晚绑定，也叫动态联编，即在基类的同名函数中用virtual关键字
}

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

void test1()
{
	//父类同名函数不加virtual关键字
	Cat cat;
	doSpeak(cat);
}

void test2()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

//动态多态产生的条件：
//1、先有继承关系
//2、父类中有虚函数，子类重写父类中的虚函数
//3、父类的指针或者引用，指向子类的对象
//注意：子类重写父类的虚函数，可以不加virtual关键字

int main()
{
	//test1();
	test2();
	return 0;
}