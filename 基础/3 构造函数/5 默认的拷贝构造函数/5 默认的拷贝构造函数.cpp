#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;
class A
{
public:
	//��ʽ���޲ι��캯��
	A()
	{
		m_a = 0;
		m_b = 0;
	}
	//��ʽ���вι��캯��
	A(int x, int y)
	{
		m_a = x;
		m_a = y;
	}

#if 0
	//��ʽ�Ŀ������캯��
	A(const A& another)
	{
		cout << "Test(const Test& another)... " << endl;
		m_a = another.m_a;
		m_b = another.m_b;
	}
#endif

private:
	int m_a;
	int m_b;
};
//���У�����Ĭ�ϵ��޲ι��캯����
//1����û���κ���ʽ�Ĺ��캯������ʽ���޲ι��졢��ʽ���вι��졢��ʽ�Ŀ������죩��ʱ��Ĭ���޲ι��캯���ͻ���֡�
//���У�����Ĭ�ϵĿ������캯����
//2����û����ʽ�Ŀ������캯����Ĭ�ϵĿ������캯���ͻ���֡�
//���У�����Ĭ�ϵ�����������
//3����û����ʽ������������Ĭ�ϵ����������ͻ���֡�
int main()
{
	A a1;

	//ͨ��ͬһ����Ķ����ʼ���Լ�
	A a2(a1);

	return 0;
}