#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��̬ת��
//������������������ת������Ϊ����ת�����ȶ�ʧ�Ȳ���ȫ
//������֮��ָ������á���Ҫ�������μ������ת��������ת��
//1�������μ��������ת��ʱ����̬����ת���;�̬����ת����Ч����һ����
//2���ڽ�������ת��ʱ����̬����ת���������ͼ��Ĺ��ܣ��Ⱦ�̬����ת������ȫ
//3������в���ȫ��ת�������޷���̬����ת���ģ�����������ת����
//4�����������̬�����ǰ�ȫ�����Գɹ�

//��̬����ת�����ؼ���dynamic_cast
void test1()
{
	//������������������֮��ת��
	char a = 'a';
	//double d = dynamic_cast<double>(a);//����
}

//class Base {};
//class Son :public Base {};

//����͸��෢����̬
class Base { virtual void func() {} };
class Son :public Base { virtual void func() {} };
class Other {};

void test2()
{
	Base* base = NULL;
	Son* son = NULL;

	//�﷨�� dynamic_cast<Ŀ������>(ԭ����/����)
	//��baseתΪSon* ��ת�� ��������ת��������ȫ
	//Son* s = dynamic_cast<Son*>(base);//�������������������̬������

	//��sonתΪBase* ��ת�� ��������ת���� ��ȫ
	Base* b = dynamic_cast<Base*>(son);

	//��baseתΪOther*
	//Other* o = dynamic_cast<Other*>(base);//�����޷�ת��

}

void test3()
{
	//Base* base = NULL;
	//Son* son = NULL;
	//��baseתΪSon* ��ת�� ��������ת��������ȫ
	//Son* s = dynamic_cast<Son*>(base);//���������������̬������

	//��η�����̬�� - �麯����������д�����麯��������ָ��/����ָ���������
	Base* base = new Son;//����ָ��ָ���������
	//��baseתΪSon* ���������̬��ת�����ǰ�ȫ��
	Son* s = dynamic_cast<Son*>(base);//��Ϊnew��ʱ��������Ŀռ�
}

void test4()
{
	Base base;
	Son son;
	Base& bs = base;
	Son& sn = son;

	//��bsתΪSon&  ��ת�� ��������ת��������ȫ
	Son& s = dynamic_cast<Son&>(bs);

	//��snתΪBase& ��ת�� ��������ת���� ��ȫ
	Base& b = dynamic_cast<Base&>(sn);

	//��bsתΪOther&
	//Other& o = dynamic_cast<Other&>(bs);//����ת����Ч

	//static_cast�Ǹ���֮���ָ��������ÿ���ת��
}

int main()
{
	test1();
	return 0;
}