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

	//������󴴽���ʱ�򣬸����ȹ��죬�������
	
	//�ڹ�����������ʱ��Ĭ��һ������ø����Ĭ�Ϲ��췽��
	//���ֻ���常����вι��죬�����常���Ĭ�Ϲ��죬�ͻᱨ����Ϊ��֪����ô���츸��
	//����ʹ�ò����б����ø�����вι����ʼ��

	//ע�⣺�����е�������public������������ֱ�ӳ�ʼ��
	Child(int a,int b)//:Parent(10)
	{
		cout << "Child(int a,int b)..." << endl;
		this->a = a;//һ����ԣ����������˭�ģ�����˭�Ĺ��캯����ʼ��
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