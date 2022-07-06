#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�������õ��������ͣ�������֪����ν�������
//�������Զ�����������ͣ���������֪���������
//������������أ������÷������µĺ��塣
//���������������ͣ����ṩ��������ز�����

//���������أ����������������ͣ��ǿ�����ֱ��ͨ�����������
//�����Զ�����������ͣ���ʹ�ò����������������ʱ������ֱ��������Ҫ�Բ������Ĺ��ܽ�������
//ʹ���û��Զ�����������ͣ�Ҳ������������������һ��������ͨ�������������������
class Person
{
public:
	Person(int a, int b) :m_A(a), m_B(b)
	{}

	//ע�⣺thisֻ�����ڷǾ�̬�ĳ�Ա������
	//�Զ��庯��ʵ������������ӣ������Ҫ��Ϊȫ�ֺ���������ͨ����Ԫ����ʵ��
	Person personAddPerson(Person& p)
	{
		Person temp(0, 0);
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	
	//1�����ó�Ա����ʵ�֣�����+��
	Person operator+(Person& p)
	{
		Person temp(0, 0);
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	int m_A;
	int m_B;
};

//2������ȫ�ֺ���ʵ�֣�����+��
Person operator+(Person& p1, Person& p2)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//��������أ����Է�����������
Person operator+(Person& p1, int num)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test1()
{
	Person p1(10, 20);
	Person p2(10, 10);
	
	//�Զ��庯��ʵ�������������
	Person p3 = p1.personAddPerson(p2);
	cout << "p3:" << p3.m_A << "," << p3.m_B << endl;
}

void test2()
{
	Person p1(10, 20);
	Person p2(10, 10);

	//����Person+Person�������������ṩ�Զ����������͵Ĳ���������
	//��Ҫ�û��Լ����ز�����

	//1���ֲ���Ա�������ز�����
	Person p4 = p1.operator+(p2);//�ֲ���Ա�������ʵ���
	//�򻯳�
	//Person p4 = p1 + p2;//���ʹ�����ַ�ʽ�����㣬����ȫ�ֺ����ͳ�Ա�����ṩһ�����������ؼ��ɣ��������ֶ����Ա���

	//2��ȫ�ֺ������ز�����
	Person p5 = operator+(p1, p2);//ȫ�ֺ������ʵ���
	//�򻯳�
	//Person p5 = p1 + p2;//���ʹ�����ַ�ʽ�����㣬����ȫ�ֺ����ͳ�Ա�����ṩһ�����������ؼ��ɣ��������ֶ����Ա���

	cout << "p1:" << p1.m_A << "," << p1.m_B << endl;
	cout << "p2:" << p2.m_A << "," << p2.m_B << endl;
	cout << "p4:" << p4.m_A << "," << p4.m_B << endl;
	cout << "p5:" << p5.m_A << "," << p5.m_B << endl;
}

void test3()
{
	Person p1(10, 20);
	//��������أ����Է�����������
	Person p6 = p1 + 10;
	cout << "p6:" << p6.m_A << "," << p6.m_B << endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}



