#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//���ö�̬ʵ�ּ�����

//����
class AbstractCalculator
{
public:

	//���������麯����ʵ��û�����壬�����ô��麯������
	/*virtual int getResult()
	{
		return 0;
	}*/

	//���麯��
	//���һ�����а����˴��麯������ô�������޷�ʵ�������������ͨ����Ϊ ������
	//����������࣬Ҳ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
	virtual int getResult() = 0;

	int m_A;
	int m_B;
};
//�ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};
//������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

class Test :public AbstractCalculator
{
	/*int getResult()
	{
		return 0;
	}*/
};
void test1()
{
	//���ö�̬���ò�ͬ�ļ�������Ĺ���
	AbstractCalculator* c = new AddCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;

	c = new SubCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;
	c = NULL;
	//�������������и�����麯���ò��������Ը�Ϊ���麯��
}

void test2()
{
	//AbstractCalculator abc;//���������಻��ʵ��������
	
	//Test t;//����̳г����࣬�������д�麯����Ҳ����ʵ�������󱨴�
	
	//��������������У��Ը����麯����д
}

int main()
{
	return 0;
}