#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int k = 1000;
int main()
{
	int k = 10;//�ֲ���������
	cout << "�ֲ�k = " << k << endl;

	//::�������������ǰ��ʲô����д����ʾȫ��������
	//ȫ�ֱ�����������
	cout << "ȫ��k = " << ::k << endl;
	//ʹ��std�������µ�cout
	std::cout << "ȫ��k = " << ::k << endl;
	return 0;
}