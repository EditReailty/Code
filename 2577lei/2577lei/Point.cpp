#include"Point.h"

void Point::setX(int x) {
	m_x = x; // 设置X坐标
}
void Point::setY(int y) {
	m_y = y; // 设置Y坐标
}
int Point::getX() const {
	return m_x; // 获取X坐标
}
int Point::getY() const {
	return m_y; // 获取Y坐标
}
