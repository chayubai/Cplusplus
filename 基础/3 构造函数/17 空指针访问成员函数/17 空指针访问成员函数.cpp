#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{ 
public:

	void showClass()//�����Ա����û��ʹ��this
	{
		cout << "class Name is Person" << endl;
	}
	void showAge()//�����Ա����ʹ����this
	{
		//��Ҫ��һ��if�жϣ���ֹ��ָ�������
		/*if (this == NULL)
		{
			return;
		}*/
		m_age = 0;
		cout << "age = " << m_age << endl;//this->m_age �ÿ�ָ�����m_age
	}

	int m_age;
};

int main() 
{
	Person* p = NULL;
	p->showClass();//��һ���������гɹ�����Ϊû��thisָ��

	//p->showAge();//��������thisָ��p = NULL���ÿ�ָ�����m_age�����´���

	//�����Ҫ��һ��if�жϣ���ֹ�����������
}
//�ܽ᣺��ָ����ʳ�Ա����
//1�����Ա������û���õ�thisָ�룬�����ÿ�ָ����ó�Ա����
//2�����Ա�������õ���this����ô���this��Ҫ���жϣ���ֹ��ָ�������