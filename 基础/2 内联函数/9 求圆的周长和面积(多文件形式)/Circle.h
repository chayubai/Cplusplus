#pragma once
 
#if 0

#ifndef __CIRCLE_H_

#define __CIRCLE_H_

#endif // !__CIRCLE_H_

#endif

//头文件包含
#include <iostream>
using namespace std;
//类声明
class Circle
{
public:
	void setR(double r);
	
	double getR();
	
	//圆的周长
	double getGirth();
	
	//圆的面积
	double getArea();

private:
	double m_r;
	double m_girth;
	double m_area;
};