#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����ת����ָ�룬���ã�����ָ��
//������������޸����͵�const����
//1������ָ��ת���ǳ���ָ�룬������Ȼָ��ԭ���Ķ���
//2����������ת���ǳ������ã�������Ȼָ��ԭ���Ķ���
//3��������ֱ�ӶԷ�ָ��ͷ����õı���ʹ�ó���������const_castȥֱ���Ƴ�����const

//����ת�����ؼ���const_cast
void test1()
{
	//����ָ��ת���ɷǳ���ָ��
	const int* p = NULL;
	int* np = const_cast<int*>(p);
}

void test2()
{
	//�ǳ���ָ��ת���ɳ���ָ��
	int* pp = NULL;
	const int* npp = const_cast<const int*>(pp);
}

void test3()
{
	const int a = 10;
	//int b = const_cast<int>(a);//�������ܶԷ�ָ������ý���ת��
}

void test4()
{
	//��������ת���ɷǳ�������
	int a = 10;
	const int& b = a;
	//b = 20;//�����޸�
	int& c = const_cast<int&>(b);

	//�ǳ�������ת���ɳ�������
	int num = 10;
	int& reNum = num;
	const int& reNum2 = const_cast<const int&>(reNum);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
}

//���½���ת�����ؼ���reinterpret_cast
//���½���ת����һ�����ȫ��ת����������ʹ��
//ǿ������ת�����κ�����ֵ��ָ�룩������ת��Ϊ��������

class Base{};
class Other {};
void test5()
{
	int a = 10;
	int* p = reinterpret_cast<int*>(a);

	//��baseת��ΪOther*��Base��Other������֮��Ľṹ���ܲ�ͬȴ����ת������˲���ȫ
	Base* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}
typedef void(FP1)(int, int);
typedef void(FP2)(int, char*);
void test6()
{
	//���⺯��ָ��֮��ת��
	FP1* func1 = NULL;
	FP2* func2 = reinterpret_cast<FP2*>(func1);

}
int main()
{
	test1();
	return 0;
}