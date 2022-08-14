#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
#include <string.h>

//���캯�������ã���ʼ������
//�������������ã��������ϵı��������ͷ�
//��������Կ��ٵ����������ñ������ṩ�Ŀ������캯�������ǳ���������������ظ��ͷŶ����ڴ������

class Teacher
{
public:
	Teacher(int id, const char* name)//���ڽ��ܵ�"name"��һ���ַ�����������������const char*�����ʹ�� char*,C++����Ҫǿת
	{
		cout << "Teacher(int id, const char* name)..." << endl;
		//��ֵid
		m_id = id;

		//��ֵname
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);//����"\0"�ַ�
		strcpy(m_name, name);
	}
	//ֻҪ��Ա������malloc���ٵĿռ䣬����Ҫ�ֶ���ʽ���ṩһ������������������ͷ�malloc���ٵĿռ�
	~Teacher()
	{
		cout << "~Teacher()..." << endl;//���������ͷ�m_name
		if (m_name != NULL)//��t2����������������ʱָ��Ŀռ�黹���˲���ϵͳ����t2.m_name = NULLʱ��
			//��t2.m_name����NULL�����ͷŲ������Լ��Ŀռ䣬����
		{
			free(m_name);
			m_name = NULL;
		}
	}
	void printT()
	{
		cout << "id = " << m_id << " name = " << m_name << endl;
	}
	
#if 0
	//�������ṩ��Ĭ�Ͽ������캯�� - �򵥿��� - ǳ����
	Teacher(const Teacher& another)
	{
		//ֵ�ĸ�ֵ����
		m_id = another.m_id;
		m_name = another.m_name;//������������t1��t2��m_nameָ��ͬһ��ռ�(��ַ��ͬ)
	}
#endif

	//ֻҪ��Ա�����ж������ٵ�ָ�룬����Ҫ�ֶ���ʽ���ṩһ���������캯����������������
	Teacher(const Teacher& another) // ���
	{
		m_id = another.m_id;//m_name = another.m_name;������ʹ�ô��д���

		int len = strlen(another.m_name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, another.m_name);
	}

	int m_id;
	char *m_name;
};

void test1()
{
	Teacher t1(1, "zhangsan");
	t1.printT();
}

//��ֹ�ڴ�й¶�����ٵĿռ�û���ͷţ�����ֹ����ͷ�ͬһ��ռ�
void test2()
{
	Teacher t1(1, "zhangsan");//�ȵ���t1���вι��캯����
	t1.printT();
	//������ǳ����
	Teacher t2(t1);//�ٵ���t2��Ĭ�Ͽ������캯�����ٵ���t2�������������ٵ���t1����������

	//��ʱ��t1.name��t2.name��ָ��malloc�Ŀռ�
	//������t2����������ʱ�����ٵĿռ䱻�ͷ��ˣ�t2.name=NULL����ʱt1.nameָ���malloc�Ŀռ�Ϊ���˵Ŀռ䣬ָ�벻ΪNULL���ٵ���t1��������������ͱ���
	t2.printT();

	//��ν��ǳ���������� ���ڳ�����ͨ�����ñ�����Ĭ�ϵĿ������캯�����µ����� - ������
	//��ʽ����ƿ������캯������������ֵ������һ���ռ��С�
	//���ٵ������ռ䣬�ֱ�ָ���Ӧ��name���������Ե�����������ʱ���ͻ��ͷŸ��ԵĿ��ٵĿռ�
}
int main()
{
	//test1();
	test2();
	return 0;
}
//�����ǳ����
//ϵͳ���ṩ�Ŀ����������м򵥵�ֵ����

//�ܽ᣺�����������ָ������ռ�����ݣ���ô�򵥵�ǳ�����ᵼ���ظ��ͷ��ڴ���쳣
//
//����������⣬��Ҫ�����Լ��ṩ�������캯�����������