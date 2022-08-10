#define _CRT_SECURE_NO_WARNINGS 1
 
//���һ��Բ���ࣨAdvCircle��,��һ�����ࣨPoint�����������Բ�ڲ�����Բ�⣬������Բ�Ĺ�ϵ
#include <iostream>
using namespace std;

//����һ��
#if 0
//����
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;//��ĺ�����
	int m_y;//���������
};

//Բ��
class Circle
{
public:
	void setXY(int x, int y)
	{
		x0 = x;
		y0 = y;
	}
	void setR(int r)
	{
		m_r = r;
	}
	bool is_in_Cricle(Point& p)
	{
		int dd;
		//����ľ����ƽ��
		dd = (p.getX() - x0) * (p.getX() - x0) + (p.getY() - y0) * (p.getY() - y0);
		if (dd > m_r * m_r)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	int x0;//Բ�ĵĺ�����
	int y0;//Բ�ĵ�������
	int m_r;//Բ�İ뾶
};

int main()
{
	Circle c;
	c.setXY(2, 2);
	c.setR(4);

	Point p;
	p.setXY(8,8);

	if (c.is_in_Cricle(p) == true)
	{
		cout << "Բ��" << endl;
	}
	else
	{
		cout << "Բ��" << endl;
	}
	return 0;
}
#endif

//��������
//����
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

//Բ��
class Circle
{
public:
	void setR(int r)
	{
		m_r = r;
	}
	int getR()
	{
		return m_r;
	}
	void setCenter(Point c)
	{
		m_center = c;//�Զ�����֮���ǿ���ֱ�Ӹ�ֵ��
	}
	Point getCenter()
	{
		return m_center;
	}
	//�ֲ�����
	void is_in_Cricle(Point p)
	{
		int distance;
		//����ľ����ƽ��
		distance = (m_center.getX() - p.getX()) * (m_center.getX() - p.getX()) +
			(m_center.getY() - p.getY()) * (m_center.getY() - p.getY());
		int rDistance = m_r * m_r;
		if (distance > rDistance)
		{
			cout << "����Բ��" << endl;
		}
		else if (distance < rDistance)
		{
			cout << "����Բ��" << endl;
		}
		else
		{
			cout << "����Բ��" << endl;
		}
	}
private:
	int m_r;//�뾶
	Point m_center;//Բ��
};
//ȫ�ֺ���
void is_in_Cricle(Circle c, Point p)
{
	int distance;
	//����ľ����ƽ��
	distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if(distance < rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	Point p;//��
	p.setXY(10, 10);

	Point pCenter;//Բ��
	pCenter.setXY(0, 10);

	Circle c;//Բ
	c.setR(10);
	c.setCenter(pCenter);
	is_in_Cricle(c, p);

	c.is_in_Cricle(p);
	return 0;
}