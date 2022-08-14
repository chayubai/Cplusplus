#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//���캯���ĳ�ʼ���б����ϰ
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
	{//Phone m_Phone = m_Phone(phoneName);����Phone(string phoneName)
		cout << "Person(string name, string phoneName, string gameName)..." << endl;
	}
	~Person()
	{
		cout << "~Person()..." << endl;

	}
	void PlayGame()
	{
		cout << m_Name << "���š�" << m_Phone.m_phoneName << "�����ֻ������ţ�" << m_Game.m_gameName << endl;
		//m_Phone.m_phoneName��m_Game.m_gameName����ֱ��ʹ��m_Phone��m_Game�������Ҳ�����֮ƥ��Ĳ�����
		//����#include <string>
	}
	string m_Name;//����
	Phone m_Phone;//�ֻ�
	Game m_Game;  //��Ϸ
};
void test()
{
	//�������������Ϊ�����Ա���ȹ�������������ٹ�������������˳��͹����෴
	Person p("����", "ƻ��", "������ҫ");
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
		//���¶Զ���ĸ�ֵ�Ǵ����
		/*m_a1 = a1;
		m_a2 = a2;*/
		//���¶Զ���ĸ�ֵ�Ǵ����
		m_a1(a1);
		m_a2(a2);
	}
#endif

	//��ʼ����Ķ����Ա��ʹ�ù��캯���ĳ�ʼ���б�
	//�ȵ��ó�ʼ���б�ģ�Ĭ�ϣ��вι��캯�����ٵ��������ĺ���
	//��������Ա��˳�����ʼ���б��˳���޹أ����Ǹ���Ա����Ķ���˳���й�
	//�﷨��ʽ�����캯����������(ֵ),����(ֵ)...

	B(A& a1, A& a2, int b) :m_a1(a1), m_a2(a2)
	{
		cout << "B(A &a1, A &a2, int b)... " << endl;
		m_b = b;
	}
	//�ȵ��ó�ʼ���б�ģ�Ĭ�ϣ��вι��캯�����ٵ��������ĺ���
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

	//������Ա����:A m_a1;A m_a2;

	A m_a2;
	A m_a1;
};

class ABC
{
public:
	//���ڳ����ĳ�ʼ����һ��Ҫ���ڳ�ʼ���б���
	ABC(int a, int b, int c)
	{
		cout << "ABC(int a, int b, int c)... " << endl;
		m_a = a;
		m_b = b;
		m_c = c;
	}
	/*
	ABC(int a, int b, int c��int m) :m_m(m)
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
	//ע�⣺������Ҫ�ڳ�Ա�����г�ʼ��
};

class ABCD
{
public:
	//��һ�ֳ�ʼ��
	ABCD(int a, int b, int c, int d) :m_abc(a, b, c), m_d(d)
	{

	}
	//�ڶ��ֳ�ʼ��
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