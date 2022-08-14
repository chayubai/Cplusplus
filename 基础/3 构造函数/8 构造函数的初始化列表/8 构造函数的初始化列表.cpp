#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
class Person
{ 
public:
	/*Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}*/

	//������ʼ����Ա������д����
	/*Person() :m_A(10), m_B(20)
	{

	}*/

	//���캯���ĳ�ʼ���б���ʼ���б���Ը������Ա������ʼ��
	Person(int a, int b) :m_A(a), m_B(b)//
	{
		//����д����������
	}
	int m_A;
	int m_B;
};

int main()
{
	Person p(10, 20);

	return 0;
}
#endif

class A
{
public:
	A(int a)
	{
		cout << "A(int a)..." << endl;
		m_a = a;
	}
	void printA()
	{
		cout << "m_a = " << m_a << endl;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int m_a;
};
class B
{
public:
	//B(A &a1, A &a2,int b)
	//{
	//	cout << "B()..." << endl;
	//	m_b = b;
	//	//����A m_a;�޷�ͨ�����캯�����г�ʼ��
	//	//m_a1(a1);//���ԣ�����������������
	//	//m_a1 = a1;//���ԣ�������õ���m_a1��=����������
	//}

	B(A& a1, A& a2, int b) :m_a1(a1),m_a2(a2)//m_a1(a1)����m_a1�Ŀ�������
	{
		cout << "B(A& a1, A& a2, int b)..." << endl;
		m_b = b;
		//�����ʼ���б�Ϊ�˽���Գ�Ա����Ϊ������Ķ�����г�ʼ��,Ҳ�ܳ�ʼ����ͨ��Ա����
	}
	B(int a1, int a2, int b) :m_a1(a1),m_a2(a2)//m_a1(a1)����m_a1���вι���
	{
		cout << "B(int a1, int a2, int b)..." << endl;
		m_b = b;
	}
	//��������Ա��˳�����ʼ���б��˳���޹�
	//���Ǹ���Ա�����Ķ���˳���йأ���A m_a1;A m_a2;�Ķ���˳��ı�һ�£��鿴�ṹ
	void printB()
	{
		cout << "m_b = " << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}

	~B()
	{
		cout << "~B()..." << endl;
	}
private:
	int m_b;
	A m_a1;
	A m_a2;
};

class ABC
{
public:
	ABC(int a,int b ,int c, int m):m_m(m)
	{
		cout << "ABC(int ,int ,int)" << endl;
		m_a = a;
		m_b = b;
		m_c = c;
		//m_m = m//����
	}
	~ABC()
	{
		cout << "~ABC() " << endl;
	}
private:
	int m_a;
	int m_b;
	int m_c;
	const int m_m;//�����ĸ�ֵ��������ڳ�ʼ���б���
};
class ABCD
{
public:
	ABCD(int a, int b, int c,int d,int m):m_abc(a,b,c, m),m_d(d)
	{
		cout << "ABCD(int a, int b, int c,int d)" << endl;
	}
	ABCD(ABC &abc, int d) :m_abc(abc), m_d(d)
	{
		cout << "ABCD(ABC &abc, int d)" << endl;
	}
	~ABCD()
	{
		cout << "~ABCD() " << endl;
	}
private:
	int m_d;
	ABC m_abc;
};
int main()
{
	A a1(10),a2(100);

	B b(a1,a2,100);
	b.printB();

	cout << "----------" << endl;

	B b(10, 20, 100);
	b.printB();

	cout << "----------" << endl;

	ABC abc(10, 20, 30,666);

	ABCD abcd1(1, 2, 3, 4,666);
	ABCD abcd2(abc, 4);
	return 0;
}