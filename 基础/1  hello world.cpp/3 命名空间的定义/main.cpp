#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
#include "game2.h"

//1�������ռ���;�����Խ�����Ƴ�ͻ����
void test1()
{
	//���������ռ��µĺ�������
	KingGlory::Attack();
	LOL::Attack();
}

//2�������ռ��¿��Էţ����������������������ṹ�塢��...
namespace A
{
	//�����ռ�ġ�}������д";"
	int m_A;
	void func();
	struct Person {};
	class Animal {};
}

//3�������ռ����Ҫ������ȫ����������
void test2()
{
	//namespace B {}�������������ֲ�������������
}

//4�������ռ����Ƕ�������ռ�
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}
void test3()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "C�ռ��µ�m_A = " << B::C::m_A << endl;
}

//5�������ռ��ǿ��ŵģ�������ʱ�������ռ�����µĳ�Ա
namespace B//�������ռ�������������ռ�B���кϲ�
{
	int m_B = 100;
}
void test4()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "B�ռ��µ�m_B = " << B::m_B << endl;
}

//6�������ռ��ǿ���������
namespace 
{
	//��д�������ռ��������ģ��൱��д��static int m_C = 1000;static int m_D = 2000;
	//��̬����ֻ���ڵ�ǰ�ļ���ʹ��
	int m_C = 1000;
	int m_D = 2000;
}
void test5()
{
	//������ȫ���������¶���������ռ䣬���������ı���������ֱ�ӷ���
	cout << "m_C = " << m_C << endl;
	//::�������������ǰ��ʲô����д����ʾȫ��������
	cout << "m_D = " << ::m_D << endl;
}

//7�������ռ����ȡ����
namespace veryLongName
{
	int m_E = 10000;
}
void test6()
{
	cout << veryLongName::m_E << endl;
	namespace vLN = veryLongName;
	cout << vLN::m_E << endl;
}
int main()
{
	//test1();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}