#define _CRT_SECURE_NO_WARNINGS 1

//类是对对象的抽象
//对象是对类的实例
#if 0
#include <iostream>
using namespace std;

struct Hero
{
	char name[20];
	int sex;
	void printHero()
	{

	}
};
void printHero(struct Hero &h)
{
	cout << "hero" << endl;
	cout << "name" << h.name << endl;
	cout << "sex" << h.sex << endl;
}

class AdvHero
{
public://访问控制权限
	char name[20];
	int sex;
	void printHero()
	{
		cout << "advHero" << endl;
		cout << "name" << name << endl;
		cout << "sex" << sex << endl;
	}
};
int main()
{	
	Hero h;//类型 变量
	//h.name = "gailun";
	strcpy(h.name, "gailun");
	h.sex = 1;
	printHero(h);

	AdvHero advH;//类 对象
	strcpy(advH.name, "ChunBro");
	advH.sex = 1;

	//在C++中，
	//结构体和类都是复杂类型
	//结构体也可以有成员方法
	//类可以有成员变量，也可以有成员函数，类有属性和行为，即变量和函数。
	//结构体就是一个类，结构体和类的唯一区别是，默认访问控制权限不同
	//类是模板，对象是类的实例

	//在C语言中，
	//结构体只有成员变量，没有成员方法
	return 0;
}
#endif

#include <iostream>
using namespace std;

class Animal
{
	//{}以内叫类的内部，以外叫类的外部
public:
	//类中的变量 称为成员属性 成员变量
	//public以下定义的成员变量和成员函数，可以在类的内部和外部都可以访问
	char kind[64];
	char color[20];

	//类中的函数 称为成员函数 成员方法
	void printAnimal()
	{
		cout << "kind" << kind << endl;
		cout << "color" << color << endl;
	}
	void write()
	{
		cout << kind << "开始写字" << endl;
	}
	void run()
	{
		cout << kind << "跑起来" << endl;
	}
private:
	//private以下定义的成员变量和成员函数，只能够在类的内部访问
	
};

int main()
{
	Animal dog;
	//public以下定义的成员变量和成员函数，在类的外部使用
	strcpy(dog.kind, "dog");
	strcpy(dog.color, "yellow");

	Animal sheep;
	strcpy(sheep.kind, "sheep");
	strcpy(sheep.color, "white");

	dog.write();
	sheep.run();
	return 0;
}