#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base
{
public:

	static void func()
	{
		cout << "Base func()��Ա�������� " << endl;
	}
	//ע�⣺��̬��Ա�������ܷ��ʷǾ�̬��Ա����

	static void func(int a)
	{
		cout << "Base func(int a)��Ա�������� " << endl;
	}

	static int m_A;

	//��̬��Ա�������ص㣺
	//1�����ж�����ͬһ���ڴ�����
	//2������׶η����ڴ�
	//3�����������������ʼ��
};

int Base::m_A = 10;

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son func()��Ա�������� " << endl;
	}
	static int m_A;
};

int Son::m_A = 20;

void test1()
{
	//1��ͨ���������
	Son s;
	//������������Ա��������ͬʱ�����ñ����еĳ�Ա����
	cout << "s.m_A = " << s.m_A << endl;
	//ע�⣺��̬��Ա���ԣ�������Լ̳�����

	//�����Ҫ���ʸ����еĳ�Ա���ԣ�����������������ʸ�����ͬ����Ա
	cout << "Base�е�m_A = " << s.Base::m_A << endl;

	//2��ͨ����������
	cout << "Son.m_A = " << Son::m_A << endl;
	cout << "Son.m_A = " << Son::Base::m_A << endl;
	//ǰ���::��ʾͨ�������ķ�ʽ���ʾ�̬��Ա�������::��ʾBase������

	cout << "Base.m_A = " << Base::m_A << endl;
}

void test2()
{
	//1��ͨ���������
	Son s;
	//������������Ա��������ͬʱ�����ñ����еĳ�Ա����

	cout << "s.func(): ";
	s.func();

	//�����Ҫ���ʸ����еĳ�Ա����������������������ʸ�����ͬ����Ա
	cout << "Base�е�func(): ";
	s.Base::func();

	//2��ͨ����������
	cout << "s.func(): ";
	Son::func();
	cout << "Base�е�func(): ";
	Son::Base::func();
	//ǰ���::��ʾͨ�������ķ�ʽ���ʾ�̬��Ա�������::��ʾBase������
}

void test3()
{
	Son s;
	//1��
	s.func();
	//s.func(10);//������������ͬ�����������ص���
	s.Base::func(10);
	//2��
	//Son::func(10);//������������ͬ�����������ص���
	Son::Base::func(10);

	//����ͨ��Ա��������һ��
	//���������¶����˸����е�ͬ����Ա����������ĳ�Ա�����ᣬ���ص��������������ذ汾��ͬ����Ա
	//����������������ʽָ������
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}