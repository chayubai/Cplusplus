#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace KingGlory
{
	int sunwukongId = 1;
}
namespace LOL
{
	int sunwukongId = 10;
}
void test1()
{
	//�ֲ���������
	//int sunwukongId = 2;
	
	//1��using������˵���Ժ󿴵�sunwukongId����KingGlory�µ�
	using KingGlory::sunwukongId;//�������Ϊ������ռ䣬��ʹ��sunwukongId
	//ֱ�Ӹ��߱�����ʹ��KingGlory�ռ��µ�sunwukongId
	cout << sunwukongId << endl;
	//��using������ֲ���������ͬʱ���־ͻ������ʱ�������������
}

void test2()
{
	//�ֲ���������
	int sunwukongId = 3;
	//2��using����ָ��
	using namespace KingGlory;//���Ϊ������ռ䣬��ʱû��ʹ��
	//ֻ���߱�������KingGlory�ռ䣬�������ʹ�õı�������ռ�����Ͳ��ᱨ��
	
	//��using����ָ����ֲ���������ͬʱ���֣��ֲ���������ʹ��
	cout << sunwukongId << endl;
}

void test3()
{
	using namespace KingGlory;//���Ϊ������ռ䣬��ʱû��ʹ��

	using namespace LOL;//���Ϊ������ռ䣬��ʱû��ʹ��
	//cout << sunwukongId << endl;//������

	//��using����ָ���ж����û�оֲ���������ʱ�����������������Ҫ������������
	cout << KingGlory::sunwukongId << endl;
	cout << LOL::sunwukongId << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}