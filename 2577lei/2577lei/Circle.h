#pragma once
#include"Point.h"

class Circle
{
private:
	Point m_center; // 圆心
	int m_radius;   // 半径
public:
	void setCenter(int x, int y);// 设置圆心坐标
	void setRadius(int radius); // 设置半径
	
	void isPointInCircle(Point& p);
	
};

