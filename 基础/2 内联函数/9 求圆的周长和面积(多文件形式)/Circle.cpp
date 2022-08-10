#include "Circle.h"
 
//注意：需要声明函数所属的类，否则是一个全局函数
void Circle::setR(double r)
{
	m_r = r;
}
double Circle::getR()
{
	return m_r;
}
//圆的周长
double Circle::getGirth()
{
	m_girth = m_r * 3.14 * 2;
	return m_girth;
}
//圆的面积
double Circle::getArea()
{
	m_area = m_r * m_r * 3.14;
	return m_area;
}