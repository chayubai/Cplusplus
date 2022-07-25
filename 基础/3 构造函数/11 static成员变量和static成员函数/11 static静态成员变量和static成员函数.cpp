#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	//1����̬��Ա����
	
	//static���εľ�̬��Ա����������׶ξͷ������ڴ�
	//������ֻ��������û�з����ڴ棬�����ʼ�����ŷ����ڴ�
	//��̬��Ա���������ж��󶼹���ͬһ������
	static int m_A;

	//2����̬��Ա����
	//���ж��󶼹���ͬһ������
	static void func()
	{
		cout << "���þ�̬func()" << endl;
		m_A = 100;//��̬��Ա�������ܷ��ʾ�̬��Ա����
		//m_C = 200;//��̬��Ա���������ܷ��ʷǾ�̬��Ա����

		//���ڷǾ�̬��Ա�������ǹ������ݣ�����ͬ�������ͬһ����̬����ʱ
		//�޷��������ĸ���������˷Ǿ�̬��Ա����m_C�����о�̬��Ա�������ܷ��ʷǾ�̬��Ա����

		//����̬��Ա���������ھ�̬�����б����ʣ�����Ϊ����ʱ����Ҫ������
	}

	//��ͨ��Ա���������Է�����ͨ��Ա������Ҳ���Է��ʾ�̬��Ա����
	void myfunc()
	{
		m_A = 100;
		m_C = 200;
	}
	int m_C;
private:
	static int m_B;

	static void func2()
	{

	}
};

//������public����privateȨ���µľ�̬��Ա�����ĳ�ʼ����һ��д��������
int Person::m_A = 0;
int Person::m_B = 200;

void test1()
{
	//1��ͨ��������з���
	Person p1;

	cout << p1.m_A << endl;

	//C��C++��static������ͬ���ӳ��ľ�̬�����������������˾�̬����ֻ���ڱ��ļ���ʹ��
	Person p2;
	p2.m_A = 200;

	cout << p1.m_A << endl;
	cout << p2.m_A << endl;

	//2��ͨ���������ʳ�Ա����

	//���ھ�̬�����������κ�һ�����󣬿��Բ���Ҫͨ���������
	cout << Person::m_A << endl;

	//ע�⣺���ھ�̬��Ա�������������֣���һͨ�����캯����ʼ����̬��Ա�������ڶ��ַ�ʽ�ﲻ����ʼ��Ҫ��

	//��̬��Ա������Ҳ���з���Ȩ�޵ģ�˽��Ȩ�������޷�����
	//cout << Person::m_B << endl;//����
}

void test2()
{
	//1��ͨ���������
	Person p1;
	p1.func();
	//2��ͨ����������
	Person::func();

	//Person::func2();//��̬��Ա����Ҳ���з���Ȩ�޵�
}
int main()
{
	//test1();

	return 0;
}
#endif

#include <iostream>
using namespace std;
class AA
{
public:
	AA(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	//��ȡ˽�е�  ��̬��Ա����  ����Ҫ���static�ĳ�Ա����
	//�����������ֵ����������
	static int& getC()
	{
		return m_c;
	}

	//public��static��̬��Ա����
	static int m_d;

	int getD()
	{
		m_d++;
		return m_d;
	}
private:
	int m_a;
	int m_b;
	//private��static��̬��Ա����
	static int m_c;
};

int AA::m_c = 100;
int AA::m_d = 200;

int main()
{
	AA a1(10, 20);//a1.m_a��a1.m_b��a2.m_a��a2.m_b���������
	AA a2(20, 40);
	//static�����ǹ����
	cout << a1.getC() << endl;
	cout << a2.getC() << endl;

	//ͨ����������public�ľ�̬��Ա����
	AA::m_d = 200;
	//ͨ������.���г�Ա����
	a1.m_d = 300;

	//ͨ����������public�ĳ�Ա����
	//cout << AA::getD() << endl;
	//�Ǿ�̬��Ա�������޷����ʾ�̬��Ա��������Ҫ��static�������Ϊ��̬��Ա����
	
	//ͨ������.���г�Ա����
	cout << a1.getD() << endl;

	//ͨ���������ʹ���get��Ա������������private�ĳ�Ա����
	cout << AA::getC() << endl;

	AA::getC() = 300;//�������ÿ�����ֵ������Ա������޸�
	//ͨ������.���г�Ա������������private�ĳ�Ա����
	
	cout << a1.getC() << endl;

	return 0;
}