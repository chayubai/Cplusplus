#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Parent
{
public:
	Parent()
	{
		cout << "Parent()..." << endl;
		a = 0;
	}
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
		
	}
	~Parent()
	{
		cout << "~Parent()..." << endl;
	}
	int a;
};

class Child:public Parent
{
public:

	//�������������Ĺ��죬�ڵ��������ʱ��Ĭ��һ������ø���Ĺ��췽��
	//�����ȹ��죬�������
	Child(int a,int b)//:Parent(10)
	{
		cout << "Child(int a,int b)..." << endl;
		this->b = b;

	}
	void printC()
	{
		cout << "b = " << b << endl;
	}
	~Child()
	{
		cout << "~Child()..." << endl;
	}
	int b;
};
int main()
{
	Child c(10, 20);
	c.printC();
	return 0;
}