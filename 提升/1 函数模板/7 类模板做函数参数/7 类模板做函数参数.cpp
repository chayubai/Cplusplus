#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "������" << this->name << "�����䣺" << this->age << endl;
	}
	T1 name;
	T2 age;
};

//1��ͨ����ģ�崴�������Ķ�����Ϊ����������ָ���������ͣ���ʵ����ʲô���βξ���ʲô
void doWork1(Person<string, int> &p)
{
	p.showPerson();
}
void test1()
{
	Person<string, int> p("�����", 999);//ͨ����ģ�崴�������Ķ���
	doWork1(p);
}

//2��ͨ����ģ�崴�������Ķ�����Ϊ��������������<string, int>ģ�廯template<class T1,class T2>
template<class T1,class T2>//��Ϊ������ģ�壬���߱�������T1��T2ģ�壬����û����һ�лᱨ��
void doWork2(Person<T1, T2>& p)//����ģ��
{
	cout << "T1�������ͣ�" << typeid(T1).name() << endl;//string
	cout << "T2�������ͣ�" << typeid(T2).name() << endl;//int

	p.showPerson();
}
void test2()
{
	Person<string, int> p("��˽�", 998);//ͨ����ģ�崴�������Ķ���
	doWork2(p);//ͨ��ģ�庯���������
}

//3��ͨ����ģ�崴�������Ķ�����Ϊ��������������Person<string, int>ģ�廯template<class T>
template<class T>//��Ϊ������ģ�壬���߱�������Tģ�壬����û����һ�лᱨ��
void doWork3(T& p)//����ģ��
{
	cout << "T�������ͣ�" << typeid(T).name() << endl;//class Person<string,int>

	p.showPerson();
}
void test3()
{
	Person<string, int> p("��ɮ", 10000);//ͨ����ģ�崴�������Ķ���
	doWork3(p);//ͨ��ģ�庯���������
}
//ע�⣺��һ��ʹ�����
//�鿴T���������ͣ�typeid(T).name()
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}