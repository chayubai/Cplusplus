#define _CRT_SECURE_NO_WARNINGS 1

#include "Point.h"
#include "Circle.h"

int main()
{
	Circle c;
	c.setXY(2, 2);
	c.setR(4);

	Point p;
	p.setXY(8, 8);

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