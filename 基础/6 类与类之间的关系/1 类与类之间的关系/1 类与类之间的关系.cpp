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
//���ߵ��ھۣ�ÿ�������Ĺ��ܶ�����һ���������ţ���һ��������ʵ�ֵĹ���Խ��һԽ��
//���͵���ϣ���֮��Ĺ�ϵ��Զ������������ţ���������֮�������Խ��Խ��

//��C�ĳ�Ա��������Ҫ��A���βΣ���C uses A,Ҳ����C��������A
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

//���磺�����еĹ��ܶ�����main������ʵ�֣������ڵ��ھ�

//B��A�Ĺ�ϵ��C��A�Ĺ�ϵ��B��A�Ĺ�ϵ������
//��Ϊ����B,һ��Ҫ����A��������C��ֻ�е���C�ķ���void funcC(A* a)ʱ������Ҫ����A
//��ˣ���C����A����϶ȱ���B����A����϶ȵ�

//��D�̳�����A����D is A���̳е���϶�����ߵ�
class D:public A
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