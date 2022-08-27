#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//即：类的兼容性原则 
class Animal
{
public:
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
void test1()
{
	Animal* animal = new Animal;
	Cat* cat = (Cat*)animal;

	//由于子类继承父类，因此子类的空间比父类更大

	//当将父类对象的指针强转为 子类类型，此时子类指针本质上只能访问Animal大小的空间，
	//如果子类指针去访问，就可能访问Cat大小的空间，导致越界

	//Animal -> Cat  父转子：向下类型转换  -  不安全
}
void test2()
{
	Cat* cat = new Cat;
	Animal* animal = (Animal*)cat;

	//当将子类对象的指针强转为 父类类型，此时父类指针本质上可以访问Cat大小的空间，
	//如果父类指针去访问，但只能访问Animal大小的空间，因此不会访问越界
	
	//Cat -> Animal  父转子：向上类型转换  -  安全
}

void test3()
{
	//如果发生多态，即父类指针指向子类对象，那么转换永远都是安全的
	Animal* animal = new Cat; //一开始开辟了Cat大小的空间，此时父类指针可以访问Animal大小的空间
	Cat* cat = (Cat*)animal;//此时再当将父类指针强转为子类类型，则子类指针也可以访问Cat大小的空间
}

int main()
{
	test1();
	return 0;
}
