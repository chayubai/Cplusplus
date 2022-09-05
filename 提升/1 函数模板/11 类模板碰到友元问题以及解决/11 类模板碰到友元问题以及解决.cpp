#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person;//����һ����ģ��

//template<class T1, class T2>class Person;���Ժϲ�

//��ʽһ
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p);//��һ���Ƕ�ʹ�õĺ���ģ��������������ں���ģ������ʱ����Person
//��ʹ��Personǰ����Ҫ��ǰ����Person�࣬

//��ʽ��
template<class T1, class T2>
void printPerson3(Person<T1, T2>& p)//��������ʵ����ǰ
{
	cout << "����ʵ�� -- ������" << p.m_Name << "�����䣺" << p.m_Age << endl;
}

//ע�⣺��Ԫ��������ʵ�ֲ���Ҫ������
template<class T1, class T2>
class Person
{
	//1����Ԫ���� ����ʵ�֡���Ԫ�ؼ��ֿ��Է����������λ�á���Ԫ��������ʵ�֣����Է������ڵ�˽�г�Ա
	friend void printPerson1(Person<T1, T2>& p)
	{
		cout << "����ʵ�� -- ������" << p.m_Name << "�����䣺" << p.m_Age << endl;//��Ԫ��������˽�г�Ա����
	}

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
	//2����Ԫ���� ����ʵ�� - ����һ������ģ��������ʵ�ַ���
	//friend void printPerson2(Person<T1, T2>& p);//û�н�����ģ�壬�������ͨ����������������û�к���ʵ�֣����µ���ʱ���޷�����

	friend void printPerson2<>(Person<T1, T2>& p);//����ģ����������ղ����б���ʱ��������һ��ģ�壬��Ҫ���߱����������ģ����ڣ�
	//����ʹ��ǰ��Ҫ��ǰ����printPerson2(Person<T1, T2>& p);ģ��

	//3����Ԫ���� ����ʵ�� - ��������������ʵ��һ��
	friend void printPerson3<>(Person<T1, T2>& p);//����ģ����������ղ����б���ʱ��������һ��ģ�壬��Ҫ���߱����������ģ����ڣ�
	//����ʹ��ǰ��Ҫ��ǰ����printPerson3(Person<T1, T2>& p);ģ��

	//�ܽ᣺����ʵ����Ԫ������ǰ�᣺1�����ں���ģ������(�����ɼӿɲ���) 2��������������ģ���Լ�������Ҫ��ǰʹ�õ��� 3������ʵ��

private:
	T1 m_Name;
	T2 m_Age;
};

//����һ������ʵ��
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)//��������Ǻ���ģ�壬�����Ҫ�Ժ���ģ�������������friend void printPerson2<>(Person<T1, T2>& p);
{
	cout << "����ʵ�� -- ������" << p.m_Name << "�����䣺" << p.m_Age << endl;
}

void test1()
{
	Person<string, int> p("Tom", 10);
	printPerson1(p);//�޷��������ⲿ����
}

void test2()
{
	Person<string, int> p("Tom", 10);
	printPerson2(p);
}

void test3()
{
	Person<string, int> p("Tom", 10);
	printPerson3(p);
}

int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}