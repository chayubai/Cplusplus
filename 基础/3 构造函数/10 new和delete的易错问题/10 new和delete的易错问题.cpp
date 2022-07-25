#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//以下程序有问题，不知道怎么解决
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
		m_a = 0;
		strcpy(m_name, "");
	}
	Test(int a, const char* name)
	{
		cout << "Test(int ,const char*)" << endl;
		m_a = a;
		int len = strlen(name);
		m_name = (char*)malloc(sizeof(len + 1));
		if (m_name == NULL)
			return;
		strcpy(m_name, name);
	}
	void printT()
	{
		cout << "printT():" << m_a << "," << m_name << endl;//这里有问题
	}
	~Test()
	{
		if (m_name != NULL)
		{
			cout << "~Test()" << endl;
			free(m_name);
			m_name = NULL;
		}
	}
private:
	int m_a;
	char* m_name;
};

//C语言中，堆上创建对象
void test1()
{
	Test* tp = (Test*)malloc(sizeof(Test));
	//必须设计一个显式的init(),来初始化m_a、m_name
	//tp->printT();
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}

//C++语言中，堆上创建对象
void test2()
{
	Test* tp = new Test(10, "zhangsan");//触发有参构造函数    
										//tp = new Test;触发无参构造函数，而不是这个tp = new Test();
	tp->printT();

	//注意：tp是栈上开辟的空间，但tp指向的空间是堆上开辟的
	if (tp != NULL)
	{
		delete tp;//释放tp指向的空间之前，触发析构函数先释放堆上的malloc开辟在堆上的m_name指向的空间
		tp = NULL;
	}

	//如果上面delete tp;改为free(tp);则不会触发析构函数，直接释放了tp指向的空间，导致m_name指向的空间未释放，内存泄露

	//注意：如果类中有属性开辟到堆区，利用编译器提供的拷贝构造函数会调用浅拷贝带来的析构重复释放堆区内存的问题
	//则使用delete释放空间时，并设计深拷贝动作
}

//malloc、free是函数，标准库：stdlib.h
//new 在堆上初始化一个对象的时候，会触发对象的构造函数，malloc不能
//free 并不能触发一个对象的析构函数，而delete会触发析构函数

int main()
{
	//test1();
	test2();
	return 0;
}