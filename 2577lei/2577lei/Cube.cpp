#include"Cube.h"
#include<iostream>

void Cube::setLength(int length)
{
	m_length = length;
}

void Cube::setWidth(int width)
{
	m_width = width;
}

void Cube::setHeight(int height)
{
	m_height = height;
}

int Cube::getLength() const
{
	return m_length;
}

int Cube::getWidth() const
{
	return m_width;
}

int Cube::getHeight() const
{
	return m_height;
}

int Cube::getVolume() const
{
	return m_height * m_length * m_width;
}
int Cube::getArea() const
{
	return (m_length * m_height + m_height * m_width + m_length * m_width) * 2;
}
bool Cube::cubcompare(Cube& c)
{
	if (m_length == c.getLength() &&
		m_width == c.getWidth() &&
		m_height == c.getHeight())
	{
		return true; // The cubes are equal
	}
	else
	{
		return false; // The cubes are not equal
	}
}	