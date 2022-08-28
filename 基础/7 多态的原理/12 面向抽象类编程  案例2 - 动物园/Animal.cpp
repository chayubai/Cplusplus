#include "Animal.h"
Animal::Animal()
{
	cout << "Animal()..." << endl;
}

Animal::~Animal()
{
	cout << "~Animal() ..." << endl;
}

void AnimalVoice(Animal* ap)
{
	cout << "动物开始乱叫了" << endl;
	ap->voice();
	cout << "动物乱叫 结束了" << endl;
}

#if 0
void AnimalVoice(Animal* ap)
{
	cout << "动物开始乱叫了" << endl;
	ap->voice();
	cout << "动物乱叫 结束了" << endl;

	if (ap != NULL)
	{
		delete ap;
		ap = NULL;
	}
}

//main

//Dog dog;AnimalVoice(&dog);//可以不需要释放的代码

AnimalVoice(new Dog);//new Dog匿名对象，堆上开辟的，如果没有释放的代码，就会内存泄露
AnimalVoice(new Cat);

//Animal * dog = new Dog;AnimalVoice(dog);delete dog;如果有释放的代码，会释放两次导致程序崩溃

#endif