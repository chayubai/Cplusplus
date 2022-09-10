#define _CRT_SECURE_NO_WARNINGS 1

//��׼�쳣���ʹ�ã�
#include <iostream>
using namespace std;

#include <stdexcept>//standard exception
class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("���������0~150֮��");//out_of_range()�������󣬵���out_of_range����вι���
		}
		else
		{
			this->m_Age = age;
		}
	}
	int m_Age;
};
void test()
{
	try
	{
		Person p(151);
	}
	//catch (out_of_range& e)//��ͨ����
	catch (exception& e)//��̬����exception����ϵͳ�������쳣�Ļ��ࡣ exception& e = out_of_range();��������ָ���������
	{
		cout << e.what() << endl;
		//what()��out_of_range�쳣���е�һ����Ա���������ڴ�ӡ�쳣��Ϣ������ֵ����Ϊconst char*
		//�Ǽ̳��˻���exception�ķ���
		//��ˣ��쳣����ʹ�û�����Ϊ�β����ͣ����Խ���������������what����

	}
}

int main()
{
	test();
	return 0;
}