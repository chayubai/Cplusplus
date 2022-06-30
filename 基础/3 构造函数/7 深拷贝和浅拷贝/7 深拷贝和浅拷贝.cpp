#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string.h>

//构造函数的作用：初始化对象
//析构函数的作用：将堆区上的变量进行释放
//如果有属性开辟到堆区，利用编译器提供的拷贝构造函数会调用浅拷贝带来的析构重复释放堆区内存的问题

class Teacher
{
public:
	Teacher(int id, const char* name)//由于接受的"name"是一个字符串常量，类型属于const char*
	{
		cout << "~Teacher(int id, const char* name)..." << endl;
		//赋值id
		m_id = id;

		//赋值name
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);//包含"\0"字符
		strcpy(m_name, name);
	}
	//只要成员变量有malloc开辟的空间，就需要手动显式的提供一个析构函数，来完成释放malloc开辟的空间
	~Teacher()
	{
		cout << "~Teacher()..." << endl;//用来测验释放m_name
		if (m_name != NULL)
		{
			free(m_name);
			m_name = NULL;
		}
	}
	void printT()
	{
		cout << "id = " << m_id << " name = " << m_name << endl;
	}
	
#if 0
	//编译器提供的默认拷贝构造函数
	Teacher(const Teacher& another)
	{
		//值的赋值操作
		m_id = another.m_id;
		m_name = another.m_name;
	}
#endif

	//只要成员变量有指针，就需要手动显式的提供一个拷贝构造函数，来完成深拷贝动作
	Teacher(const Teacher& another)
	{
		m_id = another.m_id;//m_name = another.m_name;不可以使用此行代码

		int len = strlen(another.m_name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, another.m_name);
	}
	int m_id;
	char *m_name;
};

void test1()
{
	Teacher t1(1, "zhangsan");
	t1.printT();
}

//防止内存泄露（开辟的空间没有释放），防止多次释放同一块空间
void test2()
{
	Teacher t1(1, "zhangsan");//先调用t1的有参构造函数，
	t1.printT();
	//下面是浅拷贝
	Teacher t2(t1);//再调用t2的默认拷贝构造函数，再调用t2的析构函数，再调用t1的析构函数

	//此时的t1.name和t2.name都指向malloc的空间
	//当调用t2的析构函数时，开辟的空间被释放了，t2.name=NULL，此时t1.name指向的malloc的空间为别人的空间，指针不为NULL，再调用t1的析构函数程序就崩了
	t2.printT();

	//如何解决浅拷贝动作？ 由于程序是通过调用编译器默认的拷贝构造函数导致的问题 - 设计深拷贝
	//显式的设计拷贝构造函数，将拷贝的值放入另一个空间中。
	//开辟的两个空间，分别指向对应的name，这样各自调用析构函数时，就会释放各自的开辟的空间
}
int main()
{
	//test1();
	test2();
	return 0;
}
