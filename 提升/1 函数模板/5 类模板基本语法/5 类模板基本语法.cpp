#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//��ģ������﷨��template<class T1,class T2,...>�����������Ķ��壬����ֻ�Ե�һ������Ч
//T,T2����������
template<class NAMETYPE,class AGETYPE = int>//����ģ��Ҳ������template<class T1,class T2,...>
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "������" << this->name << "�����䣺" << this->age << endl;
	}
	NAMETYPE name;
	AGETYPE age;
};

void test1()
{
	//��ģ��ͺ���ģ�������
	
	//1����ģ�岻����ʹ���Զ������Ƶ���ֻ������ʽָ������
	//Person p1("�����", 100);//ʹ���Զ������Ƶ��ᱨ��
	//���ڿ����Ƶ��Ĳ�һ�£��磺"�����"��char*���ͣ������Ŀ�����string����

	Person<string, int> p1("�����", 100);//��ʽָ�����͡�ҲҪ����#include <string>ͷ�ļ�
	p1.showPerson();
}

void test2()
{
	//��ģ��ͺ���ģ�������

	//2����ģ���п�����Ĭ�ϲ���template<class NAMETYPE,class AGETYPE = int>��ʹ�õ�ʱ��ģ������б���Բ�������
	Person<string> p2("�����", 100);
	p2.showPerson();
}
int main()
{
	//test1();
	test2();
	return 0;
}