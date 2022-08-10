#define _CRT_SECURE_NO_WARNINGS 1
 
#include "Circle.h"

int main()
{
	Circle c;
	c.setR(10);
	cout << "圆的半径是：" << c.getR() << endl;//10
	cout << "圆的周长是：" << c.getGirth() << endl << "圆的面积是：" << c.getArea() << endl;//随机值 随机值
	return 0;
}
