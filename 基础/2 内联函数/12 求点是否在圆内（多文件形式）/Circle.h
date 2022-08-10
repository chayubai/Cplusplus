#pragma once
#include "Point.h"

//‘≤¿‡ 
class Circle
{
public:
	void setXY(int x, int y);
	
	void setR(int r);
	
	bool is_in_Cricle(Point& p);
	
private:
	int x0;
	int y0;
	int m_r;
};
