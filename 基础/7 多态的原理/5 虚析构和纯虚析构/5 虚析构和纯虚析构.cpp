#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "调用Animal构造函数" << endl;
	}

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	/*~Animal()
	{
		cout << "调用Animal构造函数" << endl;
	}*/

	//当子类发生多态时，如果子类中有指向堆区的属性，那么要利用虚析构，在delete释放的时候，调用子类的析构函数
	//否则不会调用子类的析构，导致释放不干净
	/*virtual ~Animal()
	{
		cout << "调用Animal构造函数" << endl;
	}*/
	
	virtual ~Animal() = 0;//如果直接这样写，是会编译失败的
	//注意：纯虚析构 需要有声明，也需要有实现，
	//实现的目的是：如果本类中也有堆上开辟的变量，也是需要析构的，即用来对自身类内的堆上的空间，进行释放
	//在类内声明，在类外实现

	//注意：纯虚函数可以只要声明，但纯虚析构 需要有声明，也需要有实现

	//如果一个类中，有了纯虚析构函数，那种这个类也属于抽象类，无法实例化对象
	//虚函数，继承后，子类需要重写虚函数，否则子类无法实例化，而虚析构函数，是无法继承，因此不需要重写
	
	//注意：子类继承抽象类，需重写虚函数，否则也不能实例化对象
};

//纯虚析构类外实现，加作用域
Animal::~Animal()
{
	cout << "调用Animal纯虚析构函数" << endl;
}

class Cat :public Animal
{
public:
	Cat(const char* name)
	{
		//this->m_name = name;//这样赋值可以？不可以，调用默认=操作符函数，导致指向同一块空间
		//使得name和对象的属性m_name的生命周期相同，如果name结束了，会影响该类对象m_name
		//如：char* name = "Tom";Cat* c = new Cat(name);c.speak();
		//又如：char *name = new char[64];strcpy(name,"zhangsan");Cat* c = new Cat(name);delete[] name;c.speak();;
		cout << "调用Cat构造函数" << endl;
		this->m_name = new char[strlen(name) + 1];//开辟数组new char[]
		strcpy(this->m_name, name);
	}
	virtual void speak()
	{
		cout <<this->m_name << "小猫在说话" << endl;
	}
	~Cat()
	{
		if (this->m_name)
		{
			cout << "调用Cat析构函数" << endl;
			delete[] this->m_name;
			this->m_name = NULL;
		}
	}
	char* m_name;
};
void test1()
{
	Animal* animal = new Cat("Tom");//父类指针指向子类对象

	//实例化子类对象，会先调用父类的构造，再调用子类对象，然后先析构子类，再析构父类
	animal->speak();
	//栈上的对象会自动调用析构释放，堆上的对象只有手动delete，才会触发析构调用
	//注意：如果你没有释放animal指向的空间，则不会调用析构函数

	delete animal;

	//此时发现，只调用了父类的析构函数，没有调用子类的析构函数
	//原因是因为： delete animal;而animal是Animal类的对象，只会触发 Animal的析构
	//让父类的析构函数也发生多态

	//如何解决？-虚析构函数
	//父类用virtual关键字修饰析构函数
}

void test2()
{
	//Animal a;//在Animal中有了纯虚析构，也是抽象类，无法实例化
}
int main()
{
	test1();
	return 0;
}