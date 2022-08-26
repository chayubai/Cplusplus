#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}

	int a;
};
class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{
		cout << "Child(int a)..." << endl;
	}
	virtual void print()
	{
		cout << "Child::print()...a = " << a << endl;
	}
};

void test()
{
	Child array[] = { Child(0),Child(1),Child(2) };

	//ע��Child(0),Child(1),Child(2)���������������
	//��Ϊ��arry[0] = Child(0),arry[1] = Child(1),arry[2] = Child(2),�ж������

	for (int i = 0; i < 3; i++)
	{
		array[i].print();
	}
}

void test2()
{
	Child array[] = { Child(0),Child(1),Child(2) };

	Parent* pp = &array[0];//����ָ��ָ���������
	Child* cp = &array[0];

	pp->print();
	cp->print();

	pp++;
	cp++;

	//���ڸ����ָ��ָ������Ķ���ʱ���������͸������Ŀռ���ͬ
	//�������������ָ��++ʱ���������ӵĲ�����ͬ
	pp->print();
	cp->print();
}
void test3()
{
	Child array[] = { Child(0),Child(1),Child(2) };
	Parent* pp = &array[0];
	int i = 0;
	for (pp = &array[0], i = 0; i < 3; i++, pp++)
	{
		pp->print();
	}
	//���ڸ����ָ��ָ������Ķ���ʱ���������͸������Ŀռ���ͬ��������ͬ����С��ȣ�
	//�����������ʱ������������ָ��++ʱ��ʵ���Ͼ��ǿ�Ĳ��������������Ĳ���
}
#endif

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}

	int a;
};
class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{
		cout << "Child(int a)..." << endl;
	}
	virtual void print()
	{
		cout << "Child::print()...a = " << a << endl;
	}

	int b;
};
void test3()
{
	Child array[] = { Child(0),Child(1),Child(2) };
	Parent* pp = &array[0];
	Child* cp = &array[0];
	int i = 0;
	/*for (pp = &array[0], i = 0; i < 3; i++, pp++)
	{
		pp->print();
	}*/
	//���ڸ����ָ��ָ������Ķ���ʱ���������͸������Ŀռ��С��ͬ
	//�����������ʱ������������ָ��++ʱ���������Ĳ������ڸ������Ĳ��������ʾͻ������

	//���������
	for (cp = &array[0], i = 0; i < 3; i++, cp++)
	{
		cp->print();
	}

	//ע�⣺ָ���++���ᷢ����̬��
	//ppָ���++�Ǽӵ�sizeof(Parent)��С
	//cpָ���++�Ǽӵ�sizeof(Child)��С
}

int main()
{
	

	return 0;
}