#define _CRT_SECURE_NO_WARNINGS 1
//1����������Ĭ�ϲ�������������

//2��int func(int a,int b)��void func(int a, int b, int c)�����غ���ô��Ϊʲô��

//3�����º�������д���Ƿ���ȷ��Ϊʲô��
//int func(int a, int b)��int func(int a,int b,int c = 0);

//4��������������������̵�����

//5������һ��Point�࣬�����԰���������꣬�ṩ��������֮�����ķ���
//����һ��Բ�࣬�����԰���Բ�ĺͰ뾶
//��������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ����������

#include <iostream>
#include <cmath>//����include <math.h>
using namespace std;

//����
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	//�����������
	double pointDistance(Point& another)
	{
		//ͬ��֮����˽��
		int d_x = m_x - another.m_x;
		int d_y = m_y - another.m_y;

		double dis = sqrt(d_x * d_x + d_y * d_y);
		return dis;
	}
private:
	int m_x;
	int m_y;
};

//Բ��
class Circle
{
public:
	void setXY(int x, int y)
	{
		p0.setXY(x, y);
	}
	void setR(int r)
	{
		m_r = r;
	}
	//�ж�Բ�Ƿ��ཻ
	bool isIntersection(Circle &another)
	{
		//���뾶֮��
		int rr = m_r + another.m_r;
		//��Բ��֮��ľ���
		double dis = p0.pointDistance(another.p0);

		if (dis <= rr )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int m_r;
	Point p0;
};

int main()
{
	Circle c1,c2;
	int x, y, r;
	cout << "�������һ��Բ�İ뾶r" << endl;
	cin >> r;
	c1.setR(r);
	cout << "�������һ��Բ��x����" << endl;
	cin >> x;
	cout << "�������һ��Բ��y����" << endl;
	cin >> y;
	c1.setXY(x, y);

	cout << "������ڶ���Բ�İ뾶r" << endl;
	cin >> r;
	c2.setR(r);
	cout << "������ڶ���Բ��x����" << endl;
	cin >> x;
	cout << "������ڶ���Բ��y����" << endl;
	cin >> y;
	c2.setXY(x, y);

	if (c1.isIntersection(c2) == true)
	{
		cout << "�ཻ" << endl;
	}
	else
	{
		cout << "���ཻ" << endl;
	}

	return 0;
}

//6����Ʋ�����һ����ΪRect�ľ����࣬������Ϊ���ε����½������½�����������ꡣ���������ܼ�������ε����

//7������һ��Tree�࣬�г�Աages�����䣩����Ա����grow(int years)��ages����years��age()��ʾtree�����agesֵ��