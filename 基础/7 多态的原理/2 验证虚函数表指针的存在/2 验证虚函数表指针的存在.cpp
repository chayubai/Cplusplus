#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{ 
public:
	virtual void func()
	{
		cout << "Person::func()..." << endl;
	}
	virtual void func(int a)
	{
		cout << "Person::func()..." << endl;
	}
private:
	int a;
};

class Person2
{
public:
	void func()
	{
		cout << "Person2::func()..." << endl;
	}
private:
	int a;
};

int main()
{
	Person p1;
	Person2 p2;

	cout << "size of Person ..." << sizeof(Person) << endl;//�������4���ֽھ����麯����ָ��Ŀռ��С
	cout << "size of Person2 ..." << sizeof(Person2) << endl;

	//1�������඼δ��virtual�ؼ���ʱ������4�ֽ�

	//2����������һ�������virtual�ؼ���ʱ���ӹؼ��ֵ��࣬��СΪ8�ֽڡ�δ�ӹؼ��ֵ��࣬��СΪ4�ֽ�

	//3�������ӹؼ��ֵ��࣬���к������أ���С��Ϊ8�ֽ�

	//p1.vptr;ע�⣺���޷������麯����ָ���
	return 0;
}