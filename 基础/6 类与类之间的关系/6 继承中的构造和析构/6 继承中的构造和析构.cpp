#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		cout << "����Base1���캯��" << endl;
	}
	~Base1()
	{
		cout << "����Base1��������" << endl;
	}
};

class Other;//����Ϊʲô���ᱨ�������������������Ķ������ʹ�ø�����������

class Son1 :public Base1
{
public:
	Son1()
	{
		cout << "����Son1���캯��" << endl;
	}
	~Son1()
	{
		cout << "����Son1��������" << endl;
	}
	Other other;//������������Ϊ�ĳ�Ա���ԣ����ȵ�����Ĺ��캯�����ٵ��ñ���Ĺ��캯��

	//�ȵ��ø��๹�죿�����ȵ���������Ĺ��죿
};

class Other//����������Ǻ���ģ�ǰ��ʹ�ø�����Ҫ����
{
public:
	Other()
	{
		cout << "����Other���캯��" << endl;
	}
	~Other()
	{
		cout << "����Other��������" << endl;
	}
};

class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "����Base2���캯��" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	/*Son2()
	{
		cout << "����Son1���캯��" << endl;
	}*/
	
	//������д���вι���ʱ����û��Ĭ�Ϲ��캯��
	//������̳и���ʱ�����ȵ��ø����Ĭ�Ϲ��캯����������û�и����Ĭ�Ϲ��캯������˻ᱨ��������Ĭ�Ϲ��캯��
	
	//��ν����
	//1�������ṩ�Զ����Ĭ�Ϲ��캯��

	//2�����ó�ʼ���б��﷨����ʽ���ø����е��������캯��
	/*Son2() :Base2(10)//д����
	{
		cout << "����Son1���캯��" << endl;
	}*/
	Son2(int a) :Base2(a)//��a���������е��вι��죬��ʼ��m_A
	{
		cout << "����Son1���캯��" << endl;
	}
};

void test1()
{
	Son1 s;//�ȵ��ø��๹�죬�ٵ������๹�죬������˳���빹���෴
}

void test2()
{
	Son1 s;//�ȵ��ø��๹�죬�ٵ����������Ա�Ĺ��죬�ٵ��������죬������˳���빹���෴
}

void test3()
{
	Son2 s(100);
	cout << s.m_A << endl;
}

//ע�⣺�����У����죨����Ĭ�Ϲ��죬�вι��죩���������������졢operator=���ǲ��ᱻ����̳���ȥ��

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}