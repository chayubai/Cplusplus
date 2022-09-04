#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	/*{//ģ���еĳ�Ա��������ʵ��
		this->m_Name = name;
		this->m_Age = age;
	}*/

	void showPerson();
	/*{
		cout << "������" << this->m_Name << "�����䣺" << this->m_Age << endl;
	}*/

	//��Ԫ��������ʵ��
	//����1��
	//template<class T1, class T2>//�����ģ�����������Ǻ���ģ�����������������ͨ����������
	//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);//��Ԫ��������ֱ�ӷ������ڵ�˽������
	
	//����2��
	//�÷�������Ҫ�ټ�ģ������
	friend ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p);
private:
	T1 m_Name;
	T2 m_Age;
};

//template<class T1, class T2>
//Person::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}//����ʹ����ģ����Ҫģ������б�

template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)//��ģ�������Person<T1,T2>����ģ�������������
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "������" << this->m_Name << "�����䣺" << this->m_Age << endl;
}

//����1��
//���Ǻ���ģ���ʵ��
template<class T1, class T2>
ostream& operator<<(ostream& os, Person<T1, T2>& p)//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);������ͨ��������Ԫ����
{
	os << "������" << p.m_Name << "�����䣺" << p.m_Age;
	//���������ض�������ԭ�еĲ��������������������͵����㣬
	//�Դﵽ�ͺ�������ʹ��ԭ�еĲ�������ʵ�ַ������������͵�����
	return os;
}

//����2��
//���Ǻ���ģ���ʵ��
template<class T1, class T2>
ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p)//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);������ͨ��������Ԫ����
{
	os << "������" << p.m_Name << "�����䣺" << p.m_Age;
	//���������ض�������ԭ�еĲ��������������������͵����㣬
	//�Դﵽ�ͺ�������ʹ��ԭ�еĲ�������ʵ�ַ������������͵�����
	return os;
}
//���������ݺ����������ɷ��ţ���ȥ�Ҷ�Ӧ�ĺ�������һ�£������Ҳ�����ʹ�ñ����޷��������ⲿ����
//����1��
//����Ԫ��������ʱ����һ��ģ��template<class T1, class T2>//Windows��֧�֣���Linux�²�֧��
//����2��
//����Ԫ������������friend ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p)��Linux�²���һ��
//����3���ղ���ģ���б���ǰ��������ģ�壬������ʵ�ַ��롣����11 ��ģ��������Ԫ�����Լ������
//����4���ղ���ģ���б���ǰ��������ģ�壬������ʵ��һ�𡣼���11 ��ģ��������Ԫ�����Լ������
int main()
{
	Person<string, int> p("Tom", 10);
	//p.showPerson();
	cout << p << endl;
	return 0;
}