#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;

//ʵ���Զ����������͵����������
class Person
{
public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//1�����ó�Ա����ʵ�֣�����<<��
	void operator<<(Person& p)
	{

	}
	//������������Ʋ�����ʱ��p.operator<<(cout),��p<<cout
	//���һ�����Ʋ����������ó�Ա����ʵ��<<����

	//���裬int m_A;��int m_B; ��˽�г�Ա
	//������ȫ�ֺ���ʵ��<<����������ʱ����ϣ���������˽�г�Ա��������Ԫ����
	//friend ostream& operator<<(ostream& cout, Person& p);//���Է������е�����λ��
	int m_A;
	int m_B;
};

//2������ȫ�ֺ���ʵ�֣�����<<��
//void operator<<(ostream &cout,Person &p)
//{
//	cout << "m_A = " << p.m_A << ",m_B = " << p.m_B;
//}
//void test1()
//{
//	Person p1(10, 20);
//
//	//����cout << int�������ͣ��������ṩ�������������͵Ĳ���������
//	cout << p1.m_A << endl;
//
//	//����cout << Person�������ͣ������������ṩ�Զ����������͵Ĳ���������
//	//��Ҫ�û��Լ����ز�����
//	cout << p1;//���ʣ�operator<<(cout,p1)
//}

//�������Ͳ������ص�����
ostream& operator<<(ostream& out, Person& p)//operator<<(cout,p1)
{
	cout << "m_A = " << p.m_A << ",m_B = " << p.m_B;
	return cout;
	//out��cout�ı�����������ԭ���ͱ������Ի���
}
void test2()
{
	Person p1(10, 20);
	//�������ֵvoid����void << endl;����ʵ������<<����
	cout << p1 << "hello" << endl;//��ʽ��̣���������Ϊ���ã��ҷ���ֵΪcout
}

int main()
{
	//test1();
	test2();
	return 0;
}
//��Ҫ���ò��������أ�����������
//���ܶ������������ͽ�������
//�����Զ����������ͣ�������ֱ����cout << ���
//��Ҫ�������Ʋ�����
//������ó�Ա�������أ��޷�ʵ����cout����࣬��˲��ó�Ա��������
//����<<����������Ҫ֪��cout����������ostream&