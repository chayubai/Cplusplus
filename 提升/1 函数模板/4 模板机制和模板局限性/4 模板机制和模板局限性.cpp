#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ�����" << endl;
}

/*

1�������������ǰѺ���ģ�崦����ܹ������κ����͵ĺ��������Զ������ͣ����磺��������֮��ĸ�ֵ
template<class T>
void f(T a, T b)
{
	a = b;
}

2������ģ��ͨ���������Ͳ�����ͬ�ĺ��� -- ͨ������ģ������ĺ��� ��Ϊģ�庯��
	int a = 10;
	int b = 20;
	myPrint(a, b)
void myPrint(int a, int b)
{
	cout << "����ģ�����" << endl;
}

	double a = 10;
	double b = 20;
	myPrint(a, b)
void myPrint(double a, double b)
{
	cout << "����ģ�����" << endl;
}

3����������Ժ���ģ��������α��룬�������ĵط���ģ����뱾����б��룬�ڵ��õĵط��Բ����滻��Ĵ�����б���
//��һ�α��룬��ֹģ��������󡣵ڶ��α��룬��ֹ���ɵ�ģ�庯����������

*/

//ģ�������
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

//ʵ�����������Աȵĺ���
template<class T>
bool myCompare(T &a, T &b)
{
	if (a == b)//==�������������أ�ʵ�ַ������������͵ı����Ƚ�
	{
		return true;
	}
	return false;
}

//2�������������еĺ���ģ�壬ʹ��(������)���廯ʵ�ֶ��Զ����������ͣ��ṩ����ĺ���ģ��
//������廯�ܹ�����ƥ�䣬��ô��ѡ����廯
//�﷨��template<> ����ֵ ������(�����β�1, �����β�2...)
//ʵ���Ͽ�������ͨ����ʵ��
//��������Ŀ����Ϊ����ģ���ṩһ�������ӿڣ�ʹ�����ͨ�á�
template<> bool myCompare(Person& a, Person& b)//template<> int myCompare(Person& a, Person& b)����������ԭ����ģ��������ṩ���廯
{
	if (a.name == b.name && a.age == b.age)
	{
		return true;
	}
	return false;
}

void test1()
{
	int a = 10;
	int b = 10;
	//������������ �ı����Ƚ�
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}
void test2()
{
	/*
	//�������������� �ı����Ƚ�
	Person p1("Tom", 19);
	Person p2("Tom", 19);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}*/

	//���ϴ���ʹ��ģ��ͻᱨ��
	//���������
	//1����==�Ž������أ�ʹ���ܹ��Ƚ�����Person���͵�����

	//2�����þ��廯ʵ�ֶ��Զ����������ͣ��ṩ�����ģ��
}
void test3()
{
	//2�����þ��廯ʵ�ֶ��Զ����������ͣ��ṩ�����ģ��
	Person p1("Tom", 19);
	Person p2("Tom", 19);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}