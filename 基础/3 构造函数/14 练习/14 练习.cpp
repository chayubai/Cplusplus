#define _CRT_SECURE_NO_WARNINGS 1

//1、构造函数的种类，并举例说明

//2、
#if 0
class Test
{
public:
	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
	Test(Test& t)
	{
		cout << "拷贝构造函数被执行" << endl;
	}
	~Test()
	{
		cout << "析构函数被执行" << endl;
	}
	int m_a;
	int m_b;
};
void main()
{
	Test t1, t2;
}
#endif
//说明t1和t2析构函数的执行顺序。

//3、
#if 0
void test1()
{
	Test t1(1, 2);
	Test t2(t1);
}
#endif
//分析test1()函数中t1和t2构造函数和析构函数调用情景
//4、
#if 0
void test2()
{
	Test t1(1, 2);
	Test t2 = t1;
}
#endif
//分析test2()函数中t1和t2构造函数和析构函数调用情景

//5、
#if 0
void func(Test t)
{
	cout << "func begin..." << endl;

	cout << "func end..." << endl;
}
void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);
	//调用func函数
	func(t1);
	cout << "func end..." << endl;
}
#endif
//分析test3()函数和func函数中的，构造函数和析构函数调用情景

//6、
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//局部变量
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test4()
{
	cout << "test4 begin..." << endl;
	gg();
	cout << "test4 end..." << endl;
}
#endif
//分析test4()函数和gg()函数中构造函数和析构函数调用情景

//7、
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//局部变量
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test4()
{
	cout << "test5 begin..." << endl;
	Test t1 = gg();
	cout << "test5 end..." << endl;
}
#endif
//分析test5()函数和gg()函数中构造函数和析构函数调用情景

//8、
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//局部变量
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1 = gg();
	cout << "test6 end..." << endl;
}
#endif
//分析test6()函数和gg()函数中构造函数和析构函数调用情景

//9、简述类的默认拷贝构造函数深拷贝和浅拷贝的问题

//10、new、delete和malloc、free的区别

//11、static修饰的类的成员变量和成员函数的特点。
//如何初始化一个static修饰的成员变量？
//如何使用一个static修饰的成员函数？

#if 0
#include <iostream>
using namespace std;

class A
{
public:
	int a = 10;
	static int b;
};
int A::b = 20;
int main()
{
	/*cout << a <<endl;
	cout << b << endl;*/
	//这样是无法访问a和b的，因为对象没有被创建出来，类不具有空间

	//cout << A::a << endl;
	cout << A::b << endl;
	//静态成员变量或函数，不属于对象，可以通过类名::成员变量/成员函数访问
	return 0;
}
#endif

#include <iostream>
using namespace std;

class A
{
public:
	A(const char* name)
	{
		int len = strlen(name);
		m_name = (char*)malloc(sizeof(len + 1));
		strcpy(m_name, name);
	}
	void printT()
	{
		cout << "printT():" << m_name << endl;//这里有问题
	}
	~A()
	{
		cout << "~Test()" << endl;
		if (m_name != NULL)
		{
			free(m_name);
			m_name = NULL;
		}
	}
	char* m_name;
};
int main()
{
	A * p = new A("zs");
	p->printT();
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
	//cout << a.m_name << endl;//这里有问题
	return 0;
}