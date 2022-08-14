#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//构造函数的初始化列表的练习
#if 0 
#include <string>
class Phone
{
public:
	Phone(string phoneName)
	{
		cout << "Phone(string phoneName)..." << endl;
		m_phoneName = phoneName;
	}
	~Phone()
	{
		cout << "~Phone()..." << endl;
	}
	string m_phoneName;
};

class Game
{
public:
	Game(string gameName)
	{
		cout << "Game(string gameName)..." << endl;
		m_gameName = gameName;
	}
	~Game()
	{
		cout << "~Game()..." << endl;
	}
	string m_gameName;
};

class Person
{
public:
	Person(string name, string phoneName, string gameName):m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{//Phone m_Phone = m_Phone(phoneName);调用Phone(string phoneName)
		cout << "Person(string name, string phoneName, string gameName)..." << endl;
	}
	~Person()
	{
		cout << "~Person()..." << endl;

	}
	void PlayGame()
	{
		cout << m_Name << "拿着《" << m_Phone.m_phoneName << "》牌手机，玩着：" << m_Game.m_gameName << endl;
		//m_Phone.m_phoneName、m_Game.m_gameName不能直接使用m_Phone、m_Game，报错，找不到与之匹配的操作符
		//包含#include <string>
	}
	string m_Name;//姓名
	Phone m_Phone;//手机
	Game m_Game;  //游戏
};
void test()
{
	//当其他类对象作为本类成员，先构造其他类对象，再构造自身，析构的顺序和构造相反
	Person p("王二", "苹果", "王者荣耀");
	p.PlayGame();
}
int main()
{
	test();
	return 0;
}
#endif

class A
{
public:
	A(int a)
	{
		cout << "A()..." << endl;
		m_a = a;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
	void printA()
	{
		cout << "a = " << m_a << endl;
	}
	int m_a;
};
class B
{
public:

#if 0
	B(A& a1, A& a2, int b)
	{
		m_b = b;
		//以下对对象的赋值是错误的
		/*m_a1 = a1;
		m_a2 = a2;*/
		//以下对对象的赋值是错误的
		m_a1(a1);
		m_a2(a2);
	}
#endif

	//初始化类的对象成员，使用构造函数的初始化列表
	//先调用初始化列表的（默认）有参构造函数，再调用完整的函数
	//构造对象成员的顺序跟初始化列表的顺序无关，而是跟成员对象的定义顺序有关
	//语法格式：构造函数名：属性(值),属性(值)...

	B(A& a1, A& a2, int b) :m_a1(a1), m_a2(a2)
	{
		cout << "B(A &a1, A &a2, int b)... " << endl;
		m_b = b;
	}
	//先调用初始化列表的（默认）有参构造函数，再调用完整的函数
	B(int a1, int a2, int b) :m_a1(a1), m_a2(a2)
	{
		cout << "B(int a1, int a2, int b)... " << endl;
		m_b = b;
	}
	~B()
	{
		cout << "~B()..." << endl;
	}
	void printB()
	{
		cout << "b = " << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}
private:

	int m_b;

	//两个成员对象:A m_a1;A m_a2;

	A m_a2;
	A m_a1;
};

class ABC
{
public:
	//对于常量的初始化，一定要放在初始化列表中
	ABC(int a, int b, int c)
	{
		cout << "ABC(int a, int b, int c)... " << endl;
		m_a = a;
		m_b = b;
		m_c = c;
	}
	/*
	ABC(int a, int b, int c，int m) :m_m(m)
	{

	}
	*/
	~ABC()
	{
		cout << "~ABC()... " << endl;

	}
private:
	int m_a;
	int m_b;
	int m_c;
	//const int m_m;
	//注意：尽量不要在成员变量中初始化
};

class ABCD
{
public:
	//第一种初始化
	ABCD(int a, int b, int c, int d) :m_abc(a, b, c), m_d(d)
	{

	}
	//第二种初始化
	ABCD(ABC& abc, int d) :m_abc(abc)
	{
		m_d = d;
	}
private:
	int m_d;
	ABC m_abc;
};

void test1()
{
	A a1(10), a2(100);
	B b(a1, a2, 1000);
	b.printB();
}

void test2()
{
	B b(10, 20, 30);
	b.printB();
}

void test3()
{
	ABC abc(10, 20, 30);
	//ABCD abcd(1, 2, 3, 4);
	ABCD abcd(abc, 40);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}