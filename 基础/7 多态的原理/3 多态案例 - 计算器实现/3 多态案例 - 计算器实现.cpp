#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0 
//�Ƕ�̬��ʽ��
class calculator
{
public:
	int getResult(string oper)//char oper
	{
		if (oper == "+")//oper == '+'
		{
			return m_A + m_B;
		}
		else if (oper == "-")
		{
			return m_A + m_B;
		}
		else if (oper == "*")
		{
			return m_A * m_B;
		}
		else if (oper == "/")
		{
			return m_A / m_B;
		}
	}

	int m_A;
	int m_B;
};

int main()
{
	calculator c;
	c.m_A = 10;
	c.m_B = 20;
	cout << c.getResult("+") << endl;
}
#endif

//����������룬����ӹ���ʱ����Ҫ�޸�Դ�룬�ҵ����ܳ������⣬ά��������

//���ԭ�򣺿���ԭ��
//		����չ���п��ţ����޸Ľ��йر�

//���ö�̬ʵ�ּ�����

//����
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_A;
	int m_B;
};
//�ӷ���������
class AddCalculator:public AbstractCalculator
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
//�˷���������
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	}
};

//�����������Ҫ�ṩ�����¹��ܣ�ֻ��Ҫ׷�Ӵ��뼴��

int main()
{
	//���ö�̬���ò�ͬ�ļ�������Ĺ���
	AbstractCalculator *c = new AddCalculator;//����ָ��ָ���������
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
}
//��̬������ɶ���ǿ����֯�ṹ��������չ��ǿ