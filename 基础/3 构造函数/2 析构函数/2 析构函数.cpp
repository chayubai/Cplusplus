#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
#include <string.h>
using namespace std;
class Test
{
public:

	//���캯��
	Test(int x ,int y)
	{
		m_x = x;
		m_y = y;
		name = (char*)malloc(100);
		strcpy(name, "zhangsan");
		//���ڵ���������������ڣ���ʱm_x��m_y��name��ϵͳ������
		//��ʱ��malloc���ٵ�100�ֽڵĿռ䣬�����ڴ�й¶
		//Ϊ�˽��������⣬������������ʵ�ֶ�malloc���ٵ�100�ֽڵĿռ�Ļ���
		//����m_x��m_y��name��ϵͳ����ǰ�������ٱ�malloc���ٵ�100�ֽڵĿռ�
	}

	//���������͹��캯������û�з���ֵ��
	//��������û���β�
	~Test()
	{
		cout << "~Test()..." << endl;
		if (name != NULL)
		{
			free(name);
			cout << "free succ..." << endl;
		}
	}
private:
	int m_x;
	int m_y;
	char* name;
};

void test()
{
	Test t(10,20);
	//t��test�����У�����������
	//�ڶ����Ҫ������������֮ǰ�����Զ�������������
	//ͨ�����Կ��Թ۲쵽�������Ե���}��ʱ�������~Test()����
}

int main()
{
	test();
	return 0;
}