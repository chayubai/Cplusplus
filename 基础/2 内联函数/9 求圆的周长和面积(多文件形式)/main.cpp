#define _CRT_SECURE_NO_WARNINGS 1
 
#include "Circle.h"

int main()
{
	Circle c;
	c.setR(10);
	cout << "Բ�İ뾶�ǣ�" << c.getR() << endl;//10
	cout << "Բ���ܳ��ǣ�" << c.getGirth() << endl << "Բ������ǣ�" << c.getArea() << endl;//���ֵ ���ֵ
	return 0;
}
