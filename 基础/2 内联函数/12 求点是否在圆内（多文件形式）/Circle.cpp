#include "Circle.h"
#include "Point.h"

//Բ��

void Circle::setXY(int x, int y)
{
	x0 = x;
	y0 = y;
}
void Circle::setR(int r)
{
	m_r = r;
}
bool Circle::is_in_Cricle(Point& p)
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
