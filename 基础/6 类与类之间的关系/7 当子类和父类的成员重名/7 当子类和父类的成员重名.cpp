#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Parent
{
public:

	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;

	}
	int a;
};
class Child :public Parent
{
public:

	Child(int p_a, int c_a):Parent(p_a)
	{
		this->a = c_a;

	}
	void printC()
	{
		//�������͸��඼����ͬ��public�ĳ�Ա�������������ͨ����������
		//�������Ϊ˽�еģ�ֻ��ͨ��get��������
		cout << "Parent's a = " << Parent::a << endl;
		cout << "Child's a = " << this->a << endl;
	}
	int a;
};
int main()
{
	Child c(10, 200);
	c.printC();
	return 0;
}