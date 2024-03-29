#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
class Base1
{
public:
	Base1()
	{
		cout << "调用Base1构造函数" << endl;
	}
	~Base1()
	{
		cout << "调用Base1析构函数" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "调用Other构造函数" << endl;
	}
	~Other()
	{
		cout << "调用Other析构函数" << endl;
	}
};

//class Other;//提前声明了为什么还会报错？解决方法：将该类的定义放在使用该类的类的上面

class Son1 :public Base1
{
public:
	Son1()
	{
		cout << "调用Son1构造函数" << endl;
	}
	~Son1()
	{
		cout << "调用Son1析构函数" << endl;
	}
	Other other;//当有其他类作为的成员属性，是先调用类的构造函数，再调用本类的构造函数

	//创建son1的对象时，先构造other类，在构造son1类
	
	//创建son1的对象时，先调用父类默认构造Base1()？还是先调用其他类的默认构造Other()？
};

#if 0
class Other//由于这个类是后定义的，前面使用该类需要声明
{
public:
	Other()
	{
		cout << "调用Other构造函数" << endl;
	}
	~Other()
	{
		cout << "调用Other析构函数" << endl;
	}
};
#endif

class Base2
{
public:
	//如果父类没有合适的默认构造，那么子类可以利用初始化列表的方式显示的调用父类的其他构造函数
	Base2(int a)
	{
		this->m_A = a;
		cout << "调用Base2构造函数" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	/*Son2()//报错：Base2不存在默认构造
	{
		cout << "调用Son2构造函数" << endl;
	}*/
	
	//当父类写了有参构造时，就没有默认构造函数
	//当子类继承父类时，会先调用父类的默认构造函数，但发现没有父类的默认构造函数，因此会报错：不存在默认构造函数
	
	//如何解决？
	//1、父类显式提供自定义的无参构造函数

	//2、利用初始化列表语法，显式调用父类中的其他构造函数
	/*Son2() :Base2(10)//写死了
	{
		cout << "调用Son2构造函数" << endl;
	}*/
	Son2(int a) :Base2(a)//将a传给父类中的有参构造，初始化m_A
	{
		cout << "调用Son2构造函数" << endl;
	}
	//只有父类自己知道如何构造和析构自己的属性，而子类不知道
};

void test1()
{
	Son1 s;//先调用父类的默认构造，再调用子类的默认构造，析构的顺序与构造相反
}

void test2()
{
	//当对象有其他类的对象作为成员函数
	Son1 s;//先调用父类构造，再调用其他类成员的构造，再调用自身构造，析构的顺序与构造相反
}

void test3()
{
	Son2 s(100);
	cout << s.m_A << endl;
}

//注意：父类中，构造（包括默认构造，有参构造...）、析构、拷贝构造、operator=，是不会被子类继承下去的
//因为只有父类自己知道如何构造和析构自己的属性，而子类不知道
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}