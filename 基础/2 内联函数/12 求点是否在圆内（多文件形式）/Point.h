#pragma once
#include <iostream>
using namespace std;

//����
class Point
{
public:
	void setXY(int x, int y);
	int getX();
	int getY();
private:
	int m_x;
	int m_y;
};


