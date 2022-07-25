#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//���³��������⣬��֪����ô���
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
		m_a = 0;
		strcpy(m_name, "");
	}
	Test(int a, const char* name)
	{
		cout << "Test(int ,const char*)" << endl;
		m_a = a;
		int len = strlen(name);
		m_name = (char*)malloc(sizeof(len + 1));
		if (m_name == NULL)
			return;
		strcpy(m_name, name);
	}
	void printT()
	{
		cout << "printT():" << m_a << "," << m_name << endl;//����������
	}
	~Test()
	{
		if (m_name != NULL)
		{
			cout << "~Test()" << endl;
			free(m_name);
			m_name = NULL;
		}
	}
private:
	int m_a;
	char* m_name;
};

//C�����У����ϴ�������
void test1()
{
	Test* tp = (Test*)malloc(sizeof(Test));
	//�������һ����ʽ��init(),����ʼ��m_a��m_name
	//tp->printT();
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}

//C++�����У����ϴ�������
void test2()
{
	Test* tp = new Test(10, "zhangsan");//�����вι��캯��    
										//tp = new Test;�����޲ι��캯�������������tp = new Test();
	tp->printT();

	//ע�⣺tp��ջ�Ͽ��ٵĿռ䣬��tpָ��Ŀռ��Ƕ��Ͽ��ٵ�
	if (tp != NULL)
	{
		delete tp;//�ͷ�tpָ��Ŀռ�֮ǰ�����������������ͷŶ��ϵ�malloc�����ڶ��ϵ�m_nameָ��Ŀռ�
		tp = NULL;
	}

	//�������delete tp;��Ϊfree(tp);�򲻻ᴥ������������ֱ���ͷ���tpָ��Ŀռ䣬����m_nameָ��Ŀռ�δ�ͷţ��ڴ�й¶

	//ע�⣺������������Կ��ٵ����������ñ������ṩ�Ŀ������캯�������ǳ���������������ظ��ͷŶ����ڴ������
	//��ʹ��delete�ͷſռ�ʱ��������������
}

//malloc��free�Ǻ�������׼�⣺stdlib.h
//new �ڶ��ϳ�ʼ��һ�������ʱ�򣬻ᴥ������Ĺ��캯����malloc����
//free �����ܴ���һ�������������������delete�ᴥ����������

int main()
{
	//test1();
	test2();
	return 0;
}