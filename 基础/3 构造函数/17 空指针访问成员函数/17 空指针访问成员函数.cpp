#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public:

	void showClass()
	{
		cout << "class Name is Person" << endl;
	}
	void showAge()
	{
		/*if (this == NULL)
		{
			return;
		}*/
		m_age = 0;
		cout << "age = " << this->m_age << endl;
	}
	int m_age;
};

int main() 
{
	Person* p = NULL;
	p->showClass();

	//p->showAge();//��������thisָ��p = NULL���ÿ�ָ�����m_age�����´���

	//�����Ҫ��һ��if�жϣ���ֹ�����������
}