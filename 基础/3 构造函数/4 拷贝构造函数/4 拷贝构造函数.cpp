#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{
public:

	//�Լ�������вεĹ��캯��
	Test()
	{
		m_x = 0;
		m_y = 0;
	}
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
	//��ͨ��ͬһ����Ķ����ʼ���Լ������Ա���ͨ����˵���������ṩ��һ��Ĭ�ϵĿ�������
	//��û���Լ�����Ŀ������������Զ�����Ĭ�ϵĿ���������
	//��������Լ������˿���������������Լ��Ŀ�������

	//�Լ��ṩ�Ŀ������캯��
	Test(const Test& another)
	{
		cout << "Test(const Test& another)... " << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}

	//�������ṩ�Ŀ������캯��
	//��ͨ��ͬһ����Ķ����ʼ���Լ���Ĭ�ϻ��ṩһ���������캯��������Ϊ��������
	/*Test(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}*/

#if 0
	//=��ֵ����������
	//��ͨ��ͬһ����Ķ���ֵ�Լ������Ա��룬˵���������ṩ��һ��Ĭ�ϵĸ�ֵ����������
	//��û���Լ�����ĸ�ֵ���������������Զ�����Ĭ�ϵĸ�ֵ������������
	//��������Լ������˸�ֵ������������������Լ��ĸ�ֵ����������
	void operator=(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}
#endif
private:
	int m_x;
	int m_y;
};
int main()
{
	Test t1(100,200);

	//ͨ��ͬһ����Ķ����ʼ���Լ�
	//��ʼ��t2��ʱ�򣬵���t2�Ĺ��캯��
	Test t2(t1);
	t2.printT();

	Test t3 = t1;//��Ȼ�ǵ���t3�Ŀ������캯�����ȼ�Test t2(t1);
	//���Է��ֻ����Test(const Test& another)

	//���캯���Ƕ����ʼ����ʱ�����
	Test t4;//t4�Ѿ�ͨ�������޲εĹ��캯����ʼ����
	t4 = t1;//���õĲ���t4�Ŀ������캯��������t4�ĸ�ֵ����������
	//���Է��ֻ����void operator=(const Test& another)
	return 0;
}