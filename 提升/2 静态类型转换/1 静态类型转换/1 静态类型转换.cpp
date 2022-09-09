#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��̬ת��
//���������������͵�ת��
//�������νṹ�л��ࣨ���ࣩ�������ࣨ���ࣩ֮��ָ������õ�ת��
//1������ת�� - ��ת���ǰ�ȫ�ġ�
//2������ת�� - ѰַС��תѰַ��ģ��ǲ���ȫ�ġ�

//��̬����ת�����ؼ���static_cast
void test1()
{
	//����������������֮��ת��
	char a = 'a';
	double d = static_cast<double>(a);

	cout << d << endl;
}

class Base {};
class Son :public Base{};
class Other{};

void test2()
{
	Base* base = NULL;
	Son* son = NULL;

	//��֧�ֻ�����������ָ��ֱ�ӵ�ת��
	//int* p = NULL;
	//char* sp = static_cast<char*>(p);//����

	//�﷨�� static_cast<Ŀ������>(ԭ����/����)
	//��baseתΪSon* ��ת�� ��������ת��������ȫ�������Գɹ�
	Son* s = static_cast<Son*>(base);

	//��sonתΪBase* ��ת�� ��������ת���� ��ȫ
	Base* b = static_cast<Base*>(son);

	//��baseתΪOther*
	//Other* o = static_cast<Other*>(base);//����ת����Ч

	//static_cast�Ǹ���֮���ָ��������ÿ���ת��
}

void test3()
{
	Base base;
	Son son;
	Base& bs = base;
	Son& sn = son;

	//��bsתΪSon&  ��ת�� ��������ת��������ȫ
	Son& s = static_cast<Son&>(bs);

	//��snתΪBase& ��ת�� ��������ת���� ��ȫ
	Base& b = static_cast<Base&>(sn);

	//��bsתΪOther&
	//Other& o = static_cast<Other&>(bs);//ת����Ч

	//static_cast�Ǹ���֮���ָ��������ÿ���ת��
}

int main()
{
	test1();
	return 0;
}