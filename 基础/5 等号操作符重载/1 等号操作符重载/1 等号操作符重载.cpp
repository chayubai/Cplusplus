#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std; 

//编译器默认给一个类4个函数，默认构造函数，析构函数，拷贝构造函数（浅拷贝-简单的值拷贝），operator=()（浅拷贝-简单的值拷贝）
//operator=()和拷贝构造函数都可以实现内置类型或者自定义类型的运算，但是是浅拷贝，可能会导致重复释放空一块空间
//因此需要对等号操作符和拷贝构造函数都需要进行深拷贝重载实现

#if 0
class Person
{
public:
	Person(const char* name, int age)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//成员函数实现：重载=操作符
	//深拷贝动作
	//1、返回类型为void,参数const，防止内部通过p对私有成员的修改
	/*void operator=(const Person& p)
	{
		//先将原来的p2的内容释放干净
		//即先判断原来堆区释放是否有内容，如果有先释放
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		//再深拷贝,将p1的内容赋值给p2中
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}*/

	//2、返回类型为Person&,参数const，防止内部通过p对私有成员的修改
	Person& operator=(const Person& p)
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;

		return *this;
	}

	//拷贝构造函数重写
	Person(const Person &p)
	{
		//拷贝构造函数，是不需要判断原对象是否有内容，因为本身就没有内容
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	~Person()
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}
	char* m_Name;
	int m_Age;
};
void test1()
{
	Person p1("Tom",10);

	//Person p2 = p1;//此处是调用默认拷贝构造函数，即Person p2(p1);

	Person p2("Jerry",19);
	p2 = p1;//此处是调用默认operator=()，调用析构时，重复释放同一块空间，导致程序崩溃
	//因此，重载 = 操作符，调用本质，p2.operator=(p1)

	cout << "p2.name = "<<p2.m_Name << ",p2.age = " << p2.m_Age << endl;
}

void test2()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

	//对于自定义数据类型可以连=操作
	Person p3("",20);
	p3 = p2 = p1;//连等操作，由于返回类型为void，导致p2 = p1时返回void，空再赋值给p3导致报错
	
	//因此返回类型为引用，p2 = p1返回p2的本体,p3 = p2返回p3的本体

	cout << "p3.name = " << p3.m_Name << ",p3.age = " << p3.m_Age << endl;
}

void test3()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

	Person p3("", 20);
	p3 = p2 = p1;

	Person p4 = p3;//默认调用拷贝构造Person p4(p3);浅拷贝，调用析构时，重复释放同一块空间，会导致程序崩溃
	//调用本质：p4.Person(p3)
	//因此也要需要重写拷贝构造函数，实现深拷贝

	cout << "p4.name = " << p4.m_Name << ",p4.age = " << p4.m_Age << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
#endif

class Student
{
public:
	Student()
	{
		this->id = 0;
		this->name = NULL;
	}
	Student(int id, const char *name)
	{
		this->id = id;
		//如果使用this->name = name;使用常量初始化，不会导致问题
		//如：Student s(1,"123123");
		
		//如果使用this->name = name;初始化，以下方法的定义，会导致问题
		//char name[64] = "zhangsan";Student s(1,name);
		//char *name = new char[64];strcpy(name,"zhangsan");Student s1(1,name);delete[] name;s1.printS();

		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	Student(const Student &another)
	{
		this->id = another.id;

		//深拷贝
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);
	}
	~Student()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}
	Student& operator=(const Student &another)
	{
		//防止自身赋值
		if (this == &another)//&another取地址
		{
			return *this;
		}
		//先将自身额外开辟的空间回收掉
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
		//执行深拷贝
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);

		return *this;
	}
	void printS()
	{
		cout << name << endl;
	}
private:
	int id;
	char* name;//如果是char name[64]即栈上开辟的数组，不需要考虑深拷贝浅拷贝
};

void test()
{
	//如果有参构造的指针初始化方式为this->name = name;
	//如果是传常量，则可以。如：Student s(1, "12121");
	//如果是传变量，则会出问题。

	char name[64] = "zhangsan";
	Student s(1,name);//传入变量name
	//此时类中char* name维护的是栈上的数组name[64],指向同一个地址
	//导致这两个变量的生命周期相同
	//当name结束了，类中的char* name也会结束，此时s对象就会有问题

	//或者以下方式
	char *name = new char[64];
	strcpy(name,"zhangsan");
	Student s1(1,name);//传入变量name
	//此时类中char* name维护的是堆上的name = new char[64];,指向同一个地址
	//导致这两个变量的生命周期相同
	//当name结束了，类中的char* name也会结束，此时s1对象就会有问题

	delete[] name;
	//当name释放时，类中的char* name也会释放
	s1.printS();
}

int main()
{

	Student s1(1, "zhangsan");
	Student s2 = s1;//拷贝构造

	Student s3(2, "lisi");
	s2 = s3;//s2的等号赋值操作符，可以连续赋值，返回s2本身

	s1.printS();
	s2.printS();
	s3.printS();

	return 0;
}

//注意：默认拷贝构造函数和默认赋值操作符函数的功能都是一样的，都是浅拷贝动作

//Student s1(1, "zhangsan");
//Student s2 = s1;//拷贝构造
//
//Student s3(2, "lisi");
//s2 = s3;
//画内存图，发现默认赋值操作符函数，直接将s2.name的赋值给了s2.name
//导致s2和s3的name都指向同一块空间，析构时导致释放同一块空间两次。
//同时原s2.name中的内容导致内存泄漏
//因此重载赋值操作符函数，需要先判断s2.name是否开辟了空间，先释放空间，再进行深拷贝动作

//技巧：当重载函数是一定要提供=操作符重载和拷贝构造函数，防止别人使用你的源码时，误以为自己写的代码报错