#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//利用多态实现计算器

//基类
class AbstractCalculator
{
public: 

	//如果父类的虚函数的实现没有意义，可以用纯虚函数代替
	/*virtual int getResult()
	{
		return 0;
	}*/

	//纯虚函数
	//如果一个类中包含了纯虚函数，那么这个类就无法实例化对象，这个类通常称为 抽象类
	//抽象类的子类，也必须要重写父类中的纯虚函数，否则也属于抽象类
	virtual int getResult() = 0;

	int m_A;
	int m_B;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

class Test :public AbstractCalculator
{
	/*int getResult()
	{
		return 0;
	}*/
};
void test1()
{
	//利用多态调用不同的计算器类的功能
	AbstractCalculator* c = new AddCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;

	c = new SubCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;
	c = NULL;
	//由于整个过程中父类的虚函数用不到，可以改为纯虚函数
}

void test2()
{
	//AbstractCalculator abc;//报错：抽象类不能实例化对象
	
	//Test t;//子类继承抽象父类，如果不重写虚函数，也不能实例化对象报错
	
	//解决方法：子类中，对父类虚函数重写
}

#endif

//图形类
//如果一个类，拥有纯虚函数，就称该类为抽象类
//不管该类中有没有成员属性，只有该类有纯虚函数，就是抽象类，抽象类就是不能实例化对象
//如果能实例化，则调用该类的成员函数就是没有意义的，因为该函数没有实现
class Shape
{
public:
	//表示图形类声明一个方法，它是一个纯虚函数，没有函数的实现
	virtual double getArea() = 0;
	//int a;
	//int b;
};

//正方形类
//如果一个普通类继承拥有纯虚函数的类，必须要重写纯虚函数，否则也是一个抽象类
//如果实例化，则调用的成员函数是继承父类过来的，调用也没有意义
class Rect:public Shape
{
public:
	Rect(int a)
	{
		this->a = a;
	}
	virtual double getArea()
	{
		return a * a;
	}
	int a;
};

//圆类
class Circle :public Shape
{
public:
	Circle(int r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		return r * r * 3.14;
	}
	int r;
};
//面向抽象类的架构函数
void printArea(Shape *sp)
{
	sp->getArea();
}

//业务层 面向抽象类编程
int main()
{
	//main中所有使用的变量类型，都是抽象类Shape的类型
	Shape* s = new Rect(10);
	s->getArea();//发生多态

	delete s;

	s = new Circle(2);
	s->getArea();

	delete s;
	s = NULL;

	return 0;
}

//纯虚函数的好处：
//1、抽象类提供接口，子类继承抽象类，只需要根据抽象类的接口实现业务逻辑，与其他类无关，与main函数的使用无关
//2、业务层，main函数的使用，只需知道抽象类的内容，将其他类进行隔离，类和类之间的耦合度低

//如：main函数中有Rect* s1 = new Rect(10);Circle* s2 = new Circle(2);代码，与多个类的关联性很强

//纯虚函数 - 设计模式的原则之一：依赖倒转原则

//main      - 高层业务逻辑层

//Shape: virtual double getArea() = 0;   - 抽象层

//Rect: virtual double getArea(){}     Circle: virtual double getArea(){}   - 实现层

//使得高层业务逻辑层向抽象层靠拢，实现层也向抽象层靠拢