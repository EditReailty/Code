#include "Circle.h"
#include <iostream>

void Circle::setCenter(int x, int y) {
	m_center.setX(x); // 设置圆心的X坐标
	m_center.setY(y); // 设置圆心的Y坐标
}
void Circle::setRadius(int radius) {
	m_radius = radius; // 设置圆的半径
}

void Circle::isPointInCircle(Point& p)
{
	int x = p.getX(); // 获取点的X坐标
	int y = p.getY(); // 获取点的Y坐标
	int centerX = m_center.getX(); // 获取圆心的X坐标
	int centerY = m_center.getY(); // 获取圆心的Y坐标
	// 计算点到圆心的距离
	int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
	int radiusSquared = m_radius * m_radius; // 半径的平方
	if (distanceSquared <= radiusSquared) {
		std::cout << "点在圆内或在圆上" << std::endl; // 点在圆内或在圆上
	}
	else {
		std::cout << "点在圆外" << std::endl; // 点在圆外
	}	
}
