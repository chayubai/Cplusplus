#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class MyException
{
public:
	MyException()
	{
		cout << "MyException的默认构造函数调用" << endl;
	}
	MyException(const MyException &e)
	{
		cout << "MyException的拷贝构造函数调用" << endl;
	}
	void print()
	{
		this->m_A = 100;
		cout << "error:" << m_A << endl;
	}

	~MyException()
	{
		cout << "MyException的析构函数调用" << endl;
	}

	int m_A;
};

void doWork()
{
	throw MyException();//匿名对象 - 调用默认构造函数
	//throw &(MyException());//&MyException()可以这样写
	//throw new MyException();//想让指针接收对象，可以堆区上开辟空间，然后手动释放
}

void test()
{
	try
	{
		doWork();
	}
	catch (MyException e)//值传递 - 调用拷贝构造函数
	{//catch (MyException& e)
		//catch (MyException* e)
		cout << "自定义类型异常捕获" << endl;
		//e.print();//这里，由于对象提前释放了，e为野指针，导致非法访问
		
		//delete e;
	}
	catch (...)
	{
		cout << "其他类型异常捕获" << endl;
	}

	//此时的结果？异常对象的生命周期
	//1、先MyException()异常对象调用默认构造函数，再传入e中，调用拷贝构造函数。执行打印语句，最后两个析构
	//异常对象在catch处理完之后才析构

	//如果将MyException e改为引用传递MyException &e，结果？
	//2、先MyException()异常对象调用默认构造函数，再传入e中，执行打印语句，最后一个析构
	//不调用拷贝构造函数，异常对象在catch处理完后析构

	//如果将MyException e改为引用传递MyException *e，结果？
	//3、先MyException()异常对象调用默认构造函数，再调用析构函数。最后执行打印语句
	//如果使用这种方式，导致异常对象在catch处理完之后提前释放。当捕获异常后，无法通过对象访问其内容。应该延长异常对象的生命周期

	//抛出的是throw MyException();catch(MyException e)调用拷贝构造函数 效率低，因为多开销一份空间
	//为什么没有立即释放对象？因为MyException e = MyException()引用接收对象

	//抛出的是throw MyException();catch(MyException &e)只调用默认构造函数 效率高(推荐)
	//为什么没有立即释放对象？因为MyException &e = MyException()引用接收对象

	//抛出的是throw &(MyException());catch(MyException *e)此时先调用默认构造，再立即析构对象，最后捕获异常
	//（如果捕获异常代码段有需要用到的对象的其他操作，就会导致非法访问）

	//因此如果想使用指针接收，可以通过throw new MyException();catch(MyException *e);之后需要delete e;（和引用是相似的）
	//注意：也是会调用默认构造，但需要手动管理对象的释放

	//推荐使用 引用的方式 接收自定义类型的异常
}
int main()
{
	test();
	return 0;
}
//注意：匿名对象是在他当前执行完后，立刻释放
//但是当它被一个对象或者引用来接收的话，相当于给这个匿名对象重新取了名字，使得作用域延长了。
//由于指针不是给对象取名，因此会匿名对象会提前释放