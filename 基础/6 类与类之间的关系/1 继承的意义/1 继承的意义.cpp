#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class News
{
public:
	void header()
	{
		cout << "������ͷ��" << endl;
	}
	void footer()
	{
		cout << "�����ĵײ�" << endl;
	}
	void leftList()
	{
		cout << "����������б�" << endl;
	}
	void content()
	{
		cout << "���Ų���..." << endl;
	}
};

class Sport
{
public:
	void header()
	{
		cout << "������ͷ��" << endl;
	}
	void footer()
	{
		cout << "�����ĵײ�" << endl;
	}
	void leftList()
	{
		cout << "����������б�" << endl;
	}
	void content()
	{
		cout << "���籭����..." << endl;
	}
};
#endif

//���ü̳�ģ����ҳ
//�̳е��ŵ㣺�����ظ����룬�ṩ���븴����
class BasePage
{
public:
	void header()
	{
		cout << "������ͷ��" << endl;
	}
	void footer()
	{
		cout << "�����ĵײ�" << endl;
	}
	void leftList()
	{
		cout << "����������б�" << endl;
	}
};

//�̳е��﷨��class ���� : �̳з�ʽ ����
//News      ����   ������
//BasePage  ����   ����
//������ - �������ԣ����� - ͻ�����ԣ�

class News :public BasePage
{
public:
	void content()
	{
		cout << "���Ų���..." << endl;
	}
};

class Sport :public BasePage
{
public:
	void content()
	{
		cout << "���籭����..." << endl;
	}
};

int main()
{
	News ns;
	ns.header();
	ns.footer();
	ns.leftList();
	ns.content();

	Sport sp;
	sp.header();
	sp.footer();
	sp.leftList();
	sp.content();
}