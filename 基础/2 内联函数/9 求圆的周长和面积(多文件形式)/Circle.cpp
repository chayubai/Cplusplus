#include "Circle.h"
 
//ע�⣺��Ҫ���������������࣬������һ��ȫ�ֺ���
void Circle::setR(double r)
{
	m_r = r;
}
double Circle::getR()
{
	return m_r;
}
//Բ���ܳ�
double Circle::getGirth()
{
	m_girth = m_r * 3.14 * 2;
	return m_girth;
}
//Բ�����
double Circle::getArea()
{
	m_area = m_r * m_r * 3.14;
	return m_area;
}