#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	void funcA()
	{
		cout << "funcA()" << endl;
	}
	int a;
};
//��Bӵ����A�ĳ�Ա��������B has A��Ҳ����B��������A
class B
{
public:
	void funcB()
	{
		cout << "funcB()" << endl;
	}
	A a;
};
//�ھ۶ȡ���϶ȣ����ھۡ������
//���ھۣ�ÿ�������Ĺ��ܶ�����һ����������
//����ϣ���֮��Ĺ�ϵ��Զ������������ţ�������C����϶Ƚϵ�

//��C�ĳ�Ա��������Ҫ��A���βΣ���C uses A��Ҳ����B��������A
class C
{
public:
	void funcC(A* a)
	{
		cout << "funcC()" << endl;
	}
	void funcC2()
	{

	}
};

//��D�̳�����A����D is A���̳е���϶�����ߵ�
class C:public A
{
public:
	void funcD(A* a)
	{
		cout << "funcD() a = " << a << endl;
	}

};
int main()
{
	return 0;
}