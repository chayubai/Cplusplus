#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Parent
{
public:
	int a;
	void printP()
	{

	}
};
class Child:public Parent
{
public:
	int b;
	void printC()
	{

	}
};

void myprint(Parent* pp)
{
	pp->printP();
}
//���������Ե����������ʹ��
//����������ֱ�Ӹ�ֵ���������
//����������ֱ�ӳ�ʼ���������
//����ָ�����ֱ��ָ���������
//�������ÿ���ֱ�������������

int main()
{
#if 0
	Parent p;
	Child c;
	//c = p;
	p = c;//c������ռ�õ��ڴ�ռ� >= p����ռ�õĿռ䣬�ܹ����p��������Ҫ�Ŀռ�

	c.printP();//c�ܹ���������p��ʹ��
#endif
#if 0
	Parent* pp = NULL;//����ָ��
	Child* cp = NULL;//����ָ��

	Parent p;//�������
	Child c;//�������

	pp = &c;//pp->b��c�ڴ沼���ܹ����㸸��ָ���ȫ�����󣬿�����һ�����ӵĶ����ַ������ָ�븳ֵ
	//cp = &p;//cp->b;
#endif
	Parent p;//�������
	Child c;//�������
	myprint(&p);
	myprint(&c);
	return 0;
}