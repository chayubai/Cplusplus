#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
class Person
{ 
public:
	/*Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}*/

	//这样初始化成员变量就写死了
	/*Person() :m_A(10), m_B(20)
	{

	}*/

	//构造函数的初始化列表，初始化列表可以给任意成员变量初始化
	Person(int a, int b) :m_A(a), m_B(b)//
	{
		//可以写其他的内容
	}
	int m_A;
	int m_B;
};

int main()
{
	Person p(10, 20);

	return 0;
}
#endif

class A
{
public:
	A(int a)
	{
		cout << "A(int a)..." << endl;
		m_a = a;
	}
	void printA()
	{
		cout << "m_a = " << m_a << endl;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int m_a;
};
class B
{
public:
	//B(A &a1, A &a2,int b)
	//{
	//	cout << "B()..." << endl;
	//	m_b = b;
	//	//对于A m_a;无法通过构造函数进行初始化
	//	//m_a1(a1);//不对，编译器当函数调用
	//	//m_a1 = a1;//不对，这里调用的是m_a1的=操作符函数
	//}

	B(A& a1, A& a2, int b) :m_a1(a1),m_a2(a2)//m_a1(a1)调用m_a1的拷贝构造
	{
		cout << "B(A& a1, A& a2, int b)..." << endl;
		m_b = b;
		//引入初始化列表，为了解决对成员变量为其他类的对象进行初始化,也能初始化普通成员变量
	}
	B(int a1, int a2, int b) :m_a1(a1),m_a2(a2)//m_a1(a1)调用m_a1的有参构造
	{
		cout << "B(int a1, int a2, int b)..." << endl;
		m_b = b;
	}
	//构造对象成员的顺序跟初始化列表的顺序无关
	//而是跟成员变量的定义顺序有关，将A m_a1;A m_a2;的定义顺序改变一下，查看结构
	void printB()
	{
		cout << "m_b = " << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}

	~B()
	{
		cout << "~B()..." << endl;
	}
private:
	int m_b;
	A m_a1;
	A m_a2;
};

class ABC
{
public:
	ABC(int a,int b ,int c, int m):m_m(m)
	{
		cout << "ABC(int ,int ,int)" << endl;
		m_a = a;
		m_b = b;
		m_c = c;
		//m_m = m//错误
	}
	~ABC()
	{
		cout << "~ABC() " << endl;
	}
private:
	int m_a;
	int m_b;
	int m_c;
	const int m_m;//常量的赋值，必须放在初始化列表中
};
class ABCD
{
public:
	ABCD(int a, int b, int c,int d,int m):m_abc(a,b,c, m),m_d(d)
	{
		cout << "ABCD(int a, int b, int c,int d)" << endl;
	}
	ABCD(ABC &abc, int d) :m_abc(abc), m_d(d)
	{
		cout << "ABCD(ABC &abc, int d)" << endl;
	}
	~ABCD()
	{
		cout << "~ABCD() " << endl;
	}
private:
	int m_d;
	ABC m_abc;
};
int main()
{
	A a1(10),a2(100);

	B b(a1,a2,100);
	b.printB();

	cout << "----------" << endl;

	B b(10, 20, 100);
	b.printB();

	cout << "----------" << endl;

	ABC abc(10, 20, 30,666);

	ABCD abcd1(1, 2, 3, 4,666);
	ABCD abcd2(abc, 4);
	return 0;
}