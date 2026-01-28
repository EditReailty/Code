#pragma once

class Cube {
private:
	int m_length; // Length of the cube
	int m_width;  // Width of the cube
	int m_height; // Height of the cube

public:
	void setLength(int length);
	void setWidth(int width);
	void setHeight(int height);
	int getLength() const;
	int getWidth() const;
	int getHeight() const;

	int getVolume() const; // Calculate the volume of the cube
	int getArea() const; // Calculate the surface area of the cube
	bool cubcompare(Cube& c);
	
};