#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public: 

	Person(int age)
	{
		this->m_age = age;
	}
	
	//�����������γ�Ա�����е�thisָ�룬��ָ��ָ���ֵ�������޸�
	void showPerson() const // const Person* const this
	{
		//m_age = 100;//�������ʽ�����ǿ��޸ĵ���ֵ����ָ��ָ���ֵ��this->m_age�������޸�

		//thisָ��ı��ʣ�Person* const this
		//this->NULL;//this��ָ�볣����ָ���ָ�򲻿����޸ģ���ָ��ָ���ֵ�����޸�
		cout << "Person age = " << this->m_age << endl;

		m_A = 100;//�����ϣ��m_A���޸ģ������ᱨ��
	}

	//����showPerson()�Ĺ��ܣ�ֻ�������������д�����ʵ��
	//��const����ָ�볣������const Person* const this
	//��ֹͨ��this->��Ա���� = ֵ�����ʳ�Ա����

	//�����Person* const thisǰ���const�����أ�
	//ͨ���ں������ĺ����const

	void func()
	{
		m_age = 10;
		cout << "func()����" << endl;
	}
	int m_age;

	mutable int m_A;//�������л��߳������У���Щ����������Ȼ���޸ģ�����ؼ���mutable
};

int main()
{
	//������
	const Person p(10);

	//p.m_age = 10;//����,�������޸���ͨ��Ա����
	//const���εı�����Ȼ����ֱ���޸ģ������Լ���޸ģ�
	//mutable�ؼ��־��������˼���޸ģ��Ӷ������޸�mutable���ε�����

	p.m_A = 10;//���ᱨ�������޸�mutable���ε�����

	p.showPerson();//���Է��ʳ�����

	//p.func();//������ֻ�ܵ��ó������������������ͨ��Ա����
	//��������Ե��õĻ����Ϳ��Լ��ͨ����ͨ���������޸���ͨ��Ա���ԣ�����ǲ����Եģ�
}