#pragma once
 
#if 0

#ifndef __CIRCLE_H_

#define __CIRCLE_H_

#endif // !__CIRCLE_H_

#endif

//ͷ�ļ�����
#include <iostream>
using namespace std;
//������
class Circle
{
public:
	void setR(double r);
	
	double getR();
	
	//Բ���ܳ�
	double getGirth();
	
	//Բ�����
	double getArea();

private:
	double m_r;
	double m_girth;
	double m_area;
};