#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
class Building;//����Building��

class GoodGay
{
public:
	GoodGay();
	void visit();
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
		cout << "objB.b" << objB.b << endl;
		cout << "a = " << this->a << endl;
	}
	//������Ԫ��,��Ԫ�������ǵ���ģ���A��������������Ԫ��B����B�����ʹ��A�࣬��A�಻��ʹ��B��
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
		cout << "objA.a" << objA.a << endl;
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