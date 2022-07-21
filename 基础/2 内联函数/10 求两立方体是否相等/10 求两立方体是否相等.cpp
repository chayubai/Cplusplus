#define _CRT_SECURE_NO_WARNINGS 1

//����������ࣨCube����������������������
//�����������壬�Ƿ���ȣ�ȫ�ֺ����ͳ�Ա������

#include <iostream>
using namespace std;

//��������
class Cube
{
public:
	void setABC(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	int calculateS()
	{
		return (m_a * m_b) * 2 + (m_a * m_c) * 2 + (m_b * m_c) * 2;
	}
	int calculateV()
	{
		return m_a * m_b * m_c;
	}
	int getA()
	{
		return m_a;
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_c;
	}
	//��Ա����
	bool judgeCube(Cube& another)
	{
		//if (m_a == another.getA() && m_b == another.getB() && m_c == another.getC())
		//ͬ��֮����˽��
		/*if (m_a == another.m_a && m_b == another.m_b && m_c == another.m_c)
		{
			return true;
		}
		else
		{
			return false;
		}*/
		return m_a == another.m_a && m_b == another.m_b && m_c == another.m_c;
	}
private:
	int m_a;//�ɶ�����д
	int m_b;//�ɶ�����д
	int m_c;//�ɶ�����д
};

//ȫ�ֺ���
bool judgeCube(Cube& c1, Cube& c2)//const��Ա�������ܵ��÷�const��Ա��������Ϊ��const��Ա�������ܻ�ı��Ա������ֵ��
{//judgeCube(const Cube& c1, const Cube& c2)//���ǲ��Ե�
	/*if (c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC())
	{
		return true;
	}
	return false;*/
	bool ret = c1.getA() == c2.getA() && c1.getB() == c2.getB() && c1.getC() == c2.getC();
	return ret;
}

void test1()
{
	Cube c1;
	c1.setABC(10, 20, 30);
	cout << "c1�������" << c1.calculateV() << endl;
	cout << "c1�������" << c1.calculateS() << endl;
}

void test2()
{
	Cube c1;
	c1.setABC(10, 20, 30);

	Cube c2;
	c2.setABC(10, 20, 30);

	//ȫ�ֺ����ж��Ƿ����
	if (judgeCube(c1, c2) == true)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

void test3()
{
	Cube c1;
	c1.setABC(10, 20, 30);

	Cube c2;
	c2.setABC(10, 20, 30);

	//�ֲ������ж��Ƿ����
	cout << "--------------------" << endl;

	if (c1.judgeCube(c2) == true)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}
void test4()
{
	/*void func(const Cube & cub)//Ϊʲô���ܼ�const����Ϊ�޷���֤��Ա�������Ƿ��޸��˳�Ա����
	{
		cub.getA();//getA()���ܻ��޸�m_a��ֵ
	}*/
	//��int getA()constʱ�����ᱨ��

}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}
