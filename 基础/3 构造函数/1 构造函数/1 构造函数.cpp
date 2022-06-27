#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
class Test
{
public:
	void init(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	Test t;
	//...
	//...
	//由于t以上的t未赋初值，导致t存在安全隐患
	
	t.init(10, 20);
	return 0;
}
#endif

//构造函数，类似为手机的初始化设置。析构函数类似手机的清理设置
//如果用户不自定义构造函数和析构函数，系统会默认创建一个构造函数和析构函数的空实现
#include <iostream>
using namespace std;
class Person
{
public://为了方便调用，构造函数和析构函数必须声明在公共控制权限下
	
	//构造函数：
	//1、没有返回类型，也不用写void，没有返回值，没有return语句
	//2、函数名与类名相同
	//3、可以有参数，可以发生重载
	//构造函数由编译器自动调用一次，无需手动调用

	//Test类的构造函数：

	//无参的构造函数
	Person()
	{
		cout << "调用Person()无参构造函数" << endl;
		m_age = 0;
		m_y = 0;
	}

	//作用：在对象被创建出来的时候，同时初始化对象的函数
	Person(int age, int y)
	{
		m_age = age;
		m_y = y;
	}
	void printT()
	{
		cout << "x = " << m_age << " y = " << m_y << endl;
	}
	//构造函数可以重载
	Person(int age)
	{
		cout << "调用Person(int age)有参构造函数" << endl;
		m_age = age;
		m_y = 0;
	}

	//析构函数：
	//1、没有返回类型，也不用写void，没有返回值，没有return语句
	//2、函数名与类名相同，函数名前加~
	//3、不可以有参数，不可以发生重载
	//析构函数由编译器自动调用一次，无需手动调用

	//Test类的析构函数：

	~Person()
	{
		cout << "调用~Person()析构函数" << endl;
		m_age = 0;
		m_y = 0;
	}

	//拷贝构造函数：
	//1、没有返回类型，也不用写void，没有返回值，没有return语句
	//2、函数名与类名相同
	//3、参数为const 类名 &别名,加const，防止把本体修改掉
	Person(const Person&p)
	{
		cout << "调用Person(const Person &p)拷贝函数" << endl;
		m_age = p.m_age;//将对象p的年龄拷贝
	}
	int m_age;
	int m_y;
};

void test1()
{
	Person p;//构造函数由编译器自动调用一次，无需手动调用

	//t开辟在栈上，即栈上的对象被创建的时候，会自动调用无参的构造函数
	//函数执行完后，只要有对象被释放的时候，就会调用析构函数
}

void test2()
{
	//调用类的无参的构造函数
	Person p;
	p.printT();

	//创建对象的同时初始化 - 调用类的有参的构造函数
	Person p1(10, 20);
	p1.printT();

	//可以有参数，可以发生重载
	Person p2(100);
	p2.printT();
}

void test3()
{
	Person p(10);
	Person p2(p);//将对象p的年龄拷贝给对象p2
	cout << "p2的年龄： = " << p2.m_age << endl;
}

void test4()
{
	//Person p();
	//构造函数的调用：
	//1、括号法，如：Person p(10);
	//注意事项一：不要用括号法，调用无参的构造函数，
	//因为编译器会把它当作函数的声明

	//2、显示法
	Person p = Person(10);//创建对象，并用p引用 - 有参构造

	Person p2 = Person(p);//拷贝构造

	Person(10);//匿名对象。特点：当前行执行完后，立即释放，即立即调用析构函数

	cout << "执行到这里，先释放调用析构函数，释放匿名对象 "<< endl << endl;

	//注意事项二：不要用拷贝构造函数，初始化匿名对象
	//Person(p);//报错：p重定义
	//编译器会认为是Person p对象实例化操作，如果已经有p，就相当于重定义
}

void test5()
{
	//3、隐式法
	Person p3 = 10;//Person p3 = Person(10); - 调用有参构造
	Person p4 = p3;//Person p4 = Person(p3); - 调用拷贝构造
}
//构造函数的分类：
//1、按参数分类：无参构造（默认构造）函数 和 有参构造函数
//2、按类型分类：普通构造函数 和 拷贝构造函数
int main()
{
	//test1();

	//test2();

	//test3();

	//test4();

	test5();
	return 0;
}