#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <fstream>//�ļ���

#include <string>

void test1()
{
	const char* fileName1 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\����\\1 ��̬����ת��\\14 �ı��ļ�����\\source.txt";
	const char* fileName2 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\����\\1 ��̬����ת��\\14 �ı��ļ�����\\target.txt";
	
	//���ļ� -- ���ļ��ж�ȡ������
	ifstream ifs(fileName1, ios::in);
	//д�ļ� -- �ӳ�����������ļ���
	ofstream ofs(fileName2, ios::out | ios::trunc);//ios::app���ļ�����׷������

	if (!ifs)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	char c;
	while ((ifs.get(c)))
	{
		cout << c;
		ofs.put(c);
	}

	//�ر��ļ�
	ifs.close();
	ofs.close();
}

int main()
{
	test1();
	return 0;
}