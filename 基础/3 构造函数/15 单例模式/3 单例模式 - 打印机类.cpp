#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
#include <string>
class Printer
{
public:
	static Printer* getInstance()
	{
		return printer;
	}
	void printText(string text)
	{
		m_count++;
		cout << text << endl;
	}

	int m_count;
private:
	Printer() 
	{ 
		m_count = 0;
		cout << "��ӡ������" << endl;
	}

	Printer(const Printer&p){}
private:

	static Printer* printer;
};

Printer* Printer::printer = new Printer;

void test1()
{
	cout << "main����" << endl;

	//ע�⣺static Printer* printer;�Ǳ���׶η����ڴ�
	//��ʱ����׶ξͻ�ִ�У�Printer* Printer::printer = new Printer;
	//��ʱ�ȵ���printer���޲ι��죬�ٵ���main����

	//�����⣺���ʵ�ֳ���δ����ǰ���ʹ�ӡhello world
}

void test2()
{
	//1��ͨ��һ���� ֻ��ʵ����Ψһ��һ������
	//2��˽�л�-Ĭ�Ϲ��캯�����������캯����Ψһʵ��ָ��
	//3�������ṩgetInstance�ӿڣ���ָ�뷵��
	Printer* p = Printer::getInstance();
	p->printText("��ְ֤��");
	p->printText("��ְ֤��");
	p->printText("��н����");
	p->printText("��������");

	cout << "��ӡ��ʹ�ô�����" << p->m_count << endl;

	Printer* p2 = Printer::getInstance();
	p2->printText("��������");

	cout << "��ӡ��ʹ�ô�����" << p->m_count << endl;
	cout << "��ӡ��ʹ�ô�����" << p2->m_count << endl;

	//�������޷�����m_count�ģ���Ϊ����û�б������������಻���пռ�
	//cout << "��ӡ��ʹ�ô�����" << m_count << endl; 
	
	//��̬��Ա���������������ڶ��󣬿���ͨ������::��̬��Ա����/��̬��Ա��������
	//cout << "��ӡ��ʹ�ô�����" << Printer::m_count << endl; 

}
int main()
{
	//test1();
	test2();
	return 0;
}