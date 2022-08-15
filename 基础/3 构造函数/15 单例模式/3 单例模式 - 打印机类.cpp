#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
#include <string>
class Printer
{
public:
	static Printer* getInstance()
	{
		return printer;
	}
	void printText(string text)
	{
		m_count++;
		cout << text << endl;
	}

	int m_count;
private:
	Printer() 
	{ 
		m_count = 0;
		cout << "打印机调用" << endl;
	}

	Printer(const Printer&p){}
private:

	static Printer* printer;
};

Printer* Printer::printer = new Printer;

void test1()
{
	cout << "main调用" << endl;

	//注意：static Printer* printer;是编译阶段分配内存
	//此时编译阶段就会执行：Printer* Printer::printer = new Printer;
	//此时先调用printer的无参构造，再调用main函数

	//面试题：如何实现程序还未运行前，就打印hello world
}

void test2()
{
	//1、通过一个类 只能实例化唯一的一个对象
	//2、私有化-默认构造函数、拷贝构造函数、唯一实例指针
	//3、对外提供getInstance接口，将指针返回
	Printer* p = Printer::getInstance();
	p->printText("入职证明");
	p->printText("离职证明");
	p->printText("加薪申请");
	p->printText("旅游申请");

	cout << "打印机使用次数：" << p->m_count << endl;

	Printer* p2 = Printer::getInstance();
	p2->printText("调休申请");

	cout << "打印机使用次数：" << p->m_count << endl;
	cout << "打印机使用次数：" << p2->m_count << endl;

	//这样是无法访问m_count的，因为对象没有被创建出来，类不具有空间
	//cout << "打印机使用次数：" << m_count << endl; 
	
	//静态成员变量或函数，不属于对象，可以通过类名::静态成员变量/静态成员函数访问
	//cout << "打印机使用次数：" << Printer::m_count << endl; 

}
int main()
{
	//test1();
	test2();
	return 0;
}