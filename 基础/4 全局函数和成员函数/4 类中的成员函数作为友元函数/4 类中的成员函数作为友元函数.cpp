#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>

class Building;//����Building��

class GoodGay
{
public:
	GoodGay();
	void visit();//��Ԫ�������Է���building��˽�г�Ա
	void visit2();//����Ԫ���������Է���building��˽�г�Ա
private:
	Building* m_building;//����Building�࣬���������ò���
};

class Building//��Ķ����ں��棬���ǰ����Ҫʹ�ø��࣬��Ҫ��ǰ������
{
	//��GoodGay���е�visit()��Ա������Ϊ��Ԫ����������ʱ����Ҫ��������GoodGay::
	friend void GoodGay::visit();

public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//���¶������⺯����ʵ��
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
void GoodGay::visit2()
{
	cout << "�û������ڷ���" << this->m_building->m_SittingRoom << endl;
	//cout << "�û������ڷ���" << this->m_building->m_BedRoom << endl;
}

void test()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test();
	return 0;
}