#define _CRT_SECURE_NO_WARNINGS 1

//�ļ�������ļ�������
//iostreamͬʱ�������������
//istream���������				ostream���������
//ifstream���ļ��������		ofstream���ļ��������
//fsteamͬʱ���ļ������������

#include <iostream>
using namespace std;

#include <fstream>//�ļ���

#include <string>

void test1()
{
	//д�ļ� --���  ������������ļ�
	ofstream ofs;//ofstream ofs("./test.txt", ios::out | ios::trunc);

	ofs.open("./test.txt", ios::out | ios::trunc);//���ô򿪷�ʽ���Լ�·��

	if (!ofs.is_open())//����ֱ��ʹ��!ofs
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//ofstream����������<<������
	ofs << "�����������" << endl;//���ļ�д����
	ofs << "���䣺999" << endl;
	ofs << "�Ա���" << endl;

	//�ر��ļ�
	ofs.close();
}

void test2()
{
	//���ļ� --���� - ���ļ����뵽����
	
	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ��
	/*char buf[1024] = { 0 };
	//ifstream��������>>������
	while (ifs >> buf)//������������һ��һ�е����뵽buf��
	{
		cout << buf << endl;//��һ�����һ��
	}*/

	//�ڶ��ַ�ʽ��
	/*char buf[1024] = {0};

	while (ifs.getline(buf,sizeof(buf)))//������������һ��һ�е����뵽buf�� - ��Ա����
	{
		cout << buf << endl;
	}
	����
	while (!ifs.eof())//eof �����ļ�β
	{
		ifs.getline(buf,sizeof(buf))//����strlen
		cout << buf << endl;
	}
	*/

	//�����ַ�ʽ��
	/*string buf;

	while (getline(ifs,buf))//������������һ��һ�е����뵽buf�� - ȫ�ֺ���
	{
		cout << buf << endl;
	}*/

	//�����ַ�ʽ��
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//����
	/*while ((ifs.get(c)))
	{
		cout << c;
	}*/

	//�ر��ļ�
	ifs.close();
}

int main()
{
	//test1();
	test2();
	return 0;
}