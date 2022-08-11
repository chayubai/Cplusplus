#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{ 
public:
	//无参构造函数
	Test()
	{
		cout << "Test()..." << endl;
		m_x = 0;
		m_y = 0;
	}
	//有参构造函数
	Test(int x, int y)
	{
		cout << "Test(int x, int y)..." << endl;
		m_x = x;
		m_y = y;
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
	//注意：拷贝构造函数的参数为引用类型
	Test(const Test& another)
	{
		cout << "Test(const Test &another)..." << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}
	//=赋值操作符函数
	void operator=(const Test& another)
	{
		cout << "operator=(const Test& another)..." << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}
	//析构函数
	~Test()
	{
		cout << "~Test()..." << endl;
	}
private:
	int m_x;
	int m_y;
};

//场景1
void test1()
{
	Test t1(10, 20);
	//析构函数调用的顺序，跟构造相反，谁先构造的，谁后析构
	Test t2(t1);//Test t2 = t1;
	//即，进栈：t1先进栈，t2后进栈。析构：t2先析构，t1再析构
}

//场景2
void test2()
{
	Test t1(10, 20);//调用有参构造
	
	Test t2;//调用无参构造
	t2 = t1;//调用=操作函数
}

//场景3
void func(Test t)//Test t = t1;t的拷贝构造函数
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}
void test3()
{
	cout << "Test begin..." << endl;
	Test t1(10, 20);
	func(t1);
	cout << "Test end..." << endl;
}

//场景4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test t(10, 20);
	t.printT();

	cout << "func2 end..." << endl;
	return t;//创建临时对象/匿名对象来接收t，即调用匿名对象的拷贝构造函数Test temp = t
	//匿名对象 = temp 即，匿名对象.拷贝构造(temp)   Test temp = t = func2();
}
void test4()
{
	cout << "test4 begin..." << endl;
	func2();//返回一个匿名对象。
	//当一个函数返回一个匿名对象的时候，函数外部没有任何变量去接收它。
	//这个匿名对象将不会再被使用，（找不到），
	//编译器会直接将这个匿名对象回收掉，而不是等待整个函数执行完毕再回收

	cout << "test4 end..." << endl;
}

//场景5
void test5()
{
	cout << "test5 begin..." << endl;
	Test t1 = func2();//会不会触发t1的拷贝构造来，t1.拷贝构造函数(匿名)？
	//并不会触发t1拷贝构造，而是将匿名对象转正t1，
	//把这个匿名对象起了名字就叫t1

	//Test t1 = temp = func2();
	cout << "test5 end..." << endl;
}

//场景6
void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;//t1已经被初始化了。
	t1 = func2();//所以func2返回的匿名对象不会再次转正，而依然是匿名对象。
	//所以t1会调用=操作符函数，t1.operator=(匿名对象)，然后编译器会立刻回收掉匿名对象
	t1.printT();
	cout << "test6 end..." << endl;
}
int main()
{
	//test1();//先调用t1有参构造函数，再调用t2拷贝构造函数，再调t2的析构函数，再调用t1的析构函数
	
	//test2();//先调用t1有参构造函数，再调用t2无参构造函数，再调赋值操作函数，再调t2的析构函数，再调用t1的析构函数

	//test3();//先调用t1的有参构造函数，再调t的拷贝构造函数，再调用t的析构函数，再调t1的析构函数
	
	//test4();

	//test5();
	
	test6();//只要类中的对象和调用的构造函数，在使用完后会被自动调用析构函数
	return 0;
}