#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
#include <string>
class Building;//����Building��,��ֹ������ǰʹ�ñ���

class GoodGay
{
public:
	GoodGay();
	void visit();
private:
	Building* m_building;//����Building�࣬���������ò���
};

class Building
{
	//��goodGay����ΪBuilding�ĺ����ѣ����Է���˽�г�Ա
	friend class GoodGay;
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}
GoodGay::GoodGay()
{
	this->m_building = new Building;
}

void GoodGay::visit()
{
	cout << "�û������ڷ���" << this->m_building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << this->m_building->m_BedRoom << endl;
}
void test()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test();
	return 0;
}

#if 0

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	void printA()
	{
		B objB(100);
		cout << "objB.b" << objB.b << endl;//������B��˽�г�Ա������A����B��������Ԫ��
		cout << "a = " << this->a << endl;
	}

	//ע�⣺
	// (1)��Ԫ��ϵ���ܱ��̳С�
	// (2)������Ԫ��,��Ԫ�������ǵ���ģ���A��������������Ԫ��B����B�����ʹ��A���˽�г�Ա����A�಻��ʹ��B���˽�г�Ա
	// (3)��Ԫ��ϵ�����д����ԡ�����B����A����Ԫ��C��B����Ԫ,��C��һ������A����Ԫ,ͬ��Ҫ�������Ƿ�����Ӧ��������
	friend class B;
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		this->b= b;
	}
	void printB()
	{
		A objA(100);
		cout << "objA.a" << objA.a << endl;//������A��˽�г�Ա������B����A��������Ԫ��
		cout << "b = " << this->b << endl;
	}
	friend class A;
private:
	int b;
};
int main()
{
	B b(200);
	b.printB();
	return 0;
}
#endif
