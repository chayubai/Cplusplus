#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
 
//��Ԫ��������ȫ�ֺ�����ĳ����ĳ�Ա�����������ࡣ���ǻ��ƻ���ķ�װ����
//��һ��ȫ�ֺ�������Ա�����������࣬���Գ�Ϊһ����ĺ����ѣ��Ӷ�����ֱ�ӷ���˽������
//������Ҫʹ��get��set����

class Building
{
	//����friend�ؼ�����ȫ�ֺ�����goodGay��Ϊ��������ѣ����Է���˽�г�Ա
	friend void goodGay(Building* building);
public:
	
	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}

public:
	string m_SittingRoom;//����
private:
	string m_BedRoom;//����
};

//�û���ȫ�ֺ��������Է���Building��˽������
void goodGay(Building *building)
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

int main()
{
	Building building;//ջ�Ͽ��ٻ��߶��Ͽ���Building * building = new Building;
	goodGay(&building);
	return 0;
}

#if 0
#include <cmath>

class Point;//����Point�࣬���ں�������ǰ�õ�����

class PointManager//����PointManager���PointDistance���������ں���Ҫ��ǰ�õ�����
{
public:
	double PointDistance(Point& p1, Point& p2);//����Point�࣬���������ò���
};

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	//�ڶ���
	//��Ԫ�������������ⲿ��ȫ�ֺ������Է�����ģ�˽�У���Ա
	//friend double PointDistance(Point& p1, Point& p2);//friend�����ⲿȫ�ֺ���Ϊ�����Ԫ����

	//�����֣�����ָ����ĳ�Ա����Ϊ��Ԫ��������������
	friend double PointManager::PointDistance(Point& p1, Point& p2);//����PointManager���PointDistance���������������ò���
private:
	int x;
	int y;
};

#if 0
//��һ��
//ȫ�ֱ���������get��������˽�г�Ա
double PointDistance(Point& p1, Point& p2)//�������ʹ�øú���������getX()��getY()Ƶ����ѹջ�ͳ�ջ����
{
	double dis;
	int dd_x = p1.getX() - p2.getX();
	int dd_y = p1.getY() - p2.getY();
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}
#endif

#if 0
//�ڶ���
//ȫ�ֱ�����Ϊ��Ԫ����
double PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}
#endif

//������
//PointManager��ĳ�Ա������Ϊ��Ԫ���� - ������ʵ�֣����ܷ�������ʵ�֣�������Ҫ�õ�x��y
double PointManager::PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;
	dis = sqrt(dd_x * dd_x + dd_y * dd_y);
	return dis;
}

int main()
{
	Point p1(1, 2);
	Point p2(2, 2);
	//��һ�֡��ڶ���
	//cout << "PointDistance(p1,p2)��" << PointDistance(p1, p2) << endl;

	PointManager pm;
	cout << "PointDistance(p1,p2)��" << pm.PointDistance(p1, p2) << endl;
	return 0;
}
#endif

//ע�⣺��Ԫ������������ʵ�֣��൱��ȫ�ֺ���