#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person 
{
public:
	Person(int age)
	{
		cout << "�����вι��캯��" << endl;
		this->m_age = age;
	}
	void showAge()
	{
		cout << "����Ϊ��" << m_age << endl;
	}
	~Person()
	{
		cout << "������������" << endl;
	}
	int m_age;
};

//����ָ��
//�����й��Զ������͵Ķ����ö�������Զ����ͷ�
class SmartPoint
{
public:
	SmartPoint(Person*person)
	{
		this->m_person = person;
	}

	//��Ա����ʵ�֣�����->�����
	Person* operator->()
	{
		return this->m_person;
	}

	//��Ա����ʵ�֣�����*�����
	Person& operator*()
	{
		return *this->m_person;//*m_person���������͵Ķ�������˷���ֵʹ����������
		//���ض������ͣ�ֻ�ǵ��ÿ������죬����ԭ������
	}

	//��Ʋ���������ʱ���������������͵Ĳ������ó��������ͺͷ���ֵ

	~SmartPoint()
	{
		if (this->m_person != NULL)
		{
			delete this->m_person;
			this->m_person = NULL;
		}
	}
private:
	Person* m_person;//�������������new������ָ��
};

void test1()
{
	//���ٵ�ջ�ϣ��Զ���������
	Person p1(20);

	Person* p = new Person(18);//��������
	p->showAge();//����(p->)->showAge();p->������ָ��
	(*p).showAge();//*p�����ظ��ࣨ�ͣ��Ķ���
	delete p;//�����delete�����ᴥ��������������

	//������̫�࣬����������delete
	//�����Զ���һ������ָ���࣬ͨ��������������������new������person���ͷŲ���
}

void test2()
{
	//������̫�࣬����������delete
	//�����Զ���һ�� " ���� ָ�� "�࣬ͨ��������������������new������person���ͷŲ���
	//��sp��ջ�Ͽ��ٵĿռ䣬��spִ�н��������Զ��������������������Ӷ��Զ��ͷ�new�����Ŀռ�
	SmartPoint sp(new Person(18));//sp���ٵ�ջ��

	//����sp����ָ�룬��������ô��������˿���ͨ������->��*������ʵ��
	sp->showAge();//ʵ���ϣ�(sp->)->showAge()����������Ϊsp->showAge()
	(*sp).showAge();//���ʣ�sp.operator*().showAge();
	//�Ӷ�ʵ����sp�����ܣ�����ָ�룬���ϴ���Person�����ʱ�����赣��û���ͷſռ������
}
int main()
{
	//test1();
	test2();
	return 0;
}