#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//extern������Ҳ���const���������ڴ�
//1����const����ȡ��ַ���������ڷ��ű��У��������ʱ�ڴ�
void test1()
{
	const int a = 10;
	int* p = (int*)&a;//�������ʱ�ڴ�
}

//2��ʹ����ͨ��������ʼ��const����
void test2()
{
	int a = 10;
	const int b = a;//������ڴ�
	int* p = (int*)&a;
	*p = 100;//�޸ĳɹ�
	cout << "b = " << b << endl;
}

#include <string>
//3�������Զ����������ͣ���constҲ������ڴ�
struct Person
{
	string m_Name;//����ͷ�ļ�#include <string>
	int m_Age;
};
void test3()
{
	const Person p;
	//p.m_Age = 10;ֱ���޸�ʧ��
	
	//���ͨ��ָ���޸ģ��ɹ�
	Person* pp = (Person*)&p;
	(*pp).m_Name = "Tom";
	pp->m_Age = 10;
	cout << "������" << p.m_Name << ",���䣺" << p.m_Age << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	return 0;
}