#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{ 
public:

	Person()
	{
		cout << "����Person()�޲ι��캯��" << endl;
	}

	Person(int age)
	{
		cout << "����Person(int age)�вι��캯��" << endl;
		m_age = age;
	}

	Person(const Person& p)
	{
		cout << "����Person(const Person &p)�������캯��" << endl;
		m_age = p.m_age;
	}

	~Person()
	{
		cout << "����~Person()��������" << endl;
		m_age = 0;
	}

	int m_age;
};

//1�����Ѿ������õĶ�������ʼ���¶��󣬻���ÿ������캯��
void test1()
{
	Person p1(18);
	Person p2(p1);//Person p2 = Person(p1);
	cout << "p2�����䣺" << p2.m_age << endl;
}

//2��ֵ���ݵķ�ʽ��������������ֵ������ÿ������캯��
void doWork(Person p)//Person p = p1 ��Person p = Person(p1);���ÿ������캯��
{
	//�ɴ˿�֪p1��p�Ƕ������������󣬻���Ӱ��
}
void test2()
{
	Person p1(18);
	doWork(p1);
}

//3����ֵ�ķ�ʽ�����ؾֲ����󣬻���ÿ������캯��
Person doWork2()//���ﲻ�Ƿ��ؾֲ����������
{
	Person p;
	return p;//doWork2() = Person temp = p ���ÿ������캯��
}
void test3()
{
	Person p1 = doWork2();//��ִ��doWork2()�е�Person p;�����޲εĹ��캯����Person p1 = temp�ٵ��ÿ������캯��
}

/*
	�������Ż��� release�汾�Ĵ��룺�鿴���
	void doWork2(Person &p){};

	Person p;
	doWork2(p);

*/
int main()
{
	//test1();

	//test2();

	test3();

	return 0;
}